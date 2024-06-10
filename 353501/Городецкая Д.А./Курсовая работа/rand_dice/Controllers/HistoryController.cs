using Microsoft.AspNetCore.Mvc;
using rand_dice.Context;
using rand_dice.Models;
using System;
using System.Collections.Generic;
using System.Linq;

namespace rand_dice.Controllers
{
    public class HistoryController : Controller
    {
        private readonly ApplicationDbContext _context;

        public HistoryController(ApplicationDbContext context)
        {
            _context = context;
        }

        public IActionResult Index(string sortingOption, string diceType)
        {
            var history = _context.History.AsQueryable();

            if (!string.IsNullOrEmpty(diceType))
            {
                history = history.Where(h => h.TypeOfDice == diceType);
            }

            ViewBag.DiceTypes = _context.History.Select(h => h.TypeOfDice).Distinct().ToList();
            ViewBag.SortingOptions = new List<string>
        {
            "SortByDiceFaces",
            "SortByDiceValue",
            "SortByChance"
        };

            switch (sortingOption)
            {
                case "SortByDiceFaces":
                    history = QuickSort(history.ToList(), 0, history.Count() - 1).AsQueryable();
                    break;
                case "SortByDiceValue":
                    history = MergeSort(history.ToList(), 0, history.Count() - 1).AsQueryable();
                    break;
                case "SortByChance":
                    history = SortByChance(history.ToList()).AsQueryable();
                    break;
            }

            return View(history.ToList());
        }

        // Метод для удаления записи истории
        [HttpPost]
        public IActionResult Delete(int id)
        {
            var history = _context.History.Find(id);
            if (history != null)
            {
                _context.History.Remove(history);
                _context.SaveChanges();
            }
            return RedirectToAction("Index");
        }

        private List<History> SortByChance(List<History> history)
        {
            return history.OrderBy(h => h.Chance).ToList();
        }

        private List<History> QuickSort(List<History> history, int left, int right)
        {
            if (left < right)
            {
                int pivotIndex = Partition(history, left, right);
                history = QuickSort(history, left, pivotIndex - 1);
                history = QuickSort(history, pivotIndex + 1, right);
            }
            return history;
        }

        private int Partition(List<History> history, int left, int right)
        {
            string pivot = history[right].TypeOfDice;
            int i = left - 1;

            for (int j = left; j < right; j++)
            {
                if (string.Compare(history[j].TypeOfDice, pivot, StringComparison.Ordinal) < 0)
                {
                    i++;
                    Swap(history, i, j);
                }
            }

            Swap(history, i + 1, right);
            return i + 1;
        }

        private void Swap(List<History> history, int i, int j)
        {
            History temp = history[i];
            history[i] = history[j];
            history[j] = temp;
        }

        private List<History> MergeSort(List<History> history, int left, int right)
        {
            if (left < right)
            {
                int middle = left + (right - left) / 2;
                history = MergeSort(history, left, middle);
                history = MergeSort(history, middle + 1, right);
                history = Merge(history, left, middle, right);
            }
            return history;
        }

        private List<History> Merge(List<History> history, int left, int middle, int right)
        {
            List<History> result = new List<History>();
            int i = left, j = middle + 1;

            while (i <= middle && j <= right)
            {
                if (history[i].ValueOnDice <= history[j].ValueOnDice)
                {
                    result.Add(history[i]);
                    i++;
                }
                else
                {
                    result.Add(history[j]);
                    j++;
                }
            }

            while (i <= middle)
            {
                result.Add(history[i]);
                i++;
            }

            while (j <= right)
            {
                result.Add(history[j]);
                j++;
            }

            for (int k = left; k <= right; k++)
            {
                history[k] = result[k - left];
            }

            return history;
        }
    }
}