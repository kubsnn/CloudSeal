using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CloudSealCore.Crypto;

public interface ICryptoEngine : IDisposable, IAsyncDisposable
{
    string Name { get; }
    string Description { get; }
    byte[] Encrypt(ReadOnlySpan<byte> plaintext);
    byte[] Decrypt(ReadOnlySpan<byte> chunk);
}
