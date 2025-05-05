using CloudSealCore.Crypto.Block;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CloudSealCore.Crypto;

internal sealed class AesGcmCryptoEngine : ICryptoEngine
{
    private readonly GcmEncryptor _encryptor;
    private readonly GcmDecryptor _decryptor;
    public string Name => "AES-GCM-256";
    public AesGcmCryptoEngine(byte[] key)
    {
        if (key.Length != 32)
            throw new ArgumentException("Key must be 32 bytes for AES-256-GCM");
        _encryptor = new GcmEncryptor(key);
        _decryptor = new GcmDecryptor(key);
    }
    public string Description => "AES-GCM-256 encryption engine. Uses AES with Galois/Counter Mode (GCM) for authenticated encryption.";

    public byte[] Encrypt(ReadOnlySpan<byte> plaintext) => _encryptor.Encrypt(plaintext);
    public byte[] Decrypt(ReadOnlySpan<byte> chunk) => _decryptor.Decrypt(chunk);

    public void Dispose()
    {
        _encryptor.Dispose();
        _decryptor.Dispose();
        GC.SuppressFinalize(this);
    }

    public ValueTask DisposeAsync()
    {
        _encryptor.DisposeAsync();
        _decryptor.DisposeAsync();
        GC.SuppressFinalize(this);
        return ValueTask.CompletedTask;
    }

}

