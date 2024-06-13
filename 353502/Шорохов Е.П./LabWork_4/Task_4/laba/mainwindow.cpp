#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "myvector.h"
#include "mypair.h"
#include <iostream>
#include <QDebug>

//I am booored
class Smth
{
public:
    int a;
    Smth(int _a) :
        a(_a)
    {

    }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myVector<Smth> SHIT;

    SHIT.assign(5, Smth(10));
    SHIT.emplace_back(7);
    \
    for (auto instance : SHIT)
    {
        qDebug() << instance.a;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

