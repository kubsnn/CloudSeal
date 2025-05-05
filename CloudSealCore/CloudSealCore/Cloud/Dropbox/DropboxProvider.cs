using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Dropbox.Api;
using Dropbox.Api.Common;
using Dropbox.Api.Files;
using System.Net;
using System.IO;
using CloudSealCore.Cloud.Models;
using Dropbox.Api.Users;
using CloudSealCore.Cloud.Auth;
using CloudSealCore.Crypto;


namespace CloudSealCore.Cloud.Dropbox;

using static PkceUtil;

public sealed class DropboxProvider : ICloudProvider
{

    public string Name => "Dropbox";

    public bool IsAuthenticated => _client is not null;

    private const string RedirectUri = "http://localhost:5000/auth/";

    private readonly string _appKey;
    private readonly ICryptoEngine _cryptoEngine;
    private readonly IProgress<long>? _progress;

    private DropboxClient _client = null!;

    public DropboxProvider(ICryptoEngine cryptoEngine, IProgress<long>? progress = null)
    {
        _cryptoEngine = cryptoEngine;
        _progress = progress;
        _appKey = Secrets.LoadClientId("Resources/cloudseal_dropbox.json");
    }
    public async Task AuthenticateAsync(CancellationToken ct = default)
    {
        var cache = DropboxTokenCache.Load();
        if (cache is { } c && c.expires > DateTime.UtcNow.AddMinutes(1))
        {
            _client = new DropboxClient(c.access);
            if (await IsTokenValidAsync()) return;
        }

        var pkce = Generate();
        var state = Guid.NewGuid().ToString("N");

        var authUrl = DropboxOAuth2Helper.GetAuthorizeUri(
            OAuthResponseType.Code,
            _appKey,
            new Uri(RedirectUri),
            state: state,
            tokenAccessType: TokenAccessType.Offline,
            scopeList: ["files.content.write", "files.content.read", "files.metadata.read", "account_info.read"],
            codeChallenge: pkce.Challenge);

        using var listener = new HttpListener();
        listener.Prefixes.Add(RedirectUri);
        listener.Start();

        System.Diagnostics.Process.Start(new System.Diagnostics.ProcessStartInfo
        {
            FileName = authUrl.ToString(),
            UseShellExecute = true
        });

        var context = await listener.GetContextAsync();
        var code = context.Request.QueryString["code"];

        var buffer = AuthHtmlPage.GetPageBytes("Dropbox");
        context.Response.ContentLength64 = buffer.Length;
        await context.Response.OutputStream.WriteAsync(buffer);
        context.Response.Close();

        var token = await DropboxOAuth2Helper.ProcessCodeFlowAsync(
            code, _appKey, redirectUri: RedirectUri,
            codeVerifier: pkce.Verifier);

        _client = new DropboxClient(token.AccessToken);


        DropboxTokenCache.Save(
            token.AccessToken,
            token.RefreshToken,
            token.ExpiresAt ?? DateTime.MaxValue);

        if (!await IsTokenValidAsync())
            throw new Exception("Nie udało się uzyskać tokena dostępu.");
    }

    private async Task<bool> IsTokenValidAsync()
    {
        try
        {
            await _client.Users.GetCurrentAccountAsync();
            return true;
        } catch { return false; }
    }

    public async Task DeleteAsync(string fileId, CancellationToken ct = default)
        => await _client.Files.DeleteV2Async(fileId);

    public async Task<List<CloudFile>> ListFilesAsync(CancellationToken ct = default)
    {
        var list = await _client.Files.ListFolderAsync(string.Empty);
        return list.Entries
            .OfType<FileMetadata>()
            .Select(f => new CloudFile(
                f.PathLower!, // Id  
                f.Name,       // Name  
                "application/octet-stream", // MimeType  
                (long?)f.Size, // Size  
                f.ServerModified, // CreatedTime  
                this.Name       // Source  
            ))
            .ToList();
    }

    public async Task<string> GetPublicLinkAsync(string fileId)
    {
        var shared = await _client.Sharing.CreateSharedLinkWithSettingsAsync(fileId);
        return shared.Url;
    }

    public async Task<CloudSpaceInfo> GetSpaceInfoAsync(CancellationToken ct = default)
    {
        var usage = await _client.Users.GetSpaceUsageAsync();
        var total = usage.Allocation.AsIndividual.Value.Allocated;
        var used = usage.Used;
        return new CloudSpaceInfo((long)(total - used), (long)total);
    }

    public async Task UploadFromStreamAsync(string fileName, Stream content, CancellationToken cancellationToken = default)
    {
        string path = fileName.StartsWith("/") ? fileName : "/" + fileName;

        await using var encryptingStream = new AsyncEncryptingReadStream(content, _cryptoEngine, _progress);
        var metadata = await _client.Files.UploadAsync(path, WriteMode.Overwrite.Instance, body: encryptingStream);

        _progress?.Report((long)metadata.Size);
    }

    public async Task DownloadToStreamAsync(CloudFile file, Stream output, CancellationToken cancellationToken = default)
    {
        var response = await _client.Files.DownloadAsync(file.Id);
        var encryptedStream = await response.GetContentAsStreamAsync();
        
        await using var decryptedStream = new AsyncDecryptingReadStream(encryptedStream, _cryptoEngine, _progress);
        await decryptedStream.CopyToAsync(output, cancellationToken);

        _progress?.Report(file.Size ?? 0);
    }

}
