#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QElapsedTimer;
    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

////////////////MERGE_SORT

void MainWindow::mergeSort(QList<int> & list)
{
    timer->restart();
    mergeSort(list, 0, list.length() - 1);
    double time = timer->elapsed();
    ui->MergeSortTimeLabel->setText(QString::number(time));
}

void MainWindow::mergeSort(QList<int> & array, int left, int right)
{
    if (left >= right)
        return;
    int middle = left + (right - left) / 2;
    mergeSort(array, left, middle);
    mergeSort(array, middle + 1, right);
    merge(array, left, middle, right);
}

void MainWindow::merge(QList<int> & array, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    QList<int> L, R;

    for (int i = 0; i < n1; i++)
        L.append(array[left + i]);
    for (int j = 0; j < n2; j++)
        R.append(array[middle + 1 + j]);

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

}

//////////////////QUICK_SORT

void MainWindow::quickSort(QList<int> & array)
{
    timer->restart();
    quickSort(array, 0, array.size() - 1);
    double time = timer->elapsed();
    ui->QuickSortTimeLabel->setText(QString::number(time));
}


void MainWindow::quickSort(QList<int> & array, int low, int high)
{
    if (low < high) {
        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int MainWindow::partition(QList<int> &array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            array.swapItemsAt(i, j);
        }
    }

    array.swapItemsAt(i + 1, high);
    return (i + 1);
}

//////////////////HEAP_SORT

void MainWindow::heapSort(QList<int> & array)
{
    timer->restart();
    int n = array.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    for (int i = n - 1; i >= 0; i--) {
        array.swapItemsAt(0, i);
        heapify(array, i, 0);
    }
    double time = timer->elapsed();
    ui->HeapSortTimeLabel->setText(QString::number(time));
}

void MainWindow::heapify(QList<int> &array, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i) {
        array.swapItemsAt(i, largest);
        heapify(array, n, largest);
    }
}

///////////////////OTHER

void MainWindow::on_sortButton_clicked()
{
    QStringList strList = ui->arrayEdit->text().split(u' ');
    list.clear();
    for (auto str : strList){
        list.append(str.toLongLong());
    }
    mergeSort(list);
    QString strToOutput;
    for (auto el : list){
        strToOutput += QString::number(el) + " ";
    }
    ui->arrayOutput->setText(strToOutput);
}


void MainWindow::on_sortButton_2_clicked()
{
    QStringList strList = ui->arrayEdit->text().split(u' ');
    list.clear();
    for (auto str : strList){
        list.append(str.toLongLong());
    }
    quickSort(list);
    QString strToOutput;
    for (auto el : list){
        strToOutput += QString::number(el) + " ";
    }
    ui->arrayOutput->setText(strToOutput);
}


void MainWindow::on_sortButton_3_clicked()
{
    QStringList strList = ui->arrayEdit->text().split(u' ');
    list.clear();
    for (auto str : strList){
        list.append(str.toLongLong());
    }
    heapSort(list);
    QString strToOutput;
    for (auto el : list){
        strToOutput += QString::number(el) + " ";
    }
    ui->arrayOutput->setText(strToOutput);
}



int MainWindow::binSeacrh(QList<int> & array, const int target)
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

void MainWindow::on_findButton_clicked()
{
    ui->foundID->setText("ID: " + QString::number(binSeacrh(list, ui->findElemenEdit->text().toInt())));
}

