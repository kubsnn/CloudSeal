using CloudSealCore.Crypto.Block;
using System;
using System.Buffers;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CloudSealCore.Crypto;

public sealed class AsyncEncryptingReadStream : Stream
{
    private const int ChunkSize = 256 * 1024;

    private readonly Stream _source;
    private readonly ICryptoEngine _cryptoEngine;
    private readonly IProgress<long>? _progress;

    private byte[] _currentEncrypted = Array.Empty<byte>();
    private int _encryptedOffset = 0;

    private Task<byte[]?>? _nextChunkTask;
    private bool _eof = false;
    private long _totalPlaintextRead = 0;

    public AsyncEncryptingReadStream(Stream source, ICryptoEngine cryptoEngine, IProgress<long>? progress = null)
    {
        _source = source ?? throw new ArgumentNullException(nameof(source));
        _cryptoEngine = cryptoEngine ?? throw new ArgumentNullException(nameof(cryptoEngine));
        _progress = progress;
    }

    public override async ValueTask<int> ReadAsync(Memory<byte> buffer, CancellationToken cancellationToken = default)
    {
        int totalRead = 0;

        while (buffer.Length > 0)
        {
            if (_encryptedOffset >= _currentEncrypted.Length)
            {
                if (!await ReadAndEncryptNextChunkAsync(cancellationToken))
                    break;
            }

            int toCopy = Math.Min(buffer.Length, _currentEncrypted.Length - _encryptedOffset);
            _currentEncrypted.AsMemory(_encryptedOffset, toCopy).CopyTo(buffer);
            _encryptedOffset += toCopy;
            buffer = buffer[toCopy..];
            totalRead += toCopy;
        }

        return totalRead;
    }

    private async Task<bool> ReadAndEncryptNextChunkAsync(CancellationToken ct)
    {
        byte[]? plain;

        if (_nextChunkTask == null)
        {
            _nextChunkTask = ReadChunkAsync(ct);
        }

        plain = await _nextChunkTask;
        if (plain == null)
        {
            _eof = true;
            return false;
        }

        _totalPlaintextRead += plain.Length;
        _progress?.Report(_totalPlaintextRead);

        _nextChunkTask = ReadChunkAsync(ct);

        _currentEncrypted = _cryptoEngine.Encrypt(plain);
        _encryptedOffset = 0;
        return true;
    }

    private async Task<byte[]?> ReadChunkAsync(CancellationToken ct)
    {
        byte[] buffer = ArrayPool<byte>.Shared.Rent(ChunkSize);
        int read = await _source.ReadAsync(buffer.AsMemory(0, ChunkSize), ct);

        if (read == 0)
        {
            ArrayPool<byte>.Shared.Return(buffer);
            return null;
        }

        byte[] result = new byte[read];
        Buffer.BlockCopy(buffer, 0, result, 0, read);
        ArrayPool<byte>.Shared.Return(buffer);
        return result;
    }

    public override int Read(byte[] buffer, int offset, int count)
        => ReadAsync(buffer.AsMemory(offset, count)).AsTask().Result;

    public override bool CanRead => true;
    public override bool CanSeek => false;
    public override bool CanWrite => false;

    public override long Length => throw new NotSupportedException();
    public override long Position
    {
        get => throw new NotSupportedException();
        set => throw new NotSupportedException();
    }

    public override void Flush() { }

    public override long Seek(long offset, SeekOrigin origin)
        => throw new NotSupportedException();

    public override void SetLength(long value)
        => throw new NotSupportedException();

    public override void Write(byte[] buffer, int offset, int count)
        => throw new NotSupportedException();

    protected override void Dispose(bool disposing)
    {
        if (disposing)
        {
            _source.Dispose();
        }
        base.Dispose(disposing);
    }

    public override async ValueTask DisposeAsync()
    {
        await _source.DisposeAsync();
        await base.DisposeAsync();
    }
}