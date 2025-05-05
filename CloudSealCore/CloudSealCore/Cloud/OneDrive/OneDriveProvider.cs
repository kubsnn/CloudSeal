using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Graph;
using Microsoft.Identity.Client;
using System.Net.Http.Headers;
using Microsoft.Graph.Models;
using Azure.Identity;
using Microsoft.Graph.Drives.Item.Items.Item.CreateLink;
using Microsoft.Kiota.Http.HttpClientLibrary;
using Prompt = Microsoft.Identity.Client.Prompt;
using CloudSealCore.Cloud.Models;
using CloudSealCore.Crypto;

namespace CloudSealCore.Cloud.OneDrive;

public sealed class OneDriveProvider : ICloudProvider
{
    private readonly ICryptoEngine _cryptoEngine;
    private readonly IProgress<long>? _progress;

    private GraphServiceClient _graphClient;
    private string _cloudSealFolderId;
    private string _driveId;
    private static readonly string[] _scopes = { "User.Read", "Files.ReadWrite" };
    public string Name => "OneDrive";

    public bool IsAuthenticated => _graphClient is not null;

    public OneDriveProvider(ICryptoEngine cryptoEngine, IProgress<long>? progress = null)
    {
        _cryptoEngine = cryptoEngine;
        _progress = progress;
    }

    public async Task AuthenticateAsync(CancellationToken ct = default)
    {
        var clientId = Secrets.LoadClientId("Resources/onedrive_credentials.json");

        // 1) IPublicClientApplication z plikowym cache’em
        const string cacheFile = "msal_cache.bin";
        var pca = PublicClientApplicationBuilder
            .Create(clientId)
            .WithRedirectUri("http://localhost")
            .WithTenantId("common")
            .Build();

        TokenCacheHelper.EnableSerialization(pca.UserTokenCache, cacheFile);

        // 2) upewniamy się, że RAZ powstanie token (interaktywne logowanie tylko jeśli brak w cache)
        var scopes = new[] { "User.Read", "Files.ReadWrite" };
        var account = (await pca.GetAccountsAsync()).FirstOrDefault();
        try
        {
            // jeśli jest w cache → zadziała
            await pca.AcquireTokenSilent(scopes, account).ExecuteAsync(ct);
        } catch (MsalUiRequiredException)
        {
            // pierwszy raz poprosi w przeglądarce
            await pca.AcquireTokenInteractive(scopes).WithPrompt(Prompt.SelectAccount).ExecuteAsync(ct);
        }

        // 3) GraphServiceClient z własnym providerem
        var authProvider = new MsalAuthProvider(pca, scopes);
        _graphClient = new GraphServiceClient(authProvider);

        await EnsureCloudSealFolderExistsAsync(ct);
    }

    private async Task EnsureCloudSealFolderExistsAsync(CancellationToken ct = default)
    {
        // 1) Identyfikator dysku użytkownika
        var drive = await _graphClient.Me.Drive.GetAsync(cancellationToken: ct);
        _driveId = drive?.Id ?? throw new InvalidOperationException("Brak Drive ID.");

        // 2) Pobierz obiekt katalogu głównego
        var rootItem = await _graphClient
            .Drives[_driveId]
            .Root
            .GetAsync(cancellationToken: ct);                       // ← teraz mamy DriveItem

        if (rootItem is null || rootItem.Id is null)
            throw new InvalidOperationException("Nie można pobrać katalogu głównego.");

        // 3) Pobierz dzieci katalogu głównego
        var rootChildren = await _graphClient
            .Drives[_driveId]
            .Items[rootItem.Id]                  // używamy ID root-a
            .Children
            .GetAsync(cancellationToken: ct);

        if (rootChildren is null || rootChildren.Value is null)
            throw new InvalidOperationException("Nie można pobrać dzieci katalogu głównego.");

        var folder = rootChildren.Value
            .FirstOrDefault(i => i.Folder != null && i.Name == "CloudSeal");

        if (folder is not null && folder.Id is not null)
        {
            _cloudSealFolderId = folder.Id;
            return;
        }

        // 4) Utwórz folder CloudSeal, jeśli nie istnieje
        var newFolder = new DriveItem
        {
            Name = "CloudSeal",
            Folder = new Folder(),
            AdditionalData = new Dictionary<string, object>
        {
            { "@microsoft.graph.conflictBehavior", "rename" }
        }
        };

        var created = await _graphClient
            .Drives[_driveId]
            .Items[rootItem.Id]
            .Children
            .PostAsync(newFolder, cancellationToken: ct);

        if (created is null || created.Id is null)
            throw new InvalidOperationException("Nie można utworzyć folderu CloudSeal.");

        _cloudSealFolderId = created.Id;
    }


