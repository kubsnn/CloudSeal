using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CloudSealCore.Data;

public sealed class CloudStatistics
{
    public int FileCount { get; set; }
    public long TotalSize { get; set; }         // == UsedByApp
    public long? AvailableSpace { get; set; }   // całkowity dysk - użycie
    public long? TotalQuota { get; set; }       // całkowity rozmiar dysku
    public string? ProviderName { get; set; }
}

