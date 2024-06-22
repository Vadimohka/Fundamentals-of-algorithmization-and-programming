#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    BinaryHeap<int> heap;

    heap.add(5);
    heap.add(1);
    heap.add(6);
    heap.add(7);
    heap.add(9);
    heap.add(2);
    heap.add(2);
    heap.add(4);
    heap.add(10);

    while (!heap.empty())
    {
        qDebug() << heap.top();
        heap.pop();
    }

    qDebug() << "______";

    MLBinaryHeap<int> heap2;

    heap2.push(5);
    heap2.push(1);
    heap2.push(6);
    heap2.push(7);
    heap2.push(9);
    heap2.push(2);
    heap2.push(2);
    heap2.push(4);
    heap2.push(10);

    while (!heap2.empty())
    {
        qDebug() << heap2.top();
        heap2.pop();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
