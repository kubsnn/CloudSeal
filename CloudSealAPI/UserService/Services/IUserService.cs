
using UserService.Models;

namespace UserService.Services
{
    public interface IUserService
    {
        Task<KeyResponse> GetKey(string? userId);
        Task InitializeUser(string? userId, string encryptedKey);
    }
}