#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <magicnumbers.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    size(SIZE),
    arr(new int[size]),
    ui(new Ui::MainWindow),
    sorter (new SortThread(arr, size))
{
    ui->setupUi(this);
    sort_visualizer = new SortVisualizer(ui->graphicsView);
    connect(sorter, SIGNAL(arrayUpdated(int*, int)), sort_visualizer, SLOT(updateArray(int*, int)), Qt::QueuedConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete[] arr;
}

void MainWindow::skip(int ms) {
    QEventLoop loop;
    QTimer::singleShot(ms, &loop, &QEventLoop::quit);
    loop.exec();
}



void MainWindow::on_merge_sort_clicked()
{
    sort_visualizer->clearScene();
    sorter->setSortingAlgorithm(SortThread::MergeSort);
    sort_visualizer->visualizeSort(arr,size);
    sorter->start();
}


void MainWindow::on_quick_sort_clicked()
{
    sort_visualizer->clearScene();
    sorter->setSortingAlgorithm(SortThread::QuickSort);
    sort_visualizer->visualizeSort(arr,size);
    sorter->start();
}


void MainWindow::on_heap_sort_clicked()
{
    sort_visualizer->clearScene();
    sorter->setSortingAlgorithm(SortThread::HeapSort);
    sort_visualizer->visualizeSort(arr,size);
    sorter->start();
}


void MainWindow::on_interpolation_sort_clicked()
{
    sort_visualizer->clearScene();
    sorter->setSortingAlgorithm(SortThread::InterpolationSort);
    sort_visualizer->visualizeSort(arr,size);
    sorter->start();
}

void MainWindow::on_shuffle_clicked()
{
    sort_visualizer->clearScene();
    sort_visualizer->shuffle(arr,size);
    sort_visualizer->drawArray(arr, size);

}


void MainWindow::on_bin_search_clicked()
{
    int search = ui->spinBox->value();
    sort_visualizer->binarySearch(arr, size, search);
}


void MainWindow::on_interpolation_search_clicked()
{
    int search = ui->spinBox->value();
    sort_visualizer->interpolationSearch(arr, size, search);
}

