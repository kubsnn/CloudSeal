


# CloudSeal

CloudSeal is a secure, microservice-based platform for managing encrypted file storage across multiple cloud providers.
The system is built using ASP.NET Core microservices, a Qt 6 desktop client, and a .NET background service connected via gRPC.

![Test & Deploy Auth](https://github.com/kubsnn/CloudSeal/actions/workflows/auth-ci-master.yml/badge.svg)
![Test & Deploy User](https://github.com/kubsnn/CloudSeal/actions/workflows/user-ci-master.yml/badge.svg)


---

## Features

- **Microservice architecture** with independent `AuthService`, `UserService`, and API Gateway (YARP)
- **JWT-based authentication** with support for access token validation in gateway
- **Secure REST endpoints** using ASP.NET Core and Entity Framework
- **CI/CD workflows** via GitHub Actions with Docker image publishing to Docker Hub
- **Azure-ready** with Container Apps support and scale-to-zero configuration
- **gRPC inter-process communication** between Qt frontend and .NET background service
- **Custom exception handling middleware** for consistent error responses
- **Test coverage** using xUnit and EF Core InMemory provider

---

## Technologies

| Layer        | Stack                                                                 |
|--------------|-----------------------------------------------------------------------|
| Backend      | C#, ASP.NET Core, Entity Framework Core, JWT, Docker                |
| Frontend     | Qt 6 (QML, QtGrpc), C++20, .NET                                             |
| DevOps       | GitHub Actions, Docker Hub, Azure Container Apps                      |
| Testing      | xUnit, InMemory EF                                           |

---