    public async Task UploadFromStreamAsync(string fileName, Stream content, CancellationToken cancellationToken = default)
    {
        await using var encryptingStream = new AsyncEncryptingReadStream(content, _cryptoEngine, _progress);

        var item = await _graphClient.Drives[_driveId]
            .Items[_cloudSealFolderId]
            .ItemWithPath(fileName)
            .Content
            .PutAsync(encryptingStream, cancellationToken: cancellationToken);

        if (item is null || item.Size is null)
            throw new InvalidOperationException("Nie można przesłać pliku.");

        _progress?.Report((long)item.Size);
    }

    public async Task DownloadToStreamAsync(CloudFile file, Stream output, CancellationToken cancellationToken = default)
    {
        var encryptedStream = await _graphClient.Drives[_driveId]
            .Items[file.Id]
            .Content
            .GetAsync(cancellationToken: cancellationToken);

        if (encryptedStream is null)
            throw new InvalidOperationException("Could not download file.");

        await using var decryptedStream = new AsyncDecryptingReadStream(encryptedStream, _cryptoEngine, _progress);
        await decryptedStream.CopyToAsync(output, cancellationToken);

        _progress?.Report(file.Size ?? 0);
    }


    public async Task DeleteAsync(string fileId, CancellationToken cancellationToken = default)
    {
        await _graphClient.Drives[_driveId].Items[fileId]
            .DeleteAsync(cancellationToken: cancellationToken);
    }

    public async Task<string> GetPublicLinkAsync(string fileId)
    {
        var body = new CreateLinkPostRequestBody
        {
            Type = "view",
            Scope = "anonymous"
        };

        var link = await _graphClient.Drives[_driveId].Items[fileId]
            .CreateLink
            .PostAsync(body);

        return link?.Link?.WebUrl ?? "N/A";
    }

    public async Task<List<CloudFile>> ListFilesAsync(CancellationToken cancellationToken = default)
    {
        var children = await _graphClient.Drives[_driveId].Items[_cloudSealFolderId]
            .Children
            .GetAsync(cancellationToken: cancellationToken);

        if (children is null || children.Value is null)
            throw new InvalidOperationException("Could not list files.");

        return children.Value?
            .Where(i => i.File != null)
            .Select(i => new CloudFile(
                i.Id,
                i.Name,
                i.File.MimeType,
                i.Size,
                i.CreatedDateTime?.DateTime,
                this.Name
            ))
            .ToList() ?? new();
    }

    public async Task<CloudSpaceInfo> GetSpaceInfoAsync(CancellationToken cancellationToken = default)
    {
        var drive = await _graphClient.Me.Drive.GetAsync(cancellationToken: cancellationToken);

        if (drive?.Quota is null)
            throw new InvalidOperationException("Nie można uzyskać informacji o przestrzeni dyskowej.");

        if (drive.Quota.Remaining is null || drive.Quota.Total is null)
            throw new InvalidOperationException("Nie można uzyskać informacji o przestrzeni dyskowej.");

        return new CloudSpaceInfo(
            (long)drive.Quota.Remaining,
            (long)drive.Quota.Total
        );
    }


}


