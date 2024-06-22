#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , hashTable(new ExtendedHashTable(10))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete hashTable;
    delete ui;
}

void MainWindow::on_insertButton_clicked() {
    int key = ui->keyLineEdit->text().toInt();
    QString value = ui->valueLineEdit->text();
    hashTable->insert(key, value);
    updateDisplay();
}

void MainWindow::on_removeButton_clicked() {
    int key = ui->keyLineEdit->text().toInt();
    if (hashTable->remove(key)) {
        QMessageBox::information(this, "Remove", "Key removed successfully");
    } else {
        QMessageBox::warning(this, "Remove", "Key not found");
    }
    updateDisplay();
}

void MainWindow::on_findButton_clicked() {
    int key = ui->keyLineEdit->text().toInt();
    QString value;
    if (hashTable->find(key, value)) {
        QMessageBox::information(this, "Find", QString("Key: %1, Value: %2").arg(key).arg(value));
    } else {
        QMessageBox::warning(this, "Find", "Key not found");
    }
}

void MainWindow::on_countAboveAvgButton_clicked() {
    int count = hashTable->countKeysAboveAverage();
    QMessageBox::information(this, "Count Above Average", QString("Number of keys above average: %1").arg(count));
}

void MainWindow::updateDisplay() {
    qDebug() << "knowhnb";
    ui->memo->setPlainText(hashTable->toString());
}


