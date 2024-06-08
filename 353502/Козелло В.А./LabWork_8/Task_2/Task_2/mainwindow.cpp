#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    heap.insert(52);
    heap.insert(52);
    heap.insert(8);
    heap.insert(7);
    heap.insert(18);
    heap.insert(2);
    heap.insert(1);
    qDebug() << heap.getHeap();
    qDebug() << heap.extractMin();
    qDebug() << heap.getHeap();
}

MainWindow::~MainWindow()
{
    delete ui;
}

