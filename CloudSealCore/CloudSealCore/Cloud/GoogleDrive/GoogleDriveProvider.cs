using CloudSealCore.Cloud.Models;
using CloudSealCore.Crypto;
using Google.Apis.Auth.OAuth2;
using Google.Apis.Drive.v3;
using Google.Apis.Services;
using Google.Apis.Util.Store;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CloudSealCore.Cloud.GoogleDrive;

public sealed class GoogleDriveProvider : ICloudProvider
{
    private const string CredentialsPath = "Resources/gdrive_credentials.json";
    private const string TokenFolder = "cloudseal_gdrive";

    private readonly ICryptoEngine _cryptoEngine;
    private readonly IProgress<long>? _progress;

    private DriveService? _driveService;
    private string? _cloudSealFolderId;

    public string Name => "Google Drive";

    public bool IsAuthenticated => _driveService is not null;

    public GoogleDriveProvider(ICryptoEngine cryptoEngine, IProgress<long>? progress = null)
    {
        _cryptoEngine = cryptoEngine;
        _progress = progress;
    }

    public async Task AuthenticateAsync(CancellationToken cancellationToken = default)
    {
        using var stream = new FileStream(CredentialsPath, FileMode.Open, FileAccess.Read);

        var tokenPath = Path.Combine(
            Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData),
            TokenFolder);

        var credential = await GoogleWebAuthorizationBroker.AuthorizeAsync(
            GoogleClientSecrets.FromStream(stream).Secrets,
            new[] { DriveService.Scope.DriveFile },
            "user",
            cancellationToken,
            new FileDataStore(tokenPath, true)
        );

        _driveService = new DriveService(new BaseClientService.Initializer
        {
            HttpClientInitializer = credential,
            ApplicationName = "CloudSeal"
        });

