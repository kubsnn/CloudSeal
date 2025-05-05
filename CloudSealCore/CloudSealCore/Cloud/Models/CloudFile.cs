using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CloudSealCore.Cloud.Models;

public sealed record CloudFile(
    string Id,
    string Name,
    string MimeType,
    long? Size,
    DateTime? CreatedTime,
    string Source
);


