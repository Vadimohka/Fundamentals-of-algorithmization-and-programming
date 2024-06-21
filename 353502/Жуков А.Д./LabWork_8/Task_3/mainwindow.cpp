#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i = 0; i < 10; ++i) {
        set.insert(QRandomGenerator::global()->bounded(100));
        map.insert(QRandomGenerator::global()->bounded(100), QRandomGenerator::global()->bounded(100));
    }

  //  ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    displayMap();
    displaySet();



}


void MainWindow::displayMap()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(map.size());
    int i = 0;
    for (auto& el : map) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(el.key)));

        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(el.value)));
        i++;
    }
}

void MainWindow::displaySet()
{
    QString text = "";
    for (auto& el : set) {
        text += QString::number(el.key) + " ";
    }
    ui->textBrowser->setText(text);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    map.insert(ui->spinBox->value(), ui->spinBox_2->value());
    set.insert(ui->spinBox->value());
    displayMap();
    displaySet();
}


void MainWindow::on_pushButton_2_clicked()
{
    map.erase(ui->spinBox->value());
    set.erase(ui->spinBox->value());
    displayMap();
    displaySet();
}


void MainWindow::on_pushButton_3_clicked()
{
     ui->label->setText(map.contains(ui->spinBox->value()) ? "ДА" : "НЕТ");
      ui->label_2->setText(set.contains(ui->spinBox->value()) ? "ДА" : "НЕТ");
}





void MainWindow::on_pushButton_4_clicked()
{

}

