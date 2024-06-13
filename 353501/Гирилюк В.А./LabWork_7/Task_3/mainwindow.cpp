#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hashTable = new NoNegativeStackHashTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
    delete hashTable;
    hashTable = new NoNegativeStackHashTable();
    for(int i = 0; i < 100; i++){
        QString randomString;
        int length = 10;
        for (int i = 0; i < length; ++i) {
            QChar randomChar = QRandomGenerator::global()->bounded('A', 'Z' + 1);
            randomString.append(randomChar);
        }
        hashTable->put(randomString, QRandomGenerator::global()->bounded(-10, 11));
    }

    for(int i = 0; i < hashTable->size; i++){
        QString str = hashTable->stackToQString(i);
        ui->textEdit->append(str);
    }

}


void MainWindow::on_pushButtonAdd_clicked()
{
    ui->textEdit->clear();
    hashTable->put(ui->lineEdit->text(), ui->spinBox->value());
    for(int i = 0; i < hashTable->size; i++){
        QString str = hashTable->stackToQString(i);
        ui->textEdit->append(str);
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    int number = hashTable->get(ui->lineEdit->text());
    ui->textEdit->clear();
    for(int i = 0; i < hashTable->size; i++){
        QString str = hashTable->stackToQString(i);
        ui->textEdit->append(str);
    }
    QMessageBox::critical(this, "You get number", "Your number is " + QString::number(number));
}

