#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnWidth(1,249);

    //setUp();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_count_clicked()
{
    QString info = ui->input->text();
    bool ok = false;
    double decimal = info.toDouble(&ok);

    if (ok){
        int n = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(n);
        ui->tableWidget->setItem(n, 0, new QTableWidgetItem(info));
        Mathematics* count = new Mathematics;
        ui->tableWidget->setItem(n, 1, new QTableWidgetItem(count->decToBin(decimal)));

    }
}

