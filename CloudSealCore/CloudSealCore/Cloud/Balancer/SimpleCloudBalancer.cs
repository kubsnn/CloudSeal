using CloudSealCore.Cloud.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CloudSealCore.Cloud.Balancer;

public sealed class SimpleCloudBalancer : ICloudBalancer
{
    private readonly CloudProviderManager _mgr;

    public SimpleCloudBalancer(CloudProviderManager mgr) => _mgr = mgr;

    /*UPLOAD*/
    public async Task UploadAsync(string name, Stream data, CancellationToken ct = default)
    {
        long size = data.Length;                 // zakładamy seekable
        foreach (var p in _mgr.All)
        {
            var sp = await p.GetSpaceInfoAsync(ct);
            if (sp.Available > size)
            {
                await p.UploadFromStreamAsync(name, data, ct);
                return;
            }
        }
        throw new IOException("Brak miejsca we wszystkich chmurach.");
    }

    /*DOWNLOAD  (pierwsza chmura, w której plik istnieje)*/
    public async Task DownloadAsync(CloudFile file, Stream target, CancellationToken ct = default)
    {
        foreach (var p in _mgr.All)
        {
            var fileToDownload = (await p.ListFilesAsync(ct)).FirstOrDefault(f => f.Name == file.Name);
            if (fileToDownload is not null)
            {
                await p.DownloadToStreamAsync(fileToDownload, target, ct);
                return;
            }
        }
        throw new FileNotFoundException($"Plik {file.Name} nie istnieje w żadnej chmurze");
    }

    public async ValueTask<CloudSpaceInfo> GlobalSpaceAsync(CancellationToken ct = default)
        => await _mgr.TotalSpaceAsync(ct);

    public async Task<IReadOnlyList<CloudFile>> ListAllFilesAsync(CancellationToken ct = default)
    {
        var tasks = _mgr.All.Select(p => p.ListFilesAsync(ct));
        var allResults = await Task.WhenAll(tasks);

        return allResults.SelectMany(f => f).ToList();
    }
}
