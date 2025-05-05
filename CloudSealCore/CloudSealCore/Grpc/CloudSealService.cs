using Google.Protobuf;
using Grpc.Core;

namespace CloudSealCore.Grpc;

public class CloudSealService : CloudSeal.CloudSealBase
{
    private readonly CloudSealCoreApp _core;

    public CloudSealService(CloudSealCoreApp core)
    {
        _core = core;
    }

    public override async Task<Status> UploadFile(FileTransferPath request, ServerCallContext context)
    {
        if (!File.Exists(request.LocalPath))
        {
            return new Status { Success = false, Message = $"Plik lokalny nie istnieje: {request.LocalPath}" };
        }

        try
        {
            await using var input = File.OpenRead(request.LocalPath);
            await _core.Balancer.UploadAsync(request.RemoteName, input, context.CancellationToken);
            return new Status { Success = true, Message = "Plik przesłany pomyślnie." };
        } catch (Exception ex)
        {
            return new Status { Success = false, Message = $"Błąd: {ex.Message}" };
        }
    }

    public override async Task<Status> DownloadFile(FileTransferPath request, ServerCallContext context)
    {
        try
        {
            var cloudFile = (await _core.Balancer.ListAllFilesAsync(context.CancellationToken))
                .FirstOrDefault(f => f.Name == request.RemoteName);

            if (cloudFile == null)
                return new Status { Success = false, Message = $"Nie znaleziono pliku: {request.RemoteName}" };

            await using var output = File.Create(request.LocalPath);
            await _core.Balancer.DownloadAsync(cloudFile, output, context.CancellationToken);

            return new Status { Success = true, Message = "Plik pobrany pomyślnie." };
        } catch (Exception ex)
        {
            return new Status { Success = false, Message = $"Błąd: {ex.Message}" };
        }
    }

    public override async Task<FileList> ListFiles(AuthToken request, ServerCallContext context)
    {
        var all = await _core.Balancer.ListAllFilesAsync(context.CancellationToken);
        var result = new FileList();

        result.Files.AddRange(all.Select(f => new Grpc.CloudFile
        {
            Id = f.Id,
            Name = f.Name,
            MimeType = f.MimeType,
            Size = f.Size ?? 0,
            CreatedTime = f.CreatedTime?.ToString("o") ?? "",
            Source = f.Source
        }));

        return result;
    }


    public override async Task<GlobalStats> GetStats(AuthToken request, ServerCallContext context)
    {
        var stats = await _core.Balancer.GlobalSpaceAsync(context.CancellationToken);
        return new GlobalStats
        {
            Total = stats.Total,
            Free = stats.Available
        };
    }
}
