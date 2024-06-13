#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(geometry().size());

    ui->spinBox->setMinimum(1);
    ui->spinBox->setMaximum(100000);
    ui->elementSpinBox->setMinimum(1);
    ui->elementSpinBox->setMaximum(100);
    ui->findButton->setEnabled(false);

    connect(ui->sortButton, &QPushButton::clicked, this, &MainWindow::sort_3_times);
    connect(ui->findButton, &QPushButton::clicked, this, &MainWindow::findElement);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sort_3_times()
{
    int sz = ui->spinBox->value();
    v0.resize(sz);

    for (int i = 0; i < sz; ++i)
    {
        v0[i] = 1 + rand() % 100;
    }

    v = v0;
    timer.start();
    Sort::HeapSort(v, sz);
    ui->heapSort->setText("Time: " + QString::number(timer.elapsed()) + " ms");

    v = v0;
    Sort::QuickSort(v, 0, sz-1);
    ui->quickSort->setText("Time: " + QString::number(timer.elapsed()) + " ms");

    v = v0;
    timer.start();
    Sort::MergeSort(v, 0, sz-1);
    ui->mergeSort->setText("Time: " + QString::number(timer.elapsed()) + " ms");

    ui->findButton->setEnabled(true);
}


void MainWindow::findElement()
{
    int element = ui->elementSpinBox->value();
    timer.start();
    int ind = Binsearch::BinSearch(v, element);
    ui->binsearchTimeBrowser->setText("Time: " + QString::number(timer.elapsed()) + " ms");
    ui->answerBrowser->setText("Index of element " + QString::number(element) + " = " + QString::number(ind));
}
