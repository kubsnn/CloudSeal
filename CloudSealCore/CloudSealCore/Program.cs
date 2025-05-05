using System.Text;
using CloudSealCore.Cloud;
using CloudSealCore.Cloud.Dropbox;
using CloudSealCore.Cloud.GoogleDrive;
using CloudSealCore.Cloud.OneDrive;
using CloudSealCore.Crypto;
using CloudSealCore.Grpc;
using CloudSealCore.Security;
using Grpc.Core;

namespace CloudSealCore;

sealed class Program
{
    public static void Main()
    {
        var app = new CloudSealCoreApp();

        var server = new Server
        {
            Services = { CloudSeal.BindService(new CloudSealService(app)) },
            Ports = { new ServerPort("localhost", 50051, ServerCredentials.Insecure) }
        };

        server.Start();
    }
}
