using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;
using rand_dice.Context;
using rand_dice.Models;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace rand_dice.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;
        private readonly ApplicationDbContext _dbContext;
        private readonly CustomRandom _customRandom;

        public HomeController(ILogger<HomeController> logger, ApplicationDbContext dbContext)
        {
            _logger = logger;
            _dbContext = dbContext;
            _customRandom = new CustomRandom(DateTime.Now.Ticks); // Initialize with current time ticks
        }

        public IActionResult Index()
        {
            return View();
        }

        [HttpPost]
        public JsonResult RollDice(int TypeOfDice)
        {
            try
            {
                _logger.LogInformation($"Rolling a {TypeOfDice}-sided dice.");

                int diceRoll = _customRandom.Next(1, TypeOfDice + 1);
                int[,] matrix = new int[3, 3];

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        matrix[i, j] = _customRandom.Next(1, TypeOfDice + 1);
                    }
                }

                SaveDiceRoll(TypeOfDice.ToString(), diceRoll); // Save the dice roll

                var result = new
                {
                    diceRoll,
                    typeOfDice = TypeOfDice,
                    matrix
                };

                return Json(result);
            }
            catch (Exception ex)
            {
                _logger.LogError($"An error occurred while rolling the dice: {ex.Message}");
                return Json(new { error = ex.Message });
            }
        }

        [HttpPost]
        public IActionResult Index(History viewModel)
        {
            try
            {
                var lastNineRolls = GetLastNineRolls();

                if (lastNineRolls.Count < 9)
                {
                    var diceRoll = GenerateDiceRoll(viewModel.TypeOfDice);
                    viewModel.ValueOnDice = diceRoll;
                    viewModel.Chance = CalculateDiceRollProbability(viewModel.TypeOfDice, diceRoll);

                    SaveDiceRoll(viewModel.TypeOfDice, diceRoll);

                    ViewBag.DiceRoll = diceRoll;

                    var matrix = GenerateMatrixFromHistory(GetLastNineRolls());

                    return Json(new { diceRoll, typeOfDice = viewModel.TypeOfDice, matrix });
                }
                else
                {
                    var diceRoll = GenerateDiceRoll(viewModel.TypeOfDice);
                    viewModel.ValueOnDice = diceRoll;
                    viewModel.Chance = CalculateDiceRollProbability(viewModel.TypeOfDice, diceRoll);

                    SaveDiceRoll(viewModel.TypeOfDice, diceRoll);

                    ViewBag.DiceRoll = diceRoll;

                    var matrix = GenerateMatrixFromHistory(GetLastNineRolls());

                    return Json(new { diceRoll, typeOfDice = viewModel.TypeOfDice, matrix });
                }
            }
            catch (Exception ex)
            {
                _logger.LogError($"An error occurred while processing the dice roll: {ex.Message}");
                return Json(new { error = ex.Message });
            }
        }

        private List<History> GetLastNineRolls()
        {
            return _dbContext.History
                .OrderByDescending(h => h.Id)
                .Take(9)
                .ToList();
        }

        [HttpPost]
        public IActionResult AddHistoryAndCalculateDeterminant()
        {
            var lastNineRolls = GetLastNineRolls();

            if (lastNineRolls.Count != 9)
            {
                return BadRequest("Не хватает данных для вычисления определителя матрицы");
            }

            var matrix = GenerateMatrixFromHistory(lastNineRolls);
            var determinant = CalculateMatrixDeterminant(matrix);

            return Json(new { matrix, determinant });
        }

        private int GenerateDiceRoll(string typeOfDice)
        {
            return typeOfDice switch
            {
                "4" => _customRandom.Next(1, 5),
                "6" => _customRandom.Next(1, 7),
                "8" => _customRandom.Next(1, 9),
                "10" => _customRandom.Next(1, 11),
                "12" => _customRandom.Next(1, 13),
                "20" => _customRandom.Next(1, 21),
                "100" => _customRandom.Next(1, 101),
                _ => throw new ArgumentException("Invalid dice type"),
            };
        }
        


        public int CalculateDiceRollProbability(string typeOfDice, int diceRoll)
        {
            int countDiceRoll = _dbContext.History.Count(m => m.ValueOnDice == diceRoll && m.TypeOfDice == typeOfDice);
            int countOfDiceRollsOfType = _dbContext.History.Count(m => m.TypeOfDice == typeOfDice);

            return countOfDiceRollsOfType == 0 ? 0 : (countDiceRoll * 100) / countOfDiceRollsOfType;
        }

        private void SaveDiceRoll(string typeOfDice, int diceRoll)
        {
            var diceEntity = new History
            {
                TypeOfDice = typeOfDice,
                ValueOnDice = diceRoll,
                Chance = CalculateDiceRollProbability(typeOfDice, diceRoll)
            };

            _dbContext.History.Add(diceEntity);

            try
            {
                _dbContext.SaveChanges();
                _logger.LogInformation("Data saved successfully.");
            }
            catch (Exception ex)
            {
                _logger.LogError($"An error occurred while saving data: {ex.Message}");
                throw;
            }
        }

        private List<List<int>> GenerateMatrixFromHistory(List<History> lastNineRolls)
        {
            var matrix = new List<List<int>>();
            for (int i = 0; i < 3; i++)
            {
                var row = new List<int>();
                for (int j = 0; j < 3; j++)
                {
                    row.Add(lastNineRolls[i * 3 + j].ValueOnDice);
                }
                matrix.Add(row);
            }
            return matrix;
        }

        private int CalculateMatrixDeterminant(List<List<int>> matrix)
        {
            int n = 3;
            double[,] mat = new double[n, n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    mat[i, j] = matrix[i][j];
                }
            }

            for (int i = 0; i < n; i++)
            {
                double maxEl = Math.Abs(mat[i, i]);
                int maxRow = i;
                for (int k = i + 1; k < n; k++)
                {
                    if (Math.Abs(mat[k, i]) > maxEl)
                    {
                        maxEl = Math.Abs(mat[k, i]);
                        maxRow = k;
                    }
                }

                for (int k = i; k < n; k++)
                {
                    double tmp = mat[maxRow, k];
                    mat[maxRow, k] = mat[i, k];
                    mat[i, k] = tmp;
                }

                for (int k = i + 1; k < n; k++)
                {
                    double c = -mat[k, i] / mat[i, i];
                    for (int j = i; j < n; j++)
                    {
                        if (i == j)
                        {
                            mat[k, j] = 0;
                        }
                        else
                        {
                            mat[k, j] += c * mat[i, j];
                        }
                    }
                }
            }

            double det = 1;
            for (int i = 0; i < n; i++)
            {
                det *= mat[i, i];
            }

            return (int)Math.Round((-1)*det);
        }

        private string CalculateSHA256Hash(string input)
        {
            using (SHA256 sha256 = SHA256.Create())
            {
                byte[] bytes = sha256.ComputeHash(Encoding.UTF8.GetBytes(input));
                StringBuilder builder = new StringBuilder();
                foreach (byte b in bytes)
                {
                    builder.Append(b.ToString("x2"));
                }
                return builder.ToString();
            }
        }

        [HttpPost]
        public async Task<IActionResult> ImportFromFile(IFormFile file)
        {
            if (file == null || file.Length == 0)
            {
                TempData["Message"] = "Файл не выбран или пуст.";
                return RedirectToAction(nameof(Index));
            }

            try
            {
                using (var reader = new StreamReader(file.OpenReadStream()))
                {
                    while (!reader.EndOfStream)
                    {
                        var line = await reader.ReadLineAsync();
                        var parts = line.Split(' ');

                        // Проверка формата строки
                        if (parts.Length != 2)
                        {
                            TempData["Message"] = $"Неверный формат строки: {line}. Ожидается две части разделенные пробелом.";
                            return RedirectToAction(nameof(Index));
                        }

                        var diceType = parts[0];
                        var value = int.Parse(parts[1]);

                        // Проверка диапазона значений
                        if (IsValidDiceType(diceType) && IsValidDiceValue(diceType, value))
                        {
                            SaveDiceRoll(diceType, value);
                        }
                        else
                        {
                            _logger.LogWarning($"Неверные данные для сохранения: {line}");
                        }
                    }
                }

                TempData["Message"] = "Данные успешно импортированы.";
                return RedirectToAction(nameof(Index));
            }
            catch (Exception ex)
            {
                _logger.LogError($"Ошибка при импорте данных: {ex.Message}");
                TempData["Message"] = "Произошла ошибка при импорте данных.";
                return RedirectToAction(nameof(Index));
            }
        }

        [HttpPost]
        public IActionResult ExportToFile()
        {
            try
            {
                var history = _dbContext.History.ToList();
                var sb = new StringBuilder();

                foreach (var item in history)
                {
                    var data = $"{item.TypeOfDice} {item.ValueOnDice}";
                    var hash = CalculateSHA256Hash(data);
                    sb.AppendLine($"{data} {hash}");
                }

                var fileName = "dice_history.txt";
                var mimeType = "text/plain";
                var fileBytes = Encoding.UTF8.GetBytes(sb.ToString());

                TempData["Message"] = "Данные успешно экспортированы.";
                return File(fileBytes, mimeType, fileName);
            }
            catch (Exception ex)
            {
                _logger.LogError($"Ошибка при экспорте данных: {ex.Message}");
                TempData["Message"] = "Произошла ошибка при экспорте данных.";
                return RedirectToAction(nameof(Index));
            }
        }

        private bool IsValidDiceType(string diceType)
        {
            var validDiceTypes = new string[] { "d4", "d6", "d8", "d10", "d12", "d20", "d100" };
            return validDiceTypes.Contains(diceType);
        }

        private bool IsValidDiceValue(string diceType, int value)
        {
            switch (diceType)
            {
                case "d4":
                    return value >= 1 && value <= 4;
                case "d6":
                    return value >= 1 && value <= 6;
                case "d8":
                    return value >= 1 && value <= 8;
                case "d10":
                    return value >= 1 && value <= 10;
                case "d12":
                    return value >= 1 && value <= 12;
                case "d20":
                    return value >= 1 && value <= 20;
                case "d100":
                    return value >= 1 && value <= 100;
                default:
                    return false;
            }
        }

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
    }
}
public class CustomRandom
{
    private long _seed;

    public CustomRandom(long seed)
    {
        _seed = seed;
    }

    public int Next(int minValue, int maxValue)
    {
        _seed = (_seed * 48271) % 2147483647;
        return (int)(-1*(_seed % (maxValue - minValue)) + minValue);
    }
}

