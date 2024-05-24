#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyString str("Hello World");
    str.erase(0, 6);
    qDebug() << str.c_str();
}

MainWindow::~MainWindow()
{
    delete ui;
}

