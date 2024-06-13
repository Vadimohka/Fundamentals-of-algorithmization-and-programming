#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));
    for (int i = 1; i <= 1000; i++) {
        Hash->insert(rand() % 100, i);
    }
    qDebug() << Hash->size();
    for (int i = 0; i < 10; i++) {
        qDebug() << Hash->find(i);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
