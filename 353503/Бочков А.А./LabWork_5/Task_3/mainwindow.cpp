#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    b = 53;
    b = b | 15;
    qDebug() << b.to_string() << b.to_ullong() << b.to_ulong();
    for (int i = 0; i < 10; i++) {
        qDebug() << b.test(i);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
