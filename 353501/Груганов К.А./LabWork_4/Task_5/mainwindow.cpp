#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->leftWidget->setRowCount(0);
    ui->rightWidget->setRowCount(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generateButton_clicked()
{
    srand(time(0));
    pair.first.clear();
    for (int i = 0; i < rand() % 21 + 5; i++) {
        pair.first.push_back(rand() % 201 - 100);
    }
    ui->leftWidget->setRowCount(pair.first.Size());
    for (size_t i = 0; i < pair.first.Size(); i++) {
        ui->leftWidget->setItem(i, 0, new QTableWidgetItem(QString::number(pair.first[i])));
    }
    pair.second.clear();
    for (int i = 0; i < rand() % 21 + 5; i++) {
        pair.second.push_back(
            Pair<int, double>(rand() % 201 - 100, (double) rand() / RAND_MAX * 200 - 100));
    }
    ui->rightWidget->setRowCount(pair.second.Size());
    for (size_t i = 0; i < pair.second.Size(); i++) {
        ui->rightWidget->setItem(i, 0, new QTableWidgetItem(QString::number(pair.second[i].first)));
        ui->rightWidget->setItem(i, 1, new QTableWidgetItem(QString::number(pair.second[i].second)));
    }
}
