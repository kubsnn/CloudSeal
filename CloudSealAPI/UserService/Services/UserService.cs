using Microsoft.EntityFrameworkCore;
using UserService.Data;
using UserService.Entities;
using UserService.Exceptions;
using UserService.Models;

namespace UserService.Services;

public class UserService : IUserService
{
    private readonly UserDbContext _dbContext;
    public UserService(UserDbContext dbContext)
    {
        _dbContext = dbContext;
    }

    public async Task<KeyResponse> GetKey(string? userId)
    {
        Guid id;
        if (!Guid.TryParse(userId, out id))
        {
            throw new InvalidCredentialsException("Invalid user ID");
        }

        var user = await _dbContext.UsersData.FirstOrDefaultAsync(u => u.Id == id);

        if (user is null)
        {
            throw new InvalidCredentialsException("User not found");
        }

        user.LastAccess = DateTime.UtcNow;
        _dbContext.Update(user);

        await _dbContext.SaveChangesAsync();

        return new() { EncryptedKey = user.EncryptedKey };
    }

    public async Task InitializeUser(string? userId, string encryptedKey)
    {
        Guid id;
        if (!Guid.TryParse(userId, out id))
        {
            throw new InvalidCredentialsException("Broken ID");
        }

        if (await _dbContext.UsersData.AnyAsync(u => u.Id == id))
        {
            throw new ConflictException("User already exists");
        }

        var user = new User
        {
            Id = id,
            EncryptedKey = encryptedKey,
            LastAccess = DateTime.UtcNow
        };
        _dbContext.UsersData.Add(user);
        await _dbContext.SaveChangesAsync();
    }
}
