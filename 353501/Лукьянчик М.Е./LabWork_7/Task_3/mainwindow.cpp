#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , hashTable(new ExtendedHashTable(10))
{
    ui->setupUi(this);
    updateDisplay();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete hashTable;
}

void MainWindow::on_pushButtonMaxKey_clicked()
{
    if (!hashTable) return;
    int maxKey = hashTable->findMaxKey();
    ui->plainTextEdit_2->clear();
    ui->plainTextEdit_2->appendPlainText("Max Key: " + QString::number(maxKey));
}

void MainWindow::on_pushButtonRandomFill_clicked()
{
    if (!hashTable) return;
    hashTable->clear();
    for (int i = 0; i < 25; ++i) {
        int key = QRandomGenerator::global()->bounded(100);
        hashTable->insert(key);
    }
    updateDisplay();
}

void MainWindow::on_pushButtonClear_clicked()
{
    if (!hashTable) return;
    hashTable->clear();
    updateDisplay();
}

void MainWindow::updateDisplay()
{
    if (!hashTable) return;
    ui->plainTextEdit->setPlainText(hashTable->toString());
}
