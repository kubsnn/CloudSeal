using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Identity.Client;

namespace CloudSealCore.Cloud.OneDrive;

public static class TokenCacheHelper
{
    public static void EnableSerialization(ITokenCache tokenCache, string filePath)
    {
        tokenCache.SetBeforeAccess(args =>
        {
            if (File.Exists(filePath))
            {
                var data = File.ReadAllBytes(filePath);
                args.TokenCache.DeserializeMsalV3(data);
            }
        });

        tokenCache.SetAfterAccess(args =>
        {
            if (args.HasStateChanged)
            {
                var data = args.TokenCache.SerializeMsalV3();
                File.WriteAllBytes(filePath, data);
            }
        });
    }
}

