#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sorting.h"
#include "binsearch.h"
#include <QTime>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , arr(nullptr)
    , n(0)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete[] arr;
    delete ui;
}

void MainWindow::on_sortButton_clicked()
{
    n = ui->spinBox->value();
    arr = new int[n];

    // Заполнение массива случайными числами
    for(int i = 0; i < n; ++i) {
        arr[i] = qrand() % 100;
    }

    QTime timer;
    timer.start();

    // Сортировка кучей
    heapSort(arr, n);
    int heapSortTime = timer.elapsed();

    // Перезаполнение массива случайными числами
    for(int i = 0; i < n; ++i) {
        arr[i] = qrand() % 100;
    }

    timer.restart();

    // Быстрая сортировка
    quickSort(arr, 0, n - 1);
    int quickSortTime = timer.elapsed();

    // Перезаполнение массива случайными числами
    for(int i = 0; i < n; ++i) {
        arr[i] = qrand() % 100;
    }

    timer.restart();

    // Сортировка слиянием
    mergeSort(arr, 0, n - 1);
    int mergeSortTime = timer.elapsed();

    QString result = QString("Heap Sort: %1 ms\nQuick Sort: %2 ms\nMerge Sort: %3 ms")
                         .arg(heapSortTime)
                         .arg(quickSortTime)
                         .arg(mergeSortTime);

    ui->resultLabel->setText(result);
}

void MainWindow::on_searchButton_clicked()
{
    int digit = ui->searchSpinBox->value();
    int index = binSearch(arr, n, digit);
    QString result = index >= 0 ? QString("Found at index: %1").arg(index) : "Not Found";
    QMessageBox::information(this, "Search Result", result);
}
