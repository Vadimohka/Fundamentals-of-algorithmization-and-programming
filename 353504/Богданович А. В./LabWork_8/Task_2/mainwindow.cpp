#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>

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

void MainWindow::printHeapAsArray(BinaryHeap<int> &heap)
{
    ui->listWidget->clear();

    for(int i = 0; i < heap.getSize(); i++)
    {
        ui->listWidget->addItem(QString::number(heap.getArray()[i]));
    }
}

void MainWindow::printHeapAsList(BinaryHeapByList<int> &h)
{
    ui->listWidget->clear();

    for(int i = 0; i < h.getList().size; i++)
    {
        ui->listWidget->addItem(QString::number(h.getList()[i]));
    }
}

void MainWindow::on_insertButton_clicked()
{
    if (currentBH == 0) {
        h2.insert(ui->spinBox->value());
        printHeapAsArray(h2);
    } else {
        h.insert(ui->spinBox->value());
        printHeapAsList(h);
    }
}


void MainWindow::on_extractMax_clicked()
{
    ui->listWidget->setCurrentRow(0);
    if (currentBH = 0) {
        h2.extractMax();
        printHeapAsArray(h2);
    } else {
        h.extractMax();
        printHeapAsList(h);
    }

}


void MainWindow::on_getMaxButton_clicked()
{
    ui->listWidget->setCurrentRow(0);
}


void MainWindow::on_radioButton_2_clicked()
{
    ui->listWidget->clear();
    currentBH = 1;
    printHeapAsList(h);
}


void MainWindow::on_radioButton_clicked()
{
    ui->listWidget->clear();
    currentBH = 0;
    printHeapAsArray(h2);
}

