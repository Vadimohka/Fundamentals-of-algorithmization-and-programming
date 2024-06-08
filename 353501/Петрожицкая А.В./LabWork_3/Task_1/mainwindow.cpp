#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "numberconverter.h"

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

void MainWindow::convertToBinary()
{
    QString numberText = ui->lineEdit->text();
    bool ok = false;
    double number = numberText.toDouble(&ok);

    if(number>1e18){
        QMessageBox::warning(this, "Ошибка", "Введите корректное число");
    }
    else if (ok)
    {
        QString binaryNumber = NumberConverter::decimalToBinary(number, 1600);
        ui->label_2->setText(binaryNumber);
    }
    else
    {
        ui->label_2->setText("Invalid number entered!");
    }
    number = numberText.toDouble();
    QString binaryNumber = NumberConverter::decimalToBinary(number, 1600);
    ui->label_2->setText(binaryNumber);
}

void MainWindow::on_pushButton_clicked()
{
    convertToBinary();
}

