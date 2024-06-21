#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::interpolationSort(std::vector<int>& arr)
{
    int start = 0; // Индекс начала текущего диапазона
    int size = arr.size(); // Размер массива
    int min = arr[0]; // Минимальное значение массива
    int max = arr[0]; // Максимальное значение массива

    // Находим минимум и максимум в массиве
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i]; // Обновляем минимум
        }
        else if (arr[i] > max) {
            max = arr[i]; // Обновляем максимум
        }
    }

    if (min != max) { // Проверяем, что минимум не равен максимуму (это означает, что массив не отсортирован)
        std::vector<std::vector<int>> bucket(size); // Создаем вектор векторов (корзин)

        // Распределяем элементы по корзинам (бакетам) на основе интерполяции
        for (int i = 0; i < size; i++) {
            // Используем интерполяцию для определения корзины, в которую поместить элемент
            int interpolation = static_cast<int>((static_cast<double>(arr[i] - min) / (max - min)) * (size - 1));
            bucket[interpolation].push_back(arr[i]); // Добавляем элемент в соответствующую корзину
            listOutput(arr);
        }

        start = 0; // Сбрасываем индекс начала текущего диапазона для объединения

        // Сортируем каждую корзину (рекурсивно вызываем интерполяционную сортировку)
        for (int i = 0; i < size; i++) {
            if (bucket[i].size() > 1) {
                interpolationSort(bucket[i]); // Рекурсивно сортируем корзину
            }

            // Объединяем отсортированные элементы обратно в основной массив
            for (int j : bucket[i]) {
                arr[start++] = j; // Добавляем элемент из корзины в основной массив
                listOutput(arr);
            }
        }
    }
}

void MainWindow::listOutput(std::vector<int> & array)
{
    for (auto el : array)
    {
        ui->arrayOutput->insertPlainText(QString::number(el) + " ");
        qDebug() << el << " ";
    }
    qDebug() << '\n';
    ui->arrayOutput->append("\n");
}

void MainWindow::on_pushButton_clicked()
{
    QStringList strList = ui->arraInput->text().split(u' ');
    list.clear();
    for (const auto& el : strList)
    {
        list.push_back((el.toInt()));
    }
    qDebug() << list.size();
    interpolationSort(list);
}

long long  MainWindow::binpow(long long a, long long b, long long mod) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2, mod) % mod;
    res = (res * res) % mod;
    if (b % 2 == 1) {
        res = (res * a) % mod;
    }
    return res;
}

void MainWindow::on_calculateButton_clicked()
{
    long long ind = binSeacrh(list, ui->element->text().toInt());
    long long power = ui->power->text().toInt();
    long long mod = ui->module->text().toInt();
    ui->result->setText(QString::number(binpow(ind, power, mod)));
}

int MainWindow::binSeacrh(std::vector<int> & array, const int target)
{
    int left = 0;
    int right = array.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] == target)
        {
            return mid;
        }
        if (array[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}
