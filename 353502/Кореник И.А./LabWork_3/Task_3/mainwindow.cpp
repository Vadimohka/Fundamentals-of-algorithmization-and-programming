#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_count_clicked()
{
    QString info = ui->input->text();
    bool ok = false;
    int number = info.toInt(&ok);


    if (ok){
        int n = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(n);
        ui->tableWidget->setItem(n, 0, new QTableWidgetItem(info));
        Mathematics* count = new Mathematics;
        ui->tableWidget->setItem(n, 1, new QTableWidgetItem(QString::number(count->inverse(number))));
    }
}

