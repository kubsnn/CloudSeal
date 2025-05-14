namespace UserService.Entities;

public class User
{
    public Guid Id { get; set; }
    public string EncryptedKey { get; set; } = string.Empty;
    public DateTime LastAccess { get; set; } = DateTime.UtcNow;
}
