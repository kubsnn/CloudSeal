using CloudSealCore.Cloud.Models;
using CloudSealCore.Crypto;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CloudSealCore.Cloud;

public interface ICloudProvider
{
    string Name { get; }
    bool IsAuthenticated { get; }

    Task AuthenticateAsync(CancellationToken cancellationToken = default);

    Task DeleteAsync(string fileId, CancellationToken cancellationToken = default);

    Task<string> GetPublicLinkAsync(string fileId);

    Task<List<CloudFile>> ListFilesAsync(CancellationToken cancellationToken = default);
    Task UploadFromStreamAsync(string fileName, Stream content, CancellationToken cancellationToken = default);
    Task DownloadToStreamAsync(CloudFile file, Stream outStream, CancellationToken cancellationToken = default);
    Task<CloudSpaceInfo> GetSpaceInfoAsync(CancellationToken cancellationToken = default);

}


