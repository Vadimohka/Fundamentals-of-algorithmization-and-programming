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



QString MainWindow::decimalToBinaryRecursion(int num)
{
    if (num == 0)
        return "0";
    if (num == 1)
        return "1";
    else
        return decimalToBinaryRecursion(num / 2) + QString::number(num % 2);
}

QString MainWindow::convertFraction(double num, int k)
{
    QString binary = "";
    while (k--)
    {
        num *= 2;
        int fract_bit = num;

        if (fract_bit == 1)
        {
            num -= fract_bit;
            binary.append("1");
        }
        else
            binary.append("0");
    }
    return binary;
}

QString MainWindow::decimalToBinary(long double num, int k_prec)
{
    int Integral = num;

    double fractional = num - Integral;

    QString binary = decimalToBinaryRecursion(Integral);

    if (k_prec) {
        binary.append(".");
    }

    binary.append(convertFraction(fractional, k_prec));

    return binary;
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_4->clear();

    QString lineDouble, lineInt;
    double num;
    int pr;
    bool isOkDouble, isOkInt;

    lineDouble = ui->lineEdit->text();

    num = lineDouble.toDouble(&isOkDouble);

    lineInt = ui->lineEdit_2->text();

    pr = lineInt.toInt(&isOkInt);

    if (!isOkDouble && !isOkInt) {
        QMessageBox::critical(0, "Ошибка", lineDouble+" - не являтся вещественным числом!\n"+lineInt+" - не является целым числом!");
    } else if (!isOkDouble) {
        QMessageBox::critical(0, "Ошибка", lineDouble+" - не являтся вещественным числом!");
    } else if (!isOkInt) {
        QMessageBox::critical(0, "Ошибка", lineInt+" - не является целым числом!");
    } else {
        ui->label_4->setText(decimalToBinary(num, pr));
    }





}
