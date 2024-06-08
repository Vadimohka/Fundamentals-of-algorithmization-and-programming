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

void MainWindow::on_insertButton_clicked()
{
    h2.insert(ui->spinBox->value());
    printHeapAsArray(h2);
}


void MainWindow::on_extractMax_clicked()
{
    ui->listWidget->setCurrentRow(0);


    QEventLoop loop;
    QTimer::singleShot(1000, &loop, &QEventLoop::quit);
    loop.exec();

    h2.extractMax();
    printHeapAsArray(h2);
}


void MainWindow::on_getMaxButton_clicked()
{
    ui->listWidget->setCurrentRow(0);
}

