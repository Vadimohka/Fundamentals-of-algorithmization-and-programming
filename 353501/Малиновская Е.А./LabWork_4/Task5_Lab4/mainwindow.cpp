#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int n =4;
    tbl.resize(n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; j++)
        {
            tbl[i].first.push_back(j);
            tbl[i].second.push_back(Pair<int, double>  (i, j * 3.14));
        }
    }

    ui->tableWidget->setRowCount(n * n);
    ui->tableWidget->setColumnCount(3 * n);

    int k = 0;
    for (int i = 0; i < n * 3; i += 3) {
        for (int j = 0; j < n ; ++j) {
            ui->tableWidget->setItem(j, i, new QTableWidgetItem(QString::number(tbl[k].first[j])));
        }
        for (int j = 0; j < n ; ++j) {
            ui->tableWidget->setItem(j , i + 1, new QTableWidgetItem(QString::number(tbl[k].second[j].first)));
            ui->tableWidget->setItem(j , i + 2, new QTableWidgetItem(QString::number(tbl[k].second[j].second)));
        }
        k++;
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    tbl.clear();
    ui->tableWidget->clear();
    int n = arg1;
    tbl.resize(n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; j++)
        {
            tbl[i].first.push_back(j);
            tbl[i].second.push_back(Pair<int, double>  (i, j * 3.14));
        }
    }

    ui->tableWidget->setRowCount(n * n);
    ui->tableWidget->setColumnCount(3 * n);

    int k = 0;
    for (int i = 0; i < n * 3; i += 3) {
        for (int j = 0; j < n ; ++j) {
            ui->tableWidget->setItem(j, i, new QTableWidgetItem(QString::number(tbl[k].first[j])));
        }
        for (int j = 0; j < n ; ++j) {
            ui->tableWidget->setItem(j , i + 1, new QTableWidgetItem(QString::number(tbl[k].second[j].first)));
            ui->tableWidget->setItem(j , i + 2, new QTableWidgetItem(QString::number(tbl[k].second[j].second)));
        }
        k++;
    }

}
