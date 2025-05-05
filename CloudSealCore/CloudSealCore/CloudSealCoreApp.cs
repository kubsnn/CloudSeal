using CloudSealCore.Cloud.Balancer;
using CloudSealCore.Cloud.Dropbox;
using CloudSealCore.Cloud.GoogleDrive;
using CloudSealCore.Cloud.OneDrive;
using CloudSealCore.Cloud;
using CloudSealCore.Crypto;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CloudSealCore.Security;

namespace CloudSealCore;

public sealed class CloudSealCoreApp
{
    private readonly CloudProviderManager _manager;
    private readonly ICloudBalancer _balancer;

    ICryptoEngine? _cryptoEngine = null;

    public bool CryptoEngineInitialized => _cryptoEngine is not null;

    public CloudSealCoreApp(IProgress<long>? progress = null)
    {
        _manager = new CloudProviderManager();
        _balancer = new SimpleCloudBalancer(_manager);
    }

    public async Task InitAsync(CancellationToken ct = default)
    {
        if (!CryptoEngineInitialized)
            throw new Exception("Crypto engine not initialized.");

        await _manager.AuthenticateAllAsync(ct);
    }

    void SignIn(string password)
    {
        var vault = new KeyVault(Config.KeyFilePath);
        if (!vault.Unlock(password))
        {
            throw new Exception("Failed to unlock key vault.");
        }

        var key = vault.GetUserKey();

        _cryptoEngine = new AesGcmCryptoEngine(key);
    }

    void SignUp(string password)
    {
        var vault = new KeyVault(Config.KeyFilePath);

        vault.CreateNew(password);
        vault.Unlock(password);

        var key = vault.GetUserKey();

        _cryptoEngine = new AesGcmCryptoEngine(key);
    }

    public ICloudBalancer Balancer => _balancer;
    public CloudProviderManager Providers => _manager;
}
