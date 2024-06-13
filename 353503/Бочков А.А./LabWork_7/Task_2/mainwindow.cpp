#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //qDebug() << 1;
    for (int i = 1; i < 10; i++) {
        //qDebug() << i;
        example->add(i, 10 - i + 1);
    }
    //qDebug() << 1;
    example->directOutput(example->GetRoot());
    qDebug() << "";
    example->reverseOutput(example->GetRoot());
    qDebug() << "";
    example->increaseKeyOutput(example->GetRoot());
}

MainWindow::~MainWindow()
{
    delete ui;
}
