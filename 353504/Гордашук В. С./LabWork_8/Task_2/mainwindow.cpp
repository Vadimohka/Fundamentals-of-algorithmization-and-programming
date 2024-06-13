#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i < 10; ++ i)
    {
        bhl.insert(QRandomGenerator::global()->bounded(1, 1000));
    }
    bhl.printHeapToTreeWidget(ui->treeWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    bhl.insert(QRandomGenerator::global()->bounded(1, 1000));
    bhl.printHeapToTreeWidget(ui->treeWidget);
}


void MainWindow::on_pushButton_2_clicked()
{
    bhl.remove();
    bhl.printHeapToTreeWidget(ui->treeWidget);
}

