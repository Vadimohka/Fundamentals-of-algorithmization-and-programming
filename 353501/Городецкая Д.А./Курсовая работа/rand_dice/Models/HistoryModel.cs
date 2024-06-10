using System.ComponentModel.DataAnnotations;

namespace rand_dice.Models
{
    public class History
    {
        public int Id { get; set; }
        public string TypeOfDice { get; set; } = null!;

        public int ValueOnDice { get; set; }
        public int Chance { get; set; }
    }
}