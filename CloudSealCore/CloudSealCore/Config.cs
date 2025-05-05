using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CloudSealCore;

public static class Config
{
    public static string CloudSealDirectory { get; } = Path.Combine(Directory.GetCurrentDirectory(), "CloudSeal");    
    public static string ExecutablePath { get; } = AppDomain.CurrentDomain.BaseDirectory;
    public static string KeyFilePath { get; } = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "key.bin");
}
