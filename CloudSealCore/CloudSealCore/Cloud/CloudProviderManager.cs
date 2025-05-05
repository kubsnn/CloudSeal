using CloudSealCore.Cloud.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CloudSealCore.Cloud;

public sealed class CloudProviderManager
{
    private readonly List<ICloudProvider> _providers = new();

    public void Add(ICloudProvider provider) => _providers.Add(provider);

    public IReadOnlyList<ICloudProvider> All => _providers;

    public async Task AuthenticateAllAsync(CancellationToken ct = default)
    {
        foreach (var p in _providers)
            if (!p.IsAuthenticated) await p.AuthenticateAsync(ct);
    }

    public async Task<CloudSpaceInfo> TotalSpaceAsync(CancellationToken ct = default)
    {
        long total = 0, free = 0;
        foreach (var p in _providers)
        {
            var s = await p.GetSpaceInfoAsync(ct);
            total += s.Total;
            free += s.Available;
        }

        return new CloudSpaceInfo(free, total);
    }
}
