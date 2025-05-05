using System.Buffers;
using CloudSealCore.Crypto.Block;

namespace CloudSealCore.Crypto;

public sealed class AsyncDecryptingReadStream : Stream
{
    private const int HeaderSize = 4;
    private const int IvSize = 12;
    private const int TagSize = 16;

    private readonly Stream _input;
    private readonly ICryptoEngine _decryptor;
    private readonly IProgress<long>? _progress;

    private byte[] _currentPlain = Array.Empty<byte>();
    private int _plainOffset = 0;
    private long _totalDecrypted = 0;

    public AsyncDecryptingReadStream(Stream input, ICryptoEngine decryptor, IProgress<long>? progress = null)
    {
        _input = input;
        _decryptor = decryptor;
        _progress = progress;
    }

    public override async ValueTask<int> ReadAsync(Memory<byte> buffer, CancellationToken cancellationToken = default)
    {
        int totalRead = 0;

        while (buffer.Length > 0)
        {
            if (_plainOffset >= _currentPlain.Length)
            {
                if (!await ReadAndDecryptNextChunkAsync(cancellationToken))
                    break;
            }

            int toCopy = Math.Min(buffer.Length, _currentPlain.Length - _plainOffset);
            _currentPlain.AsMemory(_plainOffset, toCopy).CopyTo(buffer);
            buffer = buffer[toCopy..];
            _plainOffset += toCopy;
            totalRead += toCopy;
        }

        _totalDecrypted += totalRead;
        _progress?.Report(_totalDecrypted);

        return totalRead;
    }

    private async Task<bool> ReadAndDecryptNextChunkAsync(CancellationToken ct)
    {
        byte[] lenBuf = new byte[4];
        if (!await ReadExactAsync(_input, lenBuf, ct))
            return false;

        if (!BitConverter.IsLittleEndian)
            Array.Reverse(lenBuf);

        int chunkLen = BitConverter.ToInt32(lenBuf, 0);
        byte[] chunk = new byte[chunkLen];

        if (!await ReadExactAsync(_input, chunk, ct))
            throw new InvalidDataException("Oczekiwano danych, ale stream się zakończył.");

        _currentPlain = _decryptor.Decrypt(chunk);
        _plainOffset = 0;
        return true;
    }

    private static async Task<bool> ReadExactAsync(Stream stream, byte[] buffer, CancellationToken ct)
    {
        int offset = 0;
        while (offset < buffer.Length)
        {
            int read = await stream.ReadAsync(buffer.AsMemory(offset), ct);
            if (read == 0)
                return false;

            offset += read;
        }
        return true;
    }

    public override bool CanRead => true;
    public override bool CanSeek => false;
    public override bool CanWrite => false;
    public override long Length => throw new NotSupportedException();
    public override long Position { get => throw new NotSupportedException(); set => throw new NotSupportedException(); }

    public override void Flush() { }

    public override int Read(byte[] buffer, int offset, int count)
        => ReadAsync(buffer.AsMemory(offset, count)).AsTask().Result;

    protected override void Dispose(bool disposing)
    {
        _input.Dispose();
        base.Dispose(disposing);
    }

    public override async ValueTask DisposeAsync()
    {
        await _input.DisposeAsync();
        await base.DisposeAsync();
    }

    public override void SetLength(long value) => throw new NotSupportedException();
    public override long Seek(long offset, SeekOrigin origin) => throw new NotSupportedException();
    public override void Write(byte[] buffer, int offset, int count) => throw new NotSupportedException();
}
