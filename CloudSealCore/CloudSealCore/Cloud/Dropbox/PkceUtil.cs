using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Security.Cryptography;

namespace CloudSealCore.Cloud.Dropbox;

internal static class PkceUtil
{
    internal record PkceCodes(string Verifier, string Challenge, string Method);

    internal static PkceCodes Generate()
    {
        // verifier: 43–128 znaków Base64URL
        var bytes = RandomNumberGenerator.GetBytes(64);
        var verifier = Base64Url(bytes);

        // challenge = SHA256(verifier) → Base64URL
        using var sha = SHA256.Create();
        var hash = sha.ComputeHash(Encoding.ASCII.GetBytes(verifier));
        var challenge = Base64Url(hash);

        return new PkceCodes(verifier, challenge, "S256");
    }

    private static string Base64Url(byte[] data)
        => Convert.ToBase64String(data)
                  .Replace('+', '-')
                  .Replace('/', '_')
                  .TrimEnd('=');
}
