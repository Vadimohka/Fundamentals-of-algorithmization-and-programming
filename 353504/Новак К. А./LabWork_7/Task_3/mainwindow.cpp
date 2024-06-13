#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->clear();

    int size = ui->SizeEdit->text().toInt();

    if(size > 100 || size < 0){
        return;
    }

    Table = new HashTable<QString>(size);
    for(int i = 0; i < size; ++i){
        Table->insert(GetRandNum(), QString::number(i));
    }

    Table->ToWidget(*ui->listWidget);
}

int MainWindow::GetRandNum()
{
    return QRandomGenerator::global()->bounded(INT_MAX);
}
