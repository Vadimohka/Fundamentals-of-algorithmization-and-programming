#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->setText("");
    for(int i = 0; i < 100; i++){
        QString randomString;
        int length = 10;
        for (int i = 0; i < length; ++i) {
            QChar randomChar = QRandomGenerator::global()->bounded('A', 'Z' + 1);
            randomString.append(randomChar);
        }
        hashTable.put(randomString, QRandomGenerator::global()->bounded(-10, 11));
    }

    for(int i = 0; i < hashTable.size; i++){
        QString str = hashTable.stackToQString(i);
        ui->textEdit->append(str);
    }

}

