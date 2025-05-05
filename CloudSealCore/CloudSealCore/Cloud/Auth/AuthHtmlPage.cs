using System.Text;

namespace CloudSealCore.Cloud.Auth;

public static class AuthHtmlPage
{
    private const string TemplatePath = "Resources/AuthComplete.html";

    /// <summary>
    /// Wczytuje i wypełnia stronę HTML po zakończeniu logowania.
    /// </summary>
    /// <param name="provider">Nazwa providera, np. "Google Drive", "Dropbox"</param>
    public static byte[] GetPageBytes(string provider = "drive")
    {
        if (!File.Exists(TemplatePath))
            return Encoding.UTF8.GetBytes("<html><body>Logowanie zakończone.</body></html>");

        var html = File.ReadAllText(TemplatePath)
                       .Replace("{{provider}}", provider);

        return Encoding.UTF8.GetBytes(html);
    }
}
