#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <vector> // Для std::vector
#include <algorithm> // Для std::minmax_element

// Структура bucket
struct bucket {
    size_t start = 0;
    size_t sz = 0;
    size_t cur = 0;
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString styleSheet = R"(


    QPushButton {
        background-color: #007BFF; /* Синий цвет */
        border: none;
        color: #FFFFFF;

    }
QTextEdit {
    background-color: #2E2E4F;

}
QListWidget {
    background-color: #0D1B2A; /* Темно-синий цвет, напоминающий глубины космоса */

}

/* Стиль для главного окна */
MainWindow {
    background-color: #040F1A; /* Еще более темный оттенок синего, похожий на бесконечную глубину космоса */
}
QLineEdit {
    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1,
                                 stop: 0 #0D1B2A, stop: 1 #050A30); /* Градиент от #0D1B2A до #050A30 */
    border: 1px solid #2E2E4F; /* Фиолетовая рамка */
    color: white; /* Белый текст для контраста */
}

    QPushButton:hover {
        background-color: #0056b3; /* Темно-синий цвет при наведении */
    }


)";
    this->setStyleSheet(styleSheet);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_interpolation_Sort_clicked()
{
    ui->textEdit->clear();
    QString text = ui->lineEdit->text();
    QStringList numbers = text.split(' ', Qt::SkipEmptyParts);

    // Проверка и преобразование строк в целые числа
    std::vector<int> array;
    for (const QString& number : numbers) {
        bool ok;
        int value = number.toInt(&ok);
        if (ok) {
            array.push_back(value);
        } else {
            QMessageBox::warning(this, "Ошибка", "Введите только целые числа!");
            return;
        }
    }

    // Вызов сортировки
    _interpSort(array, 0, array.size());

    // Сохранение отсортированного массива
    sortedArray = array;

    // Вывод отсортированного массива
    printArray(sortedArray);


}

void MainWindow::printArray(const std::vector<int>& arr) {
    QString arrayStr = "Массив: ";
    for (int num : arr) {
        arrayStr += QString::number(num) + " ";
    }
    ui->textEdit->append(arrayStr);
}

void MainWindow::_interpSort(std::vector<int>& arr, size_t beg, size_t end) {
    // Проверка базового случая: если длина части массива меньше или равна 1, то она уже отсортирована.
    if(end - beg <= 1){
        return;
    }

    // Шаг 1: Подготовка временных структур

    // Вычисление размера части массива, которую мы собираемся сортировать.
    auto sz = end - beg;

    // Вектор для хранения интерполяционных значений элементов.
    std::vector<long> indices(sz);

    // Создание временного вектора, который является копией части массива для сортировки.
    std::vector<int> tmp_vect(arr.begin() + beg, arr.begin() + end);

    // Вектор корзин для сортировки элементов.
    std::vector<bucket> buckets;

    // Шаг 2: Нахождение минимального и максимального элементов

    // Нахождение итераторов на минимальный и максимальный элементы временного вектора.
    auto minmax = std::minmax_element(tmp_vect.begin(), tmp_vect.end());

    // Вычисление индексов минимального и максимального элементов.
    size_t min = minmax.first - tmp_vect.begin();
    size_t max = minmax.second - tmp_vect.begin();

    // Шаг 3: Разбиение элементов на корзины

    for(int i = 0; i < sz; ++i){
        // Проверка на деление на ноль (избегаем деления на ноль).
        if(tmp_vect[max] - tmp_vect[min] == 0){
            return;
        }

        // Вычисление интерполяционного значения для текущего элемента и определение номера соответствующей корзины.
        auto ind = (sz - 1) * (tmp_vect[i] - tmp_vect[min]) / (tmp_vect[max] - tmp_vect[min]);
        indices[i] = ind;

        // Если количество корзин меньше, чем текущий индекс, увеличиваем размер вектора корзин.
        if(buckets.size() <= ind){
            buckets.resize(ind+1);
        }

        // Увеличиваем количество элементов в текущей корзине.
        buckets[ind].sz++;
    }

    // Шаг 4: Установка начальных индексов для корзин

    // Вычисляем начальный индекс для каждой корзины.
    size_t buck_ind = 0;
    for(int i = 0; i < buckets.size(); ++i){
        buckets[i].start = buck_ind;
        buck_ind += buckets[i].sz;
    }

    // Шаг 5: Размещение элементов в соответствующих корзинах

    // Помещаем каждый элемент в соответствующую корзину в исходном массиве, а затем увеличиваем счетчик текущего элемента в этой корзине.
    for(int i = 0; i < sz; ++i){
        auto buck_ind = indices[i];
        auto vect_ind = buckets[buck_ind].start + buckets[buck_ind].cur;
        arr[beg + vect_ind] = tmp_vect[i];
        buckets[buck_ind].cur++;

        // Вывод массива после каждого шага сортировки
        printArray(arr);
    }

    // Шаг 6: Рекурсивный вызов _interpSort для каждой корзины

    // Рекурсивно вызываем _interpSort для каждой непустой корзины.
    for(int i = 0; i < buckets.size(); ++i){
        _interpSort(arr, beg + buckets[i].start, beg + buckets[i].start + buckets[i].sz);
    }
}

int MainWindow:: binpow(int digit, int power, int mod) {
    int res = 1;
    while (power > 0) {
        if (power & 1) {
            res = (res * digit) % mod;
        }
        digit = (digit * digit) % mod;
        power >>= 1;
    }
    return res;
}

void MainWindow::on_binpow_clicked()
{
    QString text = ui->lineEdit_2->text();
    int val = text.toInt();

    int ind = binarySearch(sortedArray, val);

    if (ind != -1) {
        ui->textEdit->append("Индекс найденного элемента: " + QString::number(ind));

        // Вызов функции бинарного возведения в степень
        int mod = sortedArray.size(); // Модуль числа равен длине массива
        int result = binpow(ind, mod, val);
        ui->textEdit->append("Результат бинарного возведения в степень: " + QString::number(result));
    } else {
        QMessageBox::warning(this, "Информация", "Элемент не найден");
    }
}

int MainWindow::binarySearch(const std::vector<int>& arr, int digit) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == digit)
            return mid;
        else if (arr[mid] < digit)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}
