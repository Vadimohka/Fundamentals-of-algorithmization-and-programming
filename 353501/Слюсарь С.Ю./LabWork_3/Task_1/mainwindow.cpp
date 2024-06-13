#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Input->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,7}([.][0-9]{1,9})?$"),this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::intToBinary(int num)
{
    if(num > 1)
    {
        intToBinary(num / 2);
    }
    to2 += QString::number(num % 2);
}

void MainWindow::doubleToBinary(double num)
{
    if (num != 0 && dto2.length() < 33)
    {
        num *= 2;
        dto2 += QString::number((int)num);

        if (num >= 1) {
            num -= 1;
        }

        doubleToBinary(num);
    }
}

void MainWindow::on_Conv_clicked()
{
    to2 = "";
    dto2 = "";
    inp = ui->Input->text();
    if (inp[0] == ',' || inp[inp.length() - 1] == ',')
    {
        ui->Output->setText("Неправильный ввод");
    }
    else
    {
        double num = inp.toDouble();
        int num1 = (int)num;
        double num2 = num - num1;
        intToBinary(num1);
        doubleToBinary(num2);
        ui->Output->setText(to2 + '.' + dto2);
    }
}
