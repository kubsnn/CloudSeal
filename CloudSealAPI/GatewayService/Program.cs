using Yarp.ReverseProxy;
using Microsoft.AspNetCore.Builder;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Configuration;
using System;

namespace GatewayService
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var builder = WebApplication.CreateBuilder(args);

            // Za³aduj konfiguracjê
            var config = builder.Configuration;

            // Dynamiczne nadpisanie adresów z env vars
            var reverseProxySection = config.GetSection("ReverseProxy:Clusters");

            reverseProxySection["auth-cluster:Destinations:auth:Address"] =
                Environment.GetEnvironmentVariable("AUTH_SERVICE_URL") ?? "http://localhost:5001";

            reverseProxySection["user-cluster:Destinations:user:Address"] =
                Environment.GetEnvironmentVariable("USER_SERVICE_URL") ?? "http://localhost:5002";

            // Dodaj YARP z dynamicznie wczytan¹ konfiguracj¹
            builder.Services.AddReverseProxy()
                .LoadFromConfig(config.GetSection("ReverseProxy"));

            var app = builder.Build();

            // W³¹cz reverse proxy
            app.MapReverseProxy();

            app.Run();
        }
    }
}
