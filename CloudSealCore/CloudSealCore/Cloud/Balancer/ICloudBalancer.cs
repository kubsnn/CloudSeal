using CloudSealCore.Cloud.Models;

namespace CloudSealCore.Cloud.Balancer
{
    public interface ICloudBalancer
    {
        Task UploadAsync(string name, Stream data, CancellationToken ct = default);
        Task DownloadAsync(CloudFile file, Stream target, CancellationToken ct = default);
        Task<IReadOnlyList<CloudFile>> ListAllFilesAsync(CancellationToken ct = default);
        ValueTask<CloudSpaceInfo> GlobalSpaceAsync(CancellationToken ct = default);
    }
}