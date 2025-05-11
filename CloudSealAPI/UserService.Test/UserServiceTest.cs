using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;
using UserService.Data;
using UserService.Entities;
using UserService.Services;

namespace UserService.Test;

public class UserServiceTests
{
    private UserDbContext CreateDbContext()
    {
        var options = new DbContextOptionsBuilder<UserDbContext>()
            .UseInMemoryDatabase(Guid.NewGuid().ToString()) // unikalna baza per test
            .Options;

        return new UserDbContext(options);
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
    public async Task GetKeyAsync()
    {
        // Arrange
        var context = CreateDbContext();

        var userId = Guid.NewGuid();
        var key = "test-encrypted-key";
        await CreateUserAsync(context, userId.ToString(), key);

        IUserService userService = new Services.UserService(context);

        // Act
        var result = await userService.GetKey(userId.ToString());

        // Assert
        Assert.Equal(key, result.EncryptedKey);
    }

    [Fact]
    public async Task InitializeKey()
    {
        var context = CreateDbContext();
        IUserService userService = new Services.UserService(context);
        var userId = Guid.NewGuid();
        var encryptedKey = "test-encrypted-key";

        // Act
        await userService.InitializeUser(userId.ToString(), encryptedKey);

        // Assert
        var user = await context.UsersData.FirstOrDefaultAsync(u => u.Id == userId);
        Assert.NotNull(user);
        Assert.Equal(userId, user.Id);
        Assert.Equal(encryptedKey, user.EncryptedKey);
    }

    private async Task CreateUserAsync(UserDbContext context, string userId, string encryptedKey)
    {
        var user = new User
        {
            Id = Guid.Parse(userId),
            EncryptedKey = encryptedKey,
            LastAccess = DateTime.UtcNow
        };
        context.UsersData.Add(user);
        await context.SaveChangesAsync();
    }
}