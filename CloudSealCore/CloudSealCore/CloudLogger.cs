using CloudSealCore.Cloud;
using CloudSealCore.Data;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CloudSealCore;

public static class CloudLogger
{
    public static async Task PrintAllStatisticsAsync(IEnumerable<ICloudProvider> providers)
    {
        var statsList = new List<CloudStatistics>();

        foreach (var provider in providers)
        {
            var stats = await CloudStatisticsCalculator.FromProviderAsync(provider);
            statsList.Add(stats);
            PrintSingle(stats);
        }

        // SUMA
        PrintSummary(statsList);
    }

    private static void PrintSingle(CloudStatistics stats)
    {
        Console.ForegroundColor = ConsoleColor.Cyan;
        Console.WriteLine($"\nCloudSeal – {stats.ProviderName}");
        Console.ResetColor();

        Console.Write(" • Plików: ");
        Console.ForegroundColor = ConsoleColor.Yellow;
        Console.WriteLine($"{stats.FileCount}");
        Console.ResetColor();

        Console.Write(" • Rozmiar danych aplikacji: ");
        Console.ForegroundColor = ConsoleColor.Green;
        Console.WriteLine($"{FormatSize(stats.TotalSize)}");
        Console.ResetColor();

        if (stats.TotalQuota is not null)
        {
            Console.Write(" • Użycie chmury: ");
            Console.ForegroundColor = ConsoleColor.Magenta;
            var used = stats.TotalQuota.Value - (stats.AvailableSpace ?? 0);
            var percent = (double)used / stats.TotalQuota.Value * 100;
            Console.WriteLine($"{FormatSize(used)} / {FormatSize(stats.TotalQuota.Value)} ({percent:F1}%)");
        } else if (stats.AvailableSpace is not null)
        {
            Console.Write(" • Wolne miejsce: ");
            Console.ForegroundColor = ConsoleColor.Blue;
            Console.WriteLine($"{FormatSize(stats.AvailableSpace.Value)}");
        }

        Console.ResetColor();
    }

    private static void PrintSummary(List<CloudStatistics> statsList)
    {
        Console.ForegroundColor = ConsoleColor.White;
        Console.WriteLine("\n===== PODSUMOWANIE GLOBALNE =====");
        Console.ResetColor();

        int fileCount = statsList.Sum(s => s.FileCount);
        long used = statsList.Sum(s => s.TotalSize);
        long? available = statsList.All(s => s.AvailableSpace != null) ? statsList.Sum(s => s.AvailableSpace!.Value) : null;
        long? total = statsList.All(s => s.TotalQuota != null) ? statsList.Sum(s => s.TotalQuota!.Value) : null;

        Console.Write(" • Plików łącznie: ");
        Console.ForegroundColor = ConsoleColor.Yellow;
        Console.WriteLine(fileCount);
        Console.ResetColor();

        Console.Write(" • Rozmiar danych aplikacji: ");
        Console.ForegroundColor = ConsoleColor.Green;
        Console.WriteLine(FormatSize(used));
        Console.ResetColor();

        if (total != null)
        {
            Console.Write(" • Użycie chmury (wszystkie): ");
            Console.ForegroundColor = ConsoleColor.Magenta;
            var totalUsed = total.Value - (available ?? 0);
            var percent = (double)totalUsed / total.Value * 100;
            Console.WriteLine($"{FormatSize(totalUsed)} / {FormatSize(total.Value)} ({percent:F1}%)");
        } else if (available != null)
        {
            Console.Write(" • Łączne wolne miejsce: ");
            Console.ForegroundColor = ConsoleColor.Blue;
            Console.WriteLine(FormatSize(available.Value));
        }

        Console.ResetColor();
    }

    private static string FormatSize(long bytes)
    {
        string[] units = { "B", "KB", "MB", "GB", "TB" };
        double size = bytes;
        int unit = 0;
        while (size >= 1024 && unit < units.Length - 1)
        {
            size /= 1024;
            unit++;
        }
        return $"{size:F2} {units[unit]}";
    }
}
