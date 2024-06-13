#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    hash(size)
{
    ui->setupUi(this);
    for(int i = 0 ; i < 20; ++i){
        hash.insert(10, QString::number(i));
    }

    qDebug() << hash.print();
}

MainWindow::~MainWindow()
{
    delete ui;
}
