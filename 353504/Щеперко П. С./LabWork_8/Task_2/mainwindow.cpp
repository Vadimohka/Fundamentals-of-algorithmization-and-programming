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

void MainWindow::printHeapAsArray(BinaryArrayHeap &heap)
{
    ui->listWidget->clear();
    for(int i = 0; i < heap.getSize(); i++) {
        ui->listWidget->addItem(QString::number(heap.getArray()[i]));
    }
}

void MainWindow::on_extractMaxPushButton_clicked()
{
    ui->listWidget->setCurrentRow(0);
    arrayBinHeap.extractMax();
    printHeapAsArray(arrayBinHeap);
}

void MainWindow::on_getMaxPushButton_clicked()
{
    ui->listWidget->setCurrentRow(0);
}

void MainWindow::on_insertPushButton_clicked()
{
    arrayBinHeap.insert(ui->valueSpinBox->value());
    printHeapAsArray(arrayBinHeap);
}

