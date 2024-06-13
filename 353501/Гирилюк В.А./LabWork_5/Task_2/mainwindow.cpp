#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyString str("Hello World");
    str.erase(0, 6);
    qDebug() << QString::fromStdString(str.c_str());
    ui->mainText->setPlainText("Watch qDebug :)");
}

MainWindow::~MainWindow()
{
    delete ui;
}

