using CloudSealCore.Cloud;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CloudSealCore.Data;

public static class CloudStatisticsCalculator
{
    public static async Task<CloudStatistics> FromProviderAsync(
        ICloudProvider provider,
        CancellationToken cancellationToken = default)
    {
        var files = await provider.ListFilesAsync(cancellationToken);
        var totalSize = files.Sum(f => f.Size ?? 0);
        var space = await provider.GetSpaceInfoAsync(cancellationToken);

        return new CloudStatistics
        {
            ProviderName = provider.Name,
            FileCount = files.Count,
            TotalSize = totalSize,
            AvailableSpace = space.Available,
            TotalQuota = space.Total
        };
    }
}

