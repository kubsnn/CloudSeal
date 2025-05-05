using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace CloudSealCore.Crypto.Block;

internal sealed class GcmEncryptor : IDisposable, IAsyncDisposable
{
    private const int IvSize = 12;
    private const int TagSize = 16;

    private readonly AesGcm _aes;

    public GcmEncryptor(byte[] key)
    {
        if (key.Length != 32)
            throw new ArgumentException("Key must be 32 bytes for AES-256-GCM");

        _aes = new AesGcm(key, TagSize);
    }

    public byte[] Encrypt(ReadOnlySpan<byte> plaintext)
    {
        var iv = RandomNumberGenerator.GetBytes(IvSize);      // 12 bajtów
        var tag = new byte[TagSize];                          // 16 bajtów
        var cipher = new byte[plaintext.Length];

        _aes.Encrypt(iv, plaintext, cipher, tag);

        var totalChunkLen = iv.Length + tag.Length + cipher.Length;
        var lenBytes = BitConverter.GetBytes(totalChunkLen);
        if (!BitConverter.IsLittleEndian)
            Array.Reverse(lenBytes);

        using var ms = new MemoryStream();
        ms.Write(lenBytes);         // 4 bajty długości CAŁEGO chunku
        ms.Write(iv);
        ms.Write(tag);
        ms.Write(cipher);
        return ms.ToArray();
    }


    public void Dispose()
    {
        _aes.Dispose();
        GC.SuppressFinalize(this);
    }

    public ValueTask DisposeAsync()
    {
        Dispose();
        return ValueTask.CompletedTask;
    }
}
