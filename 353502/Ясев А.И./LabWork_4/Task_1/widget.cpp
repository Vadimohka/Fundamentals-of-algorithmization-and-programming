#include "widget.h"
#include "ui_widget.h"
#include "dialog.h"
#include <random>
#include <QDebug>
#include <QElapsedTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    std::default_random_engine generator;

    for (int i = 0; i < 10000; ++i) {
        // генерируем случайное целое число от 0 до 99
        int randomNumber = std::uniform_int_distribution<>(-100000, 100000)(generator);

        vector.push_back(randomNumber);
    }
    update();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::update()
{
    ui->listWidget->clear();
    foreach (int i, vector) {
        ui->listWidget->addItem(QString::number(i));
    }
}

void Widget::on_clearPushButton_clicked()
{
    vector.clear();
    update();
}


void Widget::on_addPushButton_clicked()
{
    Dialog dialog1;
    dialog1.setWindowTitle("Enter count");
    if(!dialog1.exec())
        return;
    int max = dialog1.getInt();
    Dialog dialog2;
    dialog2.setWindowTitle("Enter minimum");
    if(!dialog2.exec())
        return;
    int left = dialog2.getInt();
    Dialog dialog3;
    dialog3.setWindowTitle("Enter maximum");
    if(!dialog3.exec())
        return;
    int right = dialog3.getInt();
    vector.reserve(max); // резервируем память для 100 элементов

    // создаём генератор случайных чисел
    std::default_random_engine generator;

    for (int i = 0; i < max; ++i) {
        // генерируем случайное целое число от 0 до 99
        int randomNumber = std::uniform_int_distribution<>(left, right)(generator);

        vector.push_back(randomNumber);
    }
    update();
}

void Widget::quickSort(QVector<int>& arr, int left, int right) {
    if (left >= right) return;

    int pivot = arr[right]; // выбираем опорный элемент
    int i = left;
    for (int j = left; j <= right - 1; ++j) {
        if (arr[j] <= pivot) { // если элемент меньше или равен опорному
            std::swap(arr[i], arr[j]); // меняем элементы местами
            ++i;
        }
    }
    std::swap(arr[i], arr[right]); // ставим опорный элемент на свое место

    quickSort(arr, left, i - 1); // рекурсивно сортируем левую часть
    quickSort(arr, i + 1, right); // рекурсивно сортируем правую часть
}

// Функция сортировки слиянием
void Widget::mergeSort(QVector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2; // находим середину массива
    mergeSort(arr, left, mid); // рекурсивно сортируем левую часть
    mergeSort(arr, mid + 1, right); // рекурсивно сортируем правую часть

    // объединяем отсортированные части
    std::vector<int> left_sorted( mid - left + 1);
    std::copy(arr.begin() + left, arr.begin() + mid + 1, left_sorted.begin());
    std::vector<int> right_sorted( right - mid);
    std::copy(arr.begin() + mid + 1, arr.begin() + right + 1, right_sorted.begin());

    int i = 0, j = 0;
    for (int k = left; k <= right; ++k) {
        if (i == left_sorted.size() || (j < right_sorted.size() && left_sorted[i] > right_sorted[j])) {
            arr[k] = right_sorted[j];
            ++j;
        } else {
            arr[k] = left_sorted[i];
            ++i;
        }
    }
}


void Widget::heapify(QVector<int>& nums, int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (left < n && nums[left] > nums[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && nums[right] > nums[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        std::swap(nums[i], nums[largest]);

        // Recursively heapify the sub-tree
        heapify(nums, n, largest);
    }
}

void Widget::heapSort(QVector<int>& nums) {
    int n = nums.size();

    // Build a maxheap.
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(nums, n, i);

    // One by one extract an element from heap and place it at the end
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        std::swap(nums[0], nums[i]);

        // call max heapify on the reduced heap
        heapify(nums, i, 0);
    }
}

void Widget::shuffle(QVector<int> &vector)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int i = 0; i < vector.size(); ++i) {
        std::uniform_int_distribution<> dist(0, i);
        int j = dist(gen);
        if (i != j) {
            std::swap(vector[i], vector[j]);
        }
    }
}

int Widget::binarySearch(QVector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;  // target not found
}


void Widget::on_pushButton_clicked()
{
    QElapsedTimer timer;
    timer.start();
    if(ui->quickRadioButton->isChecked()){
        quickSort(vector, 0, vector.size()-1);
    }else if(ui->mergeRadioButton->isChecked()){
        mergeSort(vector, 0, vector.size()-1);
    }
    else{
        heapSort(vector);
    }
    QString execTime = QString::number(timer.elapsed());
    update();
    ui->timeLabel->setText(execTime);
}


void Widget::on_shufflePushButton_clicked()
{
    shuffle(vector);
    update();
}


void Widget::on_searchButton_clicked()
{
    Dialog dialog1;
    dialog1.setWindowTitle("Enter number to search");
    if(!dialog1.exec())
        return;
    int search = dialog1.getInt();
    int result = binarySearch(vector, search);
    ui->searchLabel->setText(QString::number(result));
}

