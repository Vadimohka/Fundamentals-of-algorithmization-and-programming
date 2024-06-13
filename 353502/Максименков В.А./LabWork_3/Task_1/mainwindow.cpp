#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->doubleSpinBox->setDecimals(6);
    ui->doubleSpinBox->setMinimum(-10000);
    ui->doubleSpinBox->setMaximum(10000);
    ui->precisionBox->setMaximum(20);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::integerToBinarySystem(int n, QString& now)
{
    if (n == 0) return;
    int temp = n/2;
    temp = n - temp*2;
    char ans = (temp == 0 ? '0' : '1');
    now.push_back(ans);
    integerToBinarySystem(n/2, now);
}


void MainWindow::fractionToBinarySystem(double n, QString &now, const int& precision)
{
    if (now.size() >= precision) return;
    double temp = n*2;
    int bit = static_cast<int>(temp);
    char ans = (bit == 0 ? '0' : '1');
    now.push_back(ans);
    temp -= bit;
    fractionToBinarySystem(temp, now, precision);
}


void MainWindow::on_convertButton_clicked()
{
    int precision = ui->precisionBox->value();
    double number = ui->doubleSpinBox->value();
    if (number == 0)
    {
        ui->answerBrowser->setText("0");
        return;
    }

    QString integerAns = "", fractionalAns = "", totalAns = "";
    if (number < 0)
    {
        number = -number;
        totalAns.push_back('-');
    }

    int integer = number;
    if (integer == 0)
    {
        integerAns = "0";
    }
    else
    {
        integerToBinarySystem(integer, integerAns);
        std::reverse(integerAns.begin(), integerAns.end());
    }
    if (number - integer == 0 || precision == 0)
    {
        ui->answerBrowser->setText(integerAns);
        return;
    }
    fractionToBinarySystem(number - integer, fractionalAns, precision);
    totalAns += integerAns;
    totalAns.push_back(',');
    totalAns += fractionalAns;
    ui->answerBrowser->setText(totalAns);
}