        await EnsureCloudSealFolderExistsAsync(cancellationToken);
    }

    public async Task UploadFromStreamAsync(string fileName, Stream content, CancellationToken cancellationToken = default)
    {
        if (_driveService is null)
            throw new InvalidOperationException("Could not upload file. Not authenticated.");
        // 1. Wyszukaj istniejący plik o tej samej nazwie w folderze CloudSeal
        var listRequest = _driveService.Files.List();
        listRequest.Q = $"name = '{fileName}' and '{_cloudSealFolderId}' in parents and trashed = false";
        listRequest.Spaces = "drive";
        listRequest.Fields = "files(id)";
        listRequest.PageSize = 1;

        var existingFiles = await listRequest.ExecuteAsync(cancellationToken);
        string? existingFileId = existingFiles.Files.FirstOrDefault()?.Id;

        // 2. Utwórz metadane pliku (do create/update)
        var fileMetadata = new Google.Apis.Drive.v3.Data.File
        {
            Name = fileName,
            Parents = [_cloudSealFolderId]
        };

        // 3. Szyfrowany strumień wejściowy
        await using var encryptingStream = new AsyncEncryptingReadStream(content, _cryptoEngine, _progress);

        // 4. Jeśli plik istnieje — zaktualizuj go
        if (!string.IsNullOrEmpty(existingFileId))
        {
            await this.UpdateFileAsync(existingFileId, encryptingStream, cancellationToken);
        } 
        else
        {
            await this.CreateFileAsync(fileMetadata, encryptingStream, cancellationToken);
        }
    }
    private async Task CreateFileAsync(Google.Apis.Drive.v3.Data.File fileMetadata, AsyncEncryptingReadStream encryptingStream, CancellationToken cancellationToken)
    {
        var createRequest = _driveService!.Files.Create(
                        fileMetadata,
                        encryptingStream,
                        "application/octet-stream"
                    );
        createRequest.Fields = "id";

        var result = await createRequest.UploadAsync(cancellationToken);
        if (result.Status != Google.Apis.Upload.UploadStatus.Completed)
            throw new IOException($"Upload nie powiódł się: {result.Exception?.Message}");

        _progress?.Report(result.BytesSent);
    }

    private async Task UpdateFileAsync(string existingFileId, AsyncEncryptingReadStream encryptingStream, CancellationToken cancellationToken)
    {
        var updateRequest = _driveService!.Files.Update(
                        new Google.Apis.Drive.v3.Data.File(), // puste metadane — nie zmieniamy nazwy
                        existingFileId,
                        encryptingStream,
                        "application/octet-stream"
                    );
        var result = await updateRequest.UploadAsync(cancellationToken);
        if (result.Status != Google.Apis.Upload.UploadStatus.Completed)
            throw new IOException($"Update nie powiódł się: {result.Exception?.Message}");

        _progress?.Report(result.BytesSent);
    }

    public async Task DownloadToStreamAsync(CloudFile file, Stream output, CancellationToken cancellationToken = default)
    {
        var request = _driveService!.Files.Get(file.Id);
        var encryptedStream = new MemoryStream();
        await request.DownloadAsync(encryptedStream, cancellationToken);

        encryptedStream.Position = 0;
        await using var decryptedStream = new AsyncDecryptingReadStream(encryptedStream, _cryptoEngine, _progress);
        await decryptedStream.CopyToAsync(output, cancellationToken);

        _progress?.Report(file.Size ?? 0);
    }


    public async Task<List<CloudFile>> ListFilesAsync(CancellationToken cancellationToken = default)
    {
        var request = _driveService!.Files.List();
        request.Q = $"'{_cloudSealFolderId}' in parents and trashed = false";
        request.Fields = "files(id, name, mimeType, size, createdTime)";

        var result = await request.ExecuteAsync(cancellationToken);

        return result.Files.Select(f => new CloudFile(
            f.Id,
            f.Name,
            f.MimeType,
            f.Size,
            f.CreatedTimeRaw != null ? DateTime.Parse(f.CreatedTimeRaw) : null,
            this.Name
        )).ToList();
    }

    public Task DeleteAsync(string fileId, CancellationToken cancellationToken = default)
    {
        return _driveService!.Files.Delete(fileId).ExecuteAsync(cancellationToken);
    }

    public Task<string> GetPublicLinkAsync(string fileId)
    {
        // Można dodać udostępnianie, ale wymaga ustawienia permission
        return Task.FromResult("N/A");
    }

    private async Task EnsureCloudSealFolderExistsAsync(CancellationToken cancellationToken)
    {
        // Szukamy folderu "CloudSeal"
        var request = _driveService!.Files.List();
        request.Q = "mimeType = 'application/vnd.google-apps.folder' and name = 'CloudSeal' and trashed = false";
        request.Fields = "files(id, name)";

        var result = await request.ExecuteAsync(cancellationToken);
        var folder = result.Files.FirstOrDefault();

        if (folder != null)
        {
            _cloudSealFolderId = folder.Id;
            return;
        }

        // Jeśli nie istnieje, tworzymy nowy folder
        var fileMetadata = new Google.Apis.Drive.v3.Data.File
        {
            Name = "CloudSeal",
            MimeType = "application/vnd.google-apps.folder"
        };

        var createRequest = _driveService.Files.Create(fileMetadata);
        createRequest.Fields = "id";

        var newFolder = await createRequest.ExecuteAsync(cancellationToken);
        _cloudSealFolderId = newFolder.Id;
    }

    public async Task<CloudSpaceInfo> GetSpaceInfoAsync(CancellationToken cancellationToken = default)
    {
        if (_driveService is null)
            throw new InvalidOperationException("Could not get space info. Not authenticated.");

        var aboutRequest = _driveService.About.Get();
        aboutRequest.Fields = "storageQuota";
        var about = await aboutRequest.ExecuteAsync(cancellationToken);
        var quota = about.StorageQuota;

        if (quota is null)
            return new CloudSpaceInfo(0, 0);

        if (quota.Usage is null || quota.Limit is null)
            return new CloudSpaceInfo(0, 0);

        return new CloudSpaceInfo(
            (long)quota.Limit - (long)quota.Usage,
            (long)quota.Limit
        );
    }
}