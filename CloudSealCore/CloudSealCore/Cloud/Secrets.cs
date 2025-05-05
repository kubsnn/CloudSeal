using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;

namespace CloudSealCore.Cloud;

public static class Secrets
{
    public static string LoadClientId(string path)
    {
        var json = File.ReadAllText(path);
        using var doc = JsonDocument.Parse(json);
        return doc.RootElement.GetProperty("client_id").GetString()!;
    }
}
