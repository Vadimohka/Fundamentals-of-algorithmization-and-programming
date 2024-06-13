#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , hashTable(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
    delete hashTable;
}

void MainWindow::on_initHashTableButton_clicked() {
    int size = ui->spinBox->value();
    delete hashTable;
    hashTable = new DerivedHashTable(size);
    updateHashTableView();
}

void MainWindow::on_addElementButton_clicked() {
    if (hashTable) {
        int key = ui->keyLineEdit->text().toInt();
        int value = ui->valueLineEdit->text().toInt();
        hashTable->insert(key, value);
        updateHashTableView();
    }
}

void MainWindow::on_removeElementButton_clicked() {
    if (hashTable) {
        int key = ui->keyLineEdit->text().toInt();
        hashTable->remove(key);
        updateHashTableView();
    }
}

void MainWindow::on_findMaxKeyStackButton_clicked() {
    if (hashTable) {
        int stackIndex = hashTable->getStackWithMaxKey();
        QString result = "Stack with max key is: " + QString::number(stackIndex);
        ui->textEdit->append(result);
    }
}

void MainWindow::updateHashTableView() {
    if (hashTable) {
        ui->tableWidget->clear();
        int size = hashTable->getSize();
        ui->tableWidget->setRowCount(size);
        ui->tableWidget->setColumnCount(1);
        ui->tableWidget->setColumnWidth(0, 500);
        for (int i = 0; i < size; ++i) {
            Stack stack = hashTable->getStack(i);
            std::vector<KeyValuePair> elements = stack.getElements();
            QString stackContent;
            for (const auto& elem : elements) {
                stackContent += "{" + QString::number(elem.key) + ", " + QString::number(elem.value) + "} ";
            }
            QTableWidgetItem *item = new QTableWidgetItem(stackContent);
            ui->tableWidget->setItem(i, 0, item);
        }
    }
}

