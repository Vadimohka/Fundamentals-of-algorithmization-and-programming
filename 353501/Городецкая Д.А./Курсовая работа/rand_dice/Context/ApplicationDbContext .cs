using Microsoft.EntityFrameworkCore;
using rand_dice.Models;

namespace rand_dice.Context
{
    
    public class ApplicationDbContext : DbContext
    {

        public ApplicationDbContext(DbContextOptions<ApplicationDbContext> options) : base(options)
        {
        }

        public DbSet<History> History { get; set; }
        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseNpgsql("Host=localhost;Port=5432;Database=dicedb;Username=postgres;Password=admin");
        }
    }
}