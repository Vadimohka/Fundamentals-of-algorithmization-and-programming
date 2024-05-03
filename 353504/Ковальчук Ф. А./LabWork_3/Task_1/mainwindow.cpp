#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <cmath>
#include "Converter.h"


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


void MainWindow::on_ENTER_textChanged(const QString &arg1)
{
    std::string str = arg1.toStdString();
    const char *start = str.c_str();
    char *end;
    double value = strtold(start, &end);

    if(arg1.size() > 19) {
        ui->BINARY->setText(Converter::IntToBinary(m_lastValue) + "...");
        Converter::IEEE754 ieee754 = Converter::ToIEEE754(value);

        ui->SIGN->setText(ieee754.GetSigh());
        ui->EXPONENT->setText(ieee754.GetExp());
        ui->MANTISSA->setText(ieee754.GetMantisse());
        return;
    }


    if (*end != '\0')
    {
        ui->BINARY->setText("Enter valid number!");
        ui->SIGN->setText("-");
        ui->EXPONENT->setText("--------");
        ui->MANTISSA->setText("-----------------------");
    }
    else if (str.empty())
    {
        ui->BINARY->setText("");
        ui->SIGN->setText("-");
        ui->EXPONENT->setText("--------");
        ui->MANTISSA->setText("-----------------------");
    }
    else
    {
        m_lastValue = floor(value);
        ui->BINARY->setText(Converter::IntToBinary(m_lastValue));
        Converter::IEEE754 ieee754 = Converter::ToIEEE754(value);

        ui->SIGN->setText(ieee754.GetSigh());
        ui->EXPONENT->setText(ieee754.GetExp());
        ui->MANTISSA->setText(ieee754.GetMantisse());
    }
}

