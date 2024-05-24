using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Numerics;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;

namespace ScientificСalculator
{
    public partial class Form1 : Form
    {
        double enterFirstValue, enterSecondValue;
        String op;
        public Form1()
        {
            InitializeComponent();
        }
        private void EnterNumbers(object sender, EventArgs e)
        {
            try
            {
                System.Windows.Forms.Button num = (System.Windows.Forms.Button)sender;
                if (txtResult.Text == "0")
                    txtResult.Text = "";
                {
                    if (num.Text == ",")
                    {
                        if (!txtResult.Text.Contains(","))
                            txtResult.Text = txtResult.Text + num.Text;
                    }
                    else
                    {
                        txtResult.Text = txtResult.Text + num.Text;
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка: " + ex.Message);
            }
        }

        private void numberOper(object sender, EventArgs e)
        {
            System.Windows.Forms.Button num = (System.Windows.Forms.Button)sender;
            enterFirstValue = Convert.ToDouble(txtResult.Text);
            op = num.Text;
            txtResult.Text = "";
        }

        private void btnEqual_Click(object sender, EventArgs e)
        {
            try
            {
                enterSecondValue = Convert.ToDouble(txtResult.Text);
                switch (op)
                {
                    case "+":
                        txtResult.Text = (enterFirstValue + enterSecondValue).ToString();
                        break;

                    case "-":
                        txtResult.Text = (enterFirstValue - enterSecondValue).ToString();
                        break;

                    case "*":
                        txtResult.Text = (enterFirstValue * enterSecondValue).ToString();
                        break;

                    case "/":
                        if (enterSecondValue != 0)
                            txtResult.Text = (enterFirstValue / enterSecondValue).ToString();
                        else txtResult.Text = "Error";
                        break;
                    case "Mod":
                        txtResult.Text = (enterFirstValue % enterSecondValue).ToString();
                        break;
                    case "Exp":
                        double i = Convert.ToDouble(txtResult.Text);
                        double j = enterSecondValue;
                        txtResult.Text = Math.Exp(i * Math.Log(j * 4)).ToString();
                        break;
                    default:
                        break;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка: " + ex.Message);
            }
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            txtResult.Text = "0";
        }

        private void btnClearEntry_Click(object sender, EventArgs e)
        {
            txtResult.Text = "0";
            String f, s;
            f = Convert.ToString(enterFirstValue);
            s = Convert.ToString(enterSecondValue);

            f = "";
            s = "";
        }

        private void btnPM_Click(object sender, EventArgs e)
        {
            double q = Convert.ToDouble(txtResult.Text);
            txtResult.Text = Convert.ToString(-1 * q);
        }

        private void btnBS_Click(object sender, EventArgs e)
        {
            if (txtResult.Text.Length > 0)
            {
                txtResult.Text = txtResult.Text.Remove(txtResult.Text.Length - 1, 1);
            }
            if (txtResult.Text == "")
            {
                txtResult.Text = "0";
            }
        }

        private void standardToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Width = 318;
            this.Height = 385;
            txtResult.Width = 280;
        }

        private void sietificToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Width = 630;
            this.Height = 385;
            txtResult.Width = 592;
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            DialogResult exitCal;
            exitCal = MessageBox.Show("Confirm if you want to exit", "Scientific Calculator",
                MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (exitCal == DialogResult.Yes)
            {
                Application.Exit();
            }
        }

        private void btnPi_Click(object sender, EventArgs e)
        {
            txtResult.Text = Math.PI.ToString();
        }

        private void btnLog_Click(object sender, EventArgs e)
        {
            try
            {
                double logg = Convert.ToDouble(txtResult.Text);
                logg = Math.Log10(logg);
                txtResult.Text = logg.ToString();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка: " + ex.Message);
            }
        }

        private void btnSqrt_Click(object sender, EventArgs e)
        {
            try
            {
                double sqrt = Convert.ToDouble(txtResult.Text);
                sqrt = Math.Sqrt(sqrt);
                txtResult.Text = sqrt.ToString();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка: " + ex.Message);
            }
        }

        private void btnx2_Click(object sender, EventArgs e)
        {
            double x = Convert.ToDouble(txtResult.Text);
            x = Math.Pow(x, 2);
            txtResult.Text = x.ToString();
        }

        private void btnx3_Click(object sender, EventArgs e)
        {
            double x = Convert.ToDouble(txtResult.Text);
            x = Math.Pow(x, 3);
            txtResult.Text = x.ToString();
        }

        private void btnSinh_Click(object sender, EventArgs e)
        {
            try
            {
                double sinh = Convert.ToDouble(txtResult.Text);
                sinh = Math.Sinh(sinh);
                txtResult.Text = sinh.ToString();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка: " + ex.Message);
            }
        }

        private void btnSin_Click(object sender, EventArgs e)
        {
            try
            {
                double sin = Convert.ToDouble(txtResult.Text);
                sin = Math.Sin(sin);
                txtResult.Text = sin.ToString();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка: " + ex.Message);
            }
        }

        private void btnCosh_Click(object sender, EventArgs e)
        {
            try
            {
                double cosh = Convert.ToDouble(txtResult.Text);
                cosh = Math.Cosh(cosh);
                txtResult.Text = cosh.ToString();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка: " + ex.Message);
            }
        }

        private void btnCos_Click(object sender, EventArgs e)
        {
            try
            {
                double cos = Convert.ToDouble(txtResult.Text);
                cos = Math.Cos(cos);
                txtResult.Text = cos.ToString();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка: " + ex.Message);
            }
        }

        private void btnTanh_Click(object sender, EventArgs e)
        {
            try
            {
                double tanh = Convert.ToDouble(txtResult.Text);
                tanh = Math.Tanh(tanh);
                txtResult.Text = tanh.ToString();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка: " + ex.Message);
            }
        }

        private void btnTan_Click(object sender, EventArgs e)
        {
            try
            {
                double tan = Convert.ToDouble(txtResult.Text);
                tan = Math.Tan(tan);
                txtResult.Text = tan.ToString();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка: " + ex.Message);
            }
        }

        private void btn1x_Click(object sender, EventArgs e)
        {
            try
            {
                double a = Convert.ToDouble(txtResult.Text);
                a = 1 / a;
                txtResult.Text = a.ToString();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка: " + ex.Message);
            }
        }

        private void btnln_Click(object sender, EventArgs e)
        {
            try
            {
                double ln = Convert.ToDouble(txtResult.Text);
                ln = Math.Log(ln);
                txtResult.Text = ln.ToString();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка: " + ex.Message);
            }
        }

        private void btnFac_Click(object sender, EventArgs e) 
        {
            try
            {
                int num = Convert.ToInt32(txtResult.Text);
                BigInteger a = Fac(num);
                txtResult.Text = a.ToString();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка: " + ex.Message);
            }
        }

        private BigInteger Fac(int number)
        {
            BigInteger fact = 1;
            for (int i = 2; i <= number; i++)
            {
                fact *= i;
            }
            return fact;
        }

        private void btnDec_Click(object sender, EventArgs e)
        {
            try
            {
                double dec = Convert.ToDouble(txtResult.Text);
                int i1 = Convert.ToInt32(dec);
                txtResult.Text = i1.ToString();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка: " + ex.Message);
            }
        }

        private void btnBin_Click(object sender, EventArgs e)
        {
            try
            {
                int a = int.Parse(txtResult.Text);
                txtResult.Text = Convert.ToString(a, 2);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка: " + ex.Message);
            }
        }

        private void btnHex_Click(object sender, EventArgs e)
        {
            try
            {
                int a = int.Parse(txtResult.Text);
                txtResult.Text = Convert.ToString(a, 16);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка: " + ex.Message);
            }
        }

        private void btnOct_Click(object sender, EventArgs e)
        {
            try
            {
                int a = int.Parse(txtResult.Text);
                txtResult.Text = Convert.ToString(a, 8);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка: " + ex.Message);
            }
        }

        private void statisticsFunctionsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Width = 630;
            this.Height = 800;
            txtResult.Width = 592;
        }

        private async void button1_Click(object sender, EventArgs e)
        {
            // Получение данных из текстовых полей
            List<double> data1, data2;
            try
            {
                data1 = textBox1.Text.Split(';').Select(double.Parse).ToList();
                data2 = textBox2.Text.Split(';').Select(double.Parse).ToList();
            }
            catch (FormatException)
            {
                MessageBox.Show("Некорректный ввод в текстовом поле. Пожалуйста, введите числа, разделенные ';'.");
                return;
            }

            // Начало измерения времени
            //Stopwatch stopwatch = Stopwatch.StartNew();

            // Вычисление статистических значений
            double mean1 = await MeanAsync(data1);
            double median1 = await MedianAsync(data1);
            double stdDev1 = await StandardDeviationAsync(data1);
            double variance1 = await VarianceAsync(data1);
            double correlation = await PearsonCorrelationAsync(data1, data2);

            // Остановка измерения времени
            //stopwatch.Stop();
            //TimeSpan timeElapsed = stopwatch.Elapsed;

            // Вывод результатов
            textBox3.Text = $"Среднее: {mean1}{Environment.NewLine}Медиана: {median1}{Environment.NewLine}" +
            $"Стандартное отклонение: {stdDev1}{Environment.NewLine}Дисперсия: {variance1}{Environment.NewLine}" +
            $"Коэффициент корреляции Пирсона: {correlation}{Environment.NewLine}";
            //+ $"Время выполнения: {timeElapsed.TotalMilliseconds} миллисекунд";
        }


        public async Task<double> MeanAsync(List<double> data)
        {
            return await Task.Run(() => data.Sum() / data.Count);
        }
        public async Task<double> MedianAsync(List<double> data)
        {
            return await Task.Run(() =>
            {
                int count = data.Count;
                data.Sort();

                if (count % 2 == 0)
                {
                    return (data[count / 2 - 1] + data[count / 2]) / 2;
                }
                else
                {
                    return data[count / 2];
                }
            });
        }

        public async Task<double> StandardDeviationAsync(List<double> data)
        {
            return await Task.Run(() =>
            {
                double mean = MeanAsync(data).Result;
                double sum = data.Sum(d => Math.Pow(d - mean, 2));
                return Math.Sqrt(sum / (data.Count - 1));
            });
        }
        public async Task<double> PearsonCorrelationAsync(List<double> xs, List<double> ys)
        {
            return await Task.Run(() =>
            {
                int count = xs.Count;
                double xMean = MeanAsync(xs).Result;
                double yMean = MeanAsync(ys).Result;

                double sumProduct = 0;
                double sumXSq = 0;
                double sumYSq = 0;

                for (int i = 0; i < count; i++)
                {
                    double x = xs[i] - xMean;
                    double y = ys[i] - yMean;

                    sumProduct += x * y;
                    sumXSq += x * x;
                    sumYSq += y * y;
                }

                return sumProduct / Math.Sqrt(sumXSq * sumYSq);
            });
        }
        public async Task<double> VarianceAsync(List<double> data)
        {
            return await Task.Run(() =>
            {
                double mean = MeanAsync(data).Result;
                double sum = data.Sum(d => Math.Pow(d - mean, 2));
                return sum / (data.Count - 1);
            });
        }

        // Генерация случайного количества чисел
        private void buttonGenerate_Click(object sender, EventArgs e)
        {
            Random random = new Random();
            int count;
            try
            {
                count = int.Parse(textBoxCount.Text);
            }
            catch (FormatException)
            {
                MessageBox.Show("Некорректный ввод в поле количества. Пожалуйста, введите целое число.");
                return;
            }
            List<double> data1 = new List<double>();
            List<double> data2 = new List<double>();
            for (int i = 0; i < count; i++)
            {
                data1.Add(Math.Round(random.NextDouble() * 100, 0)); // Генерирует случайное число от 0 до 100 и округляет 
                data2.Add(Math.Round(random.NextDouble() * 100, 0)); // Генерирует случайное число от 0 до 100 и округляет 
            }

            // Заполнение текстовых полей сгенерированными числами
            textBox1.Text = string.Join(";", data1);
            textBox2.Text = string.Join(";", data2);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.Width = 318;
            this.Height = 385;
            txtResult.Width = 280;
        }
    }
}
