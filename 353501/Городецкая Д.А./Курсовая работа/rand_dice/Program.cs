using Microsoft.Extensions.Configuration;
using rand_dice.Context;
using Microsoft.EntityFrameworkCore;
using rand_dice.Models;

var builder = WebApplication.CreateBuilder(args);

// Подключение базы данных
builder.Services.AddDbContext<ApplicationDbContext>(options =>

    //options.UseNpgsql("Host=localhost;Port=5432;Database=dicedb;Username=postgres;Password=admin");
    options.UseNpgsql(builder.Configuration.GetConnectionString("DefaultConnection"))
);

// Добавление служб контроллеров и представлений
builder.Services.AddControllersWithViews();
//builder.Services.AddScoped<Hash>();

var app = builder.Build();

// Настройка конвейера обработки HTTP-запросов
if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Home/Error");
    app.UseHsts();
}

app.UseHttpsRedirection();
app.UseStaticFiles();

app.UseRouting();

app.UseAuthorization();

app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Home}/{action=Index}/{id?}");

app.Run();