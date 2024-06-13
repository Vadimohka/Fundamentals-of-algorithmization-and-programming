#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bitset = new BitSet(15,10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

