#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , hashTable(21)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    int key = ui->spinBoxKey->value();
    int value = ui->spinBoxValue->value();
    hashTable.push(key, value);
    ui->textEdit->setPlainText(hashTable.print());
}

void MainWindow::on_popButton_clicked() {
    int key = ui->spinBoxKey->value();
    int value;
    if (hashTable.pop(key, value)) {
        ui->textEdit->setPlainText(hashTable.print());
    }
}

void MainWindow::on_taskButton_clicked() {
    hashTable.clear();
    for (int i = 0; i < 50; ++i) {
        int key = QRandomGenerator::global()->bounded(-10, 11);
        int value = QRandomGenerator::global()->bounded(100);
        hashTable.push(key, value);
    }

    ui->textEdit->setPlainText(hashTable.print());

    hashTable.removeNegativeKeys();

    ui->textEdit_2->setPlainText(hashTable.print());
}

void MainWindow::on_pushButton_2_clicked()
{
    hashTable.clear();
    ui->textEdit->setPlainText(hashTable.print());
    ui->textEdit_2->setPlainText(hashTable.print());
}

