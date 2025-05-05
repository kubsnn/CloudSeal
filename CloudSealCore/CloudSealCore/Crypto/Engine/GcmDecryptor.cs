using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Security.Cryptography;

namespace CloudSealCore.Crypto.Block;

internal sealed class GcmDecryptor : IDisposable, IAsyncDisposable
{
    private const int IvSize = 12;
    private const int TagSize = 16;

    private readonly AesGcm _aes;

    public GcmDecryptor(byte[] key)
    {
        if (key.Length != 32)
            throw new ArgumentException("Key must be 32 bytes for AES-256-GCM");

        _aes = new AesGcm(key, TagSize);
    }

    public byte[] Decrypt(ReadOnlySpan<byte> chunk)
    {
        if (chunk.Length < IvSize + TagSize)
            throw new ArgumentException("Nieprawidłowy blok: zbyt krótki");

        var iv = chunk.Slice(0, IvSize);
        var tag = chunk.Slice(IvSize, TagSize);
        var cipher = chunk.Slice(IvSize + TagSize);

        var plain = new byte[cipher.Length];
        _aes.Decrypt(iv, cipher, tag, plain);
        return plain;
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

