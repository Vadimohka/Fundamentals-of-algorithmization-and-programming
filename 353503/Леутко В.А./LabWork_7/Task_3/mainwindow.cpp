#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , hashTable(new HashTableAvg<QString>(4))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generateBtn_clicked()
{
    unsigned int key = 0;
    QString valueStr;
    hashTable = new HashTableAvg<QString>(ui->spinBox_2->value());

    for (int i = 0; i < ui->spinBox->value(); ++i) {
        key = generateRandomNumber();
        valueStr = generateRandomString(10);
        hashTable->insert(key, valueStr);
        ui->listWidget->addItem(QString::number(i) + ". Key: " + QString::number(key)
                                       + " Value: " + valueStr);
    }
    hashTable->inputToTableWidget(*ui->listStackWidget);

    // size_t countAboveAvg = hashTable->getCountAboveAvg();
    // ui->textEdit->clear();
    // ui->textEdit->append(QString("Количество элементов, превышающих среднее значение ключей: %1").arg(countAboveAvg));
}


QString MainWindow::generateRandomString(int length)
{
    QString characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    QString result;
    for (int i = 0; i < length; i++) {
        result += characters[QRandomGenerator::global()->generate() % characters.length()];
    }
    return result;
}

int64_t MainWindow::generateRandomNumber()
{
    int numDigits = QRandomGenerator::global()->generate() % 5 + 8; // Случайное число от 8 до 12
    int64_t result = 0;
    for (int i = 0; i < numDigits; i++) {
        result = result * 10 + QRandomGenerator::global()->generate() % 10;
    }
    return result;
}
