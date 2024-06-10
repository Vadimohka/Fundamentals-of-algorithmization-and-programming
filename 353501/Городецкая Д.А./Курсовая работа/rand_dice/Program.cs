using Microsoft.Extensions.Configuration;
using rand_dice.Context;
using Microsoft.EntityFrameworkCore;
using rand_dice.Models;

var builder = WebApplication.CreateBuilder(args);

// ����������� ���� ������
builder.Services.AddDbContext<ApplicationDbContext>(options =>

    //options.UseNpgsql("Host=localhost;Port=5432;Database=dicedb;Username=postgres;Password=admin");
    options.UseNpgsql(builder.Configuration.GetConnectionString("DefaultConnection"))
);

// ���������� ����� ������������ � �������������
builder.Services.AddControllersWithViews();
//builder.Services.AddScoped<Hash>();

var app = builder.Build();

// ��������� ��������� ��������� HTTP-��������
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