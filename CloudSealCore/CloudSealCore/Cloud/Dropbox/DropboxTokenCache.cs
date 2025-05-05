using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CloudSealCore.Cloud.Dropbox;

using System.Text.Json;

internal static class DropboxTokenCache
{
    private const string CacheFile = "dropbox_token.json";

    internal static (string access, string refresh, DateTime expires)? Load()
    {
        if (!File.Exists(CacheFile)) return null;
        var doc = JsonDocument.Parse(File.ReadAllText(CacheFile));
        var root = doc.RootElement;
        return (
            root.GetProperty("access").GetString()!,
            root.GetProperty("refresh").GetString()!,
            DateTime.Parse(root.GetProperty("expires").GetString()!)
        );
    }

    internal static void Save(string access, string refresh, DateTime expires)
    {
        var jsonObject = new
        {
            access,
            refresh,
            expires = expires.ToString("o") // ISO 8601 format
        };

        var json = JsonSerializer.Serialize(jsonObject);
        File.WriteAllText(CacheFile, json);
    }

}
