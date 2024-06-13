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


void MainWindow::on_exBMin_clicked()
{
    int val = heap.extractMin();
    ui->exMin->setText(QString::number(val));
}


void MainWindow::on_getBMin_clicked()
{
    int val = heap.getMin();
    ui->getMin->setText(QString::number(val));
}

void MainWindow::on_insBMin_clicked()
{
    heap.insert(ui->insMin->text().toInt());
}


void MainWindow::on_prBMin_clicked()
{
    ui->prMin->setText(heap.printMinHeap());
}

void MainWindow::on_exBMax_clicked()
{
    int val = heap.extractMax();
    ui->exMax->setText(QString::number(val));
}


void MainWindow::on_getBMax_clicked()
{
    int val = heap.getMax();
    ui->getMax->setText(QString::number(val));
}

void MainWindow::on_insBMax_clicked()
{
    heap.insert(ui->insMax->text().toInt());
}


void MainWindow::on_prBMax_clicked()
{
    ui->prMax->setText(heap.printMaxHeap());
}

