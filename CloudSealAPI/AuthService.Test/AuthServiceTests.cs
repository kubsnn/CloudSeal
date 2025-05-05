using AuthService.Data;
using AuthService.Entities;
using AuthService.Exceptions;
using AuthService.Models;
using AuthService.Services;
using Microsoft.AspNetCore.Identity;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;
using Moq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AuthService.Test;

public class AuthServiceTests
{
    private AuthDbContext CreateDbContext()
    {
        var options = new DbContextOptionsBuilder<AuthDbContext>()
            .UseInMemoryDatabase(Guid.NewGuid().ToString()) // unikalna baza per test
            .Options;

        return new AuthDbContext(options);
    }

    private static IConfiguration CreateFakeJwtConfig() =>
        new ConfigurationBuilder()
            .AddInMemoryCollection(new Dictionary<string, string>
            {
                { "Jwt:Key", "test-secret-key-really-secretty1" },
                { "Jwt:Issuer", "test-issuer" },
                { "Jwt:Audience", "test-audience" }
            })
            .Build();

    [Fact]
    public async Task RegisterAsync_ShouldThrow_WhenUsernameAlreadyExists()
    {
        // Arrange
        var context = CreateDbContext();
        context.Users.Add(new User { Username = "john" });
        await context.SaveChangesAsync();

        var authService = new Services.AuthService(
            context,
            CreateFakeJwtConfig(),
            new PasswordHasher<User>()
        );

        var request = new RegisterRequest
        {
            Username = "john",
            Password = "secret"
        };

        // Act & Assert
        await Assert.ThrowsAsync<UsernameTakenException>(() => authService.RegisterAsync(request));
    }

    [Fact]
    public async Task RegisterAsync_ShouldSucceed_WhenUsernameIsUnique()
    {
        // Arrange
        var context = CreateDbContext();

        var authService = new Services.AuthService(
            context,
            CreateFakeJwtConfig(),
            new PasswordHasher<User>()
        );

        var request = new RegisterRequest
        {
            Username = "newuser",
            Password = "password"
        };

        // Act
        var result = await authService.RegisterAsync(request);

        // Assert
        Assert.NotNull(result.Token);
        Assert.True(context.Users.Any(u => u.Username == "newuser"));
    }

    private static Services.AuthService CreateServiceWithUser(string username, string plainPassword, out AuthDbContext context)
    {
        context = new AuthDbContext(
            new DbContextOptionsBuilder<AuthDbContext>()
                .UseInMemoryDatabase(Guid.NewGuid().ToString())
                .Options
        );

        var user = new User { Username = username };
        var hasher = new PasswordHasher<User>();
        user.PasswordHash = hasher.HashPassword(user, plainPassword);

        context.Users.Add(user);
        context.SaveChanges();

        return new Services.AuthService(context, CreateFakeJwtConfig(), hasher);
    }

    [Fact]
    public async Task LoginAsync_ShouldSucceed_WithCorrectCredentials()
    {
        // Arrange
        var username = "john";
        var password = "secure123";
        var authService = CreateServiceWithUser(username, password, out _);

        var request = new LoginRequest { Username = username, Password = password };

        // Act
        var result = await authService.LoginAsync(request);

        // Assert
        Assert.NotNull(result.Token);
        Assert.IsType<string>(result.Token);
    }

    [Fact]
    public async Task LoginAsync_ShouldThrow_WhenUserNotFound()
    {
        // Arrange
        var context = CreateDbContext();
        var authService = new Services.AuthService(context, CreateFakeJwtConfig(), new PasswordHasher<User>());

        var request = new LoginRequest { Username = "notfound", Password = "x" };

        // Act & Assert
        await Assert.ThrowsAsync<InvalidCredentialsException>(() => authService.LoginAsync(request));
    }

    [Fact]
    public async Task LoginAsync_ShouldThrow_WhenPasswordIsInvalid()
    {
        // Arrange
        var username = "john";
        var correctPassword = "secure123";
        var wrongPassword = "wrong";

        var authService = CreateServiceWithUser(username, correctPassword, out _);

        var request = new LoginRequest { Username = username, Password = wrongPassword };

        // Act & Assert
        await Assert.ThrowsAsync<InvalidCredentialsException>(() => authService.LoginAsync(request));
    }
}
