using Microsoft.EntityFrameworkCore;
using UserService.Entities;

namespace UserService.Data;

public class UserDbContext : DbContext
{
    public DbSet<User> UsersData { get; set; }
    public UserDbContext(DbContextOptions<UserDbContext> options) : base(options)
    {
    }
    // Define your DbSet properties here
    // public DbSet<YourEntity> YourEntities { get; set; } = null!;
    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        // Configure your entity mappings here
        // modelBuilder.Entity<YourEntity>()
        //     .HasKey(e => e.Id);
        modelBuilder.Entity<User>()
            .HasKey(u => u.Id);
        modelBuilder.Entity<User>()
            .Property(u => u.EncryptedKey)
            .IsRequired()
            .HasMaxLength(255);
    }
}