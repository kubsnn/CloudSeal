using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CloudSealCore.Cloud.Models;

public sealed record CloudSpaceInfo(
    long Available,
    long Total
);
