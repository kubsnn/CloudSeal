using System.Security.Cryptography;
using System.Text.Json;

namespace CloudSealCore.Security;

public sealed class KeyVault
{
    private const int SaltSize = 16;
    private const int KeySize = 32;
    private const int Iterations = 10000;

    private readonly string _vaultPath;
    private byte[]? _userKey;

    public KeyVault(string vaultPath)
    {
        _vaultPath = vaultPath;
    }

    public bool Exists => File.Exists(_vaultPath);

    public byte[] GetUserKey()
        => _userKey ?? throw new InvalidOperationException("Vault is locked. Call Unlock() first.");

    public void CreateNew(string password)
    {
        var salt = RandomNumberGenerator.GetBytes(SaltSize);
        var userKey = RandomNumberGenerator.GetBytes(KeySize);

        var passwordKey = DeriveFromPassword(password, salt);
        var encrypted = AesGcmEncrypt(userKey, passwordKey, out var iv, out var tag);

        var payload = new VaultPayload
        {
            Salt = Convert.ToBase64String(salt),
            IV = Convert.ToBase64String(iv),
            Tag = Convert.ToBase64String(tag),
            EncryptedKey = Convert.ToBase64String(encrypted)
        };

        File.WriteAllText(_vaultPath, JsonSerializer.Serialize(payload, new JsonSerializerOptions
        {
            WriteIndented = true
        }));

        _userKey = userKey;
        Array.Clear(userKey, 0, userKey.Length); // optional: zero local copy
    }

    public bool Unlock(string password)
    {
        try
        {
            var payload = JsonSerializer.Deserialize<VaultPayload>(File.ReadAllText(_vaultPath))!;

            var salt = Convert.FromBase64String(payload.Salt);
            var iv = Convert.FromBase64String(payload.IV);
            var tag = Convert.FromBase64String(payload.Tag);
            var encrypted = Convert.FromBase64String(payload.EncryptedKey);

            var passwordKey = DeriveFromPassword(password, salt);
            _userKey = AesGcmDecrypt(encrypted, passwordKey, iv, tag);

            return true;
        } catch
        {
            _userKey = null;
            return false;
        }
    }


    public void Lock()
    {
        if (_userKey != null)
        {
            Array.Clear(_userKey, 0, _userKey.Length);
            _userKey = null;
        }
    }

    private static byte[] DeriveFromPassword(string password, byte[] salt)
    {
        using var derive = new Rfc2898DeriveBytes(password, salt, Iterations, HashAlgorithmName.SHA256);
        return derive.GetBytes(KeySize);
    }

    private static byte[] AesGcmEncrypt(byte[] plain, byte[] key, out byte[] iv, out byte[] tag)
    {
        iv = RandomNumberGenerator.GetBytes(12);
        tag = new byte[16];
        var cipher = new byte[plain.Length];

        using var aes = new AesGcm(key, 16);
        aes.Encrypt(iv, plain, cipher, tag);
        return cipher;
    }

    private static byte[] AesGcmDecrypt(byte[] cipher, byte[] key, byte[] iv, byte[] tag)
    {
        var plain = new byte[cipher.Length];
        using var aes = new AesGcm(key, 16);
        aes.Decrypt(iv, cipher, tag, plain);
        return plain;
    }

    private sealed class VaultPayload
    {
        public string Salt { get; set; } = "";
        public string IV { get; set; } = "";
        public string Tag { get; set; } = "";
        public string EncryptedKey { get; set; } = "";
    }
}
