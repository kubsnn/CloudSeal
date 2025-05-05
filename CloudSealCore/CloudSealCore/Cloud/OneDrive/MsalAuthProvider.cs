using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Kiota.Abstractions;
using Microsoft.Kiota.Abstractions.Authentication;
using Microsoft.Identity.Client;

namespace CloudSealCore.Cloud.OneDrive;

using Microsoft.Kiota.Abstractions.Authentication;
using System.Threading;

public sealed class MsalAuthProvider : IAuthenticationProvider
{
    private readonly IPublicClientApplication _app;
    private readonly IEnumerable<string> _scopes;

    public MsalAuthProvider(IPublicClientApplication app, IEnumerable<string> scopes)
    {
        _app = app;
        _scopes = scopes;
    }
    public async Task AuthenticateRequestAsync(RequestInformation request, Dictionary<string, object>? additionalAuthenticationContext = null, CancellationToken cancellationToken = default)
    {
        // zawsze próbujemy silent – tokeny są w lokalnym pliku cache
        var account = (await _app.GetAccountsAsync()).FirstOrDefault();
        var result = await _app.AcquireTokenSilent(_scopes, account).ExecuteAsync();

        // dopisujemy nagłówek
        request.Headers.Add("Authorization", $"Bearer {result.AccessToken}");
    }
}

