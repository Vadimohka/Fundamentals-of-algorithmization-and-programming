#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i < 1000; i++) {
        int x = rand();
        mod->insert(x, i);
        mult->insert(x, i);
    }
    qDebug() << mod->size() << mult->size();
    qDebug() << mod->amountСollisions() << mult->amountСollisions();
}

MainWindow::~MainWindow()
{
    delete ui;
}
