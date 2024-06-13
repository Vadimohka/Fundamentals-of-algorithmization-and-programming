#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , heap(100)
{
    ui->setupUi(this);
    int b  = 10;
    heap.push(b);
    heap.push(b + 1);
    heap.push(132);
    heap.push(212345);

    bheap.push(1234);
    bheap.push(1234567);
    bheap.push(1);
    bheap.push(2);
    bheap.pop();
    int value = heap.top();
    qDebug() << value << bheap.top();
}

MainWindow::~MainWindow()
{
    delete ui;
}
