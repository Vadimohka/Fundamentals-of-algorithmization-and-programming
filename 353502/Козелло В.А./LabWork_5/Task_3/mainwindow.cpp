#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyBitset bitset(50);
    bitset.set(1);
    bitset.set(3);
    bitset.set(5);
    bitset.set(49);
    qDebug() << bitset.to_string();
}

MainWindow::~MainWindow()
{
    delete ui;
}

