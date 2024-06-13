#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    s.insertVal(10);
    s.insertVal(6);
    s.insertVal(2);
    s.insertVal(1);
    s.insertVal(100);

    qDebug() << (s.findVal(6))->value << " " << (s.findVal(10))->value << " " << (s.findVal(2))->value << " " << (s.findVal(1))->value << " " << (s.findVal(100))->value;

    m[100] = "Vlad";
    m[77] = "Anton";
    m[104] = "Dzioma";
    m[22] = "Dzianis";

    qDebug() << m[100] << m[77] << m[104] << m[22];
}

MainWindow::~MainWindow()
{
    delete ui;
}
