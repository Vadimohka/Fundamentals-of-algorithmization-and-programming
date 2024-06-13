#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myPair<int, QString> p = myPair<int, QString>();
    myPair<int, int> pp = myPair<int, int>();
    myPair<myPair<int, int>, QString> pa = myPair<myPair<int, int>, QString>();

    p.first = 1;
    p.second = "Hello, World!";
    qDebug() << p.first << " " << p.second;

    pp.first = 10;
    pp.second = 10;

    pa.first.first = pp.first;
    pa.first.second = pp.second;
    pa.second = "Hello, Vlad!";

    qDebug() << pa.first.first << " " << pa.first.second << "    " << pa.second;
}

MainWindow::~MainWindow()
{
    delete ui;
}
