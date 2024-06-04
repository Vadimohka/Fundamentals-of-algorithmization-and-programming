#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("ЪуЪ");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Add_clicked()
{
    arr.push_back(ui->Input->value());
    ui->Input->clear();
    Median *median = new Median(arr);
    ui->Array->insert(QString::number(arr[arr.size() - 1]) + ", ");
    QVector<double> ans = median->findMedian();
    ui->Answer->clear();
    for (double a : ans) {
        ui->Answer->insert(QString::number(a) + ", ");
    }
    delete median;
}

void MainWindow::on_Clear_clicked()
{
    ui->Array->clear();
    ui->Answer->clear();
    arr.clear();
}
