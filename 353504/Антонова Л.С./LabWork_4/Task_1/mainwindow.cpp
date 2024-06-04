#include "mainwindow.h"
#include "ui_mainwindow.h"

QString MainWindow::vectorToString(const QVector<int> &arr) {
    QStringList list;
    for (int num : arr) {
        list << QString::number(num);
    }
    return list.join(", ");
}

void MainWindow::heapify(QVector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void MainWindow::heapSort(QVector<int> &arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int MainWindow::partition (QVector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void MainWindow::quickSort(QVector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void MainWindow::merge(QVector<int> &arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    QVector<int> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MainWindow::mergeSort(QVector<int> &arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int MainWindow::binsearch(QVector<int> &arr, int digit) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == digit)
            return m;
        if (arr[m] < digit)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}

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

void MainWindow::on_sortButton_clicked()
{
    QString input = ui->arrayInput->text();
    QStringList numbers = input.split(" ");
    QVector<int> arr;
    for (const QString &number : numbers) {
        arr.append(number.toInt());
    }

    QVector<int> arr_copy;
    QElapsedTimer timer;
    qint64 nanoSec;

    arr_copy = arr;
    timer.start();
    heapSort(arr_copy);
    nanoSec = timer.nsecsElapsed();
    ui->output->append("Heap sorted array: " + vectorToString(arr_copy));
    ui->output->append("Heap sort time: " + QString::number(nanoSec) + " ns");

    arr_copy = arr;
    timer.restart();
    quickSort(arr_copy, 0, arr_copy.size()-1);
    nanoSec = timer.nsecsElapsed();
    ui->output->append("Quick sorted array: " + vectorToString(arr_copy));
    ui->output->append("Quick sort time: " + QString::number(nanoSec) + " ns");

    arr_copy = arr;
    timer.restart();
    mergeSort(arr_copy, 0, arr_copy.size()-1);
    nanoSec = timer.nsecsElapsed();
    ui->output->append("Merge sorted array: " + vectorToString(arr_copy));
    ui->output->append("Merge sort time: " + QString::number(nanoSec) + " ns");
}

void MainWindow::on_searchButton_clicked()
{
    QString input = ui->arrayInput->text();
    QStringList numbers = input.split(" ");
    QVector<int> arr;
    for (const QString &number : numbers) {
        arr.append(number.toInt());
    }
    quickSort(arr, 0, arr.size() - 1);

    int digit = ui->digitInput->text().toInt();
    int index = binsearch(arr, digit);
    ui->output->append("Index of " + QString::number(digit) + " is " + QString::number(index));
}
