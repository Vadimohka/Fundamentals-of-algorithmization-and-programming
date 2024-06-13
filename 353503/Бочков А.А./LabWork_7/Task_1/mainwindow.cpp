#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);
    for (int i = 0; i < 10; i++) {
        int x = rand() % 1000 - 500;
        deq.push_back(x);
        qDebug() << deq[i];
    }
    qDebug() << "";
    qDebug() << deq.size();
    qDebug() << "";
    for (size_t i = 0; i < deq.size(); i++) {
        if (deq[i] >= 0) {
            newdeq.push_back(deq[i]);
        }
    }
    for (int i = 0; i < 5; i++) {
        deq.pop_back();
    }
    for (int i = 0; i < 5; i++) {
        deq.pop_front();
    }
    /*qDebug() << "";
    qDebug() << deq.size();*/
    for (int i = 0; i < newdeq.size(); i++) {
        deq.push_back(newdeq[i]);
        qDebug() << deq[i];
    }
    qDebug() << "";
    qDebug() << deq.size();
}

MainWindow::~MainWindow()
{
    delete ui;
}
