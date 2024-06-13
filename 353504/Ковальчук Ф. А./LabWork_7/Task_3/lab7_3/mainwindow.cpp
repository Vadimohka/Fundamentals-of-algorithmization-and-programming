#include "mainwindow.h"
#include "ui_mainwindow.h"

constexpr short SIZE_STRING = 10;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , hashTable(new HashTableMax<QString>(100))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

unsigned int MainWindow::generateRandomNumber()
{
    return QRandomGenerator::global()->bounded(INT_MAX);
}

QString MainWindow::generateRandomString(unsigned int length)
{
    QString randomString;
    static const char alphanum[] = "0123456789"
                                   "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                   "abcdefghijklmnopqrstuvwxyz";

    for (unsigned int i = 0; i < length; ++i) {
        randomString
            += alphanum[QRandomGenerator::global()->bounded(static_cast<int>(sizeof(alphanum) - 1))];
    }

    return randomString;
}

void MainWindow::on_generateButton_clicked()
{
    ui->listElementWidget->clear();
    ui->listStackWidget->clear();
    ui->findMaxEdit->clear();

    unsigned int key = 0;
    QString valueStr;
    hashTable = new HashTableMax<QString>(ui->amountElementBox->value());

    for (int i = 0; i < ui->amountElementBox->value(); ++i) {
        key = generateRandomNumber();
        valueStr = generateRandomString(SIZE_STRING);
        hashTable->insert(key, valueStr);
        ui->listElementWidget->addItem("[" + QString::number(i) + "] - Key: " + QString::number(key)
                                       + " Value: " + valueStr);
    }
    ui->findMaxEdit->setText("Key: " + QString::number(hashTable->getMaxKey())
                             + " Value: " + hashTable->findMax());
    hashTable->inputToTableWidget(*ui->listStackWidget);
}
