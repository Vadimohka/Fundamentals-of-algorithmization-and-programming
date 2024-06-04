#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString v, a = "([,][+-]?[0-9]{1,16})";
    v.insert(0, a.repeated(1200));
    ui->lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[-+]?[0-9]{1,16}" + v),this));
    ui->lineEdit_2->setValidator(new QRegularExpressionValidator(QRegularExpression("[-+]?[0-9]{1,16}"),this));
    timer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::HeapSort(QVector<long long> &arr)
{
    long long size = arr.size();
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
    for (int i = size - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void MainWindow::heapify(QVector<long long> &arr, long long size, long long cor)
{
    long long ind = cor;
    long long l = 2 * cor + 1;
    long long r = 2 * cor + 2;
    if (l < size && arr[l] > arr[ind]) ind = l;
    if (r < size && arr[r] > arr[ind]) ind = r;
    if (ind != cor) {
        std::swap(arr[cor], arr[ind]);
        heapify(arr, size, ind);
    }
}

long long MainWindow::partition(QVector<long long> &arr, long long low, long long high) {

    long long pivot = arr[high];
    long long i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }
    std::swap(arr[i], arr[high]);
    return i;
}

void MainWindow::QuickSort(QVector<long long> &arr, long long low, long long high) {
    if (low < high) {
        long long pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

void MainWindow::merge(QVector<long long> &arr, long long l, long long centr, long long r) {
    long long size1 = centr - l + 1;
    long long size2 = r - centr;
    long long arr1[size1], arr2[size2];

    for (int i = 0; i < size1; i++) arr1[i] = arr[l + i];
    for (int j = 0; j < size2; j++) arr2[j] = arr[centr + 1 + j];

    long long ind_arr1 = 0, ind_arr2 = 0, ind_arr = l;
    while (ind_arr1 < size1 && ind_arr2 < size2) {
        if (arr1[ind_arr1] <= arr2[ind_arr2]) arr[ind_arr++] = arr1[ind_arr1++];
        else arr[ind_arr++] = arr2[ind_arr2++];
    }
    while (ind_arr1 < size1) arr[ind_arr++] = arr1[ind_arr1++];
    while (ind_arr2 < size2) arr[ind_arr++] = arr2[ind_arr2++];
}
void MainWindow::MergeSort(QVector<long long> &arr, long long l, long long r) {
    if (l < r) {
        long long m = l + (r - l) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

long long MainWindow::BinarySearch(const QVector<long long> &arr, long long target)
{
    long long left = 0;
    long long right = arr.size() - 1;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}


void MainWindow::on_pushButton_clicked()
{
    if (ui -> lineEdit -> text() != input){
    numbers.clear();
    numbersHeapSort.clear();
    numbersMergeSort.clear();
    numbersQuickSort.clear();
    input = ui -> lineEdit -> text();
    QStringList numbersAsStrings = input.split(",");
    for(const QString& str : numbersAsStrings) {
        long long num = str.toLongLong();
        numbers.append(num);
    }
    numbersHeapSort = numbers;
    numbersQuickSort = numbers;
    numbersMergeSort = numbers;
    QString heap_sort, quick_sort, merge_sort;
    timer.restart();
    HeapSort(numbersHeapSort);
    long long time_heap_sort = timer.nsecsElapsed();
    timer.restart();
    QuickSort(numbersQuickSort, 0, numbersQuickSort.size() - 1);
    long long time_quick_sort = timer.nsecsElapsed();
    timer.restart();
    MergeSort(numbersMergeSort, 0, numbersMergeSort.size() - 1);
    long long time_merge_sort = timer.nsecsElapsed();
    for (int i = 0; i < numbers.size(); ++i) {
        heap_sort += QString::number(numbersHeapSort[i]);
        quick_sort += QString::number(numbersQuickSort[i]);
        merge_sort += QString::number(numbersMergeSort[i]);
        if (i < numbersHeapSort.size() - 1) {
            heap_sort += ",";
            quick_sort += ",";
            merge_sort += ",";
        }
    }
    ui -> label_2 -> setText("Heap sort [" + heap_sort + "]");
    ui -> label_3 -> setText("Quick sort [" + quick_sort + "]");
    ui -> label_4 -> setText("Merge sort [" + merge_sort + "]");
    ui -> label_6 -> setText("Время выполнения Heap sort: " + QString::number(time_heap_sort) + "нс");
    ui -> label_7 -> setText("Время выполнения Quick sort: " + QString::number(time_quick_sort) + " нс");
    ui -> label_8 -> setText("Время выполнения Merge sort: " + QString::number(time_merge_sort) + " нс");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    close();
}



void MainWindow::on_pushButton_3_clicked()
{
    long long namber = (ui -> lineEdit_2 -> text()).toLongLong();
    ui -> label_5 -> setText(QString::number(BinarySearch(numbersHeapSort, namber)));
}

