#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    test2[0] = "aa";
    qDebug() << test2.size();
    for (int i = 2; i < 10; i++) {
        //test[i] = i;
        test.insert(i);
        test1[i] = i;
        //      qDebug() << i << " " << test[i];
    }
    qDebug() << test.size();
    for (int i = 0; i < 11; i++) {
        qDebug() << test.contains(i);
    }
    for (int i = 0; i < 11; i++) {
        qDebug() << test1[i];
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
