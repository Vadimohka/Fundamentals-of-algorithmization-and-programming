#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    str = "abcd";
    //str.clear();
    str.append("ef");
    //str.erase(1, 3);
    //str.pop_back();
    str.shrink_to_fit();
    for (int i = 0; i < str.size(); i++) {
        qDebug() << str[i];
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
