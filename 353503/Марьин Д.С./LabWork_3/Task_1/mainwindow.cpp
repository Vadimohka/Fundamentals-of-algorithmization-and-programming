#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget->setStyleSheet("background-color: black");
    ui->lineEdit_binNum->setStyleSheet("QWidget { background-image: url(/Users/daniil_mariyn/Downloads/images.png) };");
    ui->lineEdit_decNum->setStyleSheet("QWidget { background-image: url(/Users/daniil_mariyn/Downloads/images.png) };");
}
MainWindow::~MainWindow()
{
    delete ui;
}
QString MainWindow::convertInteger(int num)
{
    if (num == 0)
    {
        return "0";
    }

    if (num == 1)
    {
        return "1";
    }

     return convertInteger(num / 2) + QString::number(num % 2);

}


QString MainWindow::convertFraction(double frac, int depth)
{
    const int precision = 32;
    if (depth > precision || frac >= 1.0)
    {
        return "";
    }
    double two_frac = 2 * frac;
    int digit = static_cast<int>(two_frac);
    return QString::number(digit) + convertFraction(two_frac - digit, depth + 1);
}

QString MainWindow::translate(double num)
{
    int integerPart = abs(static_cast<int>(num));
    double fractionalPart = abs(abs(num) - integerPart);

    QString integerBinary = convertInteger(integerPart);
    QString fractionalBinary = convertFraction(fractionalPart,1);

    return (num < 0 ? "-" : "") + integerBinary + "." + fractionalBinary;
}
void MainWindow::on_lineEdit_decNum_returnPressed()
{
    bool Ok = true;
    double num = ui->lineEdit_decNum->text().toDouble(&Ok);
    if(!Ok)
    {
        QMessageBox::warning(this, "Error!!!", "Please enter number!");
        return;
    }
    QString str = translate(num);
    ui->lineEdit_binNum->setText(str);
}

