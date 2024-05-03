#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpressionValidator>
#include <iostream>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
  ui->setupUi(this);

  ui->lineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,16}(?:[.][0-9]{1,15})?$"),this));  

  connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::binarySetText);
}

void MainWindow::binarySetText(){
  QString str = ui->lineEdit->text();
  value = str.toDouble();
  std::cout << value;
  ui->label->setText(ToBin(value));
}

QString MainWindow::IntToBin(long long value)
{
    if (value == 0)
    {
        return "";
    }
    return IntToBin(value / 2) + QString::number(value % 2);
}

QString MainWindow::RealToBin(long double value)
{
    value *= 2;
    
    if (value >= 1)
    {
        return "1" + RealToBin(value - 1);
    }
    else if (value != 0)
    {
        return "0" + RealToBin(value);
    }
    else
    {
        return "";
    }
}

QString MainWindow::ToBin(double value)
{
    long long IntPart = (long long)value;
    long double RealPart = value - IntPart;
    QString res;
    if(RealPart != 0 && IntPart != 0){
        res = IntToBin (IntPart) + "." + RealToBin(RealPart);
    }
    else if(IntPart == 0){
        res = "0." + RealToBin(RealPart); 
    }
    else{
        res = IntToBin (IntPart);
    }
    return res;
}