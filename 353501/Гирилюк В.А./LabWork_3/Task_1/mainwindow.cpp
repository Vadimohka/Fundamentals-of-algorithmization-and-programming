#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

void MainWindow::on_lineEdit_editingFinished()
{
    std::string str = ui->lineEdit->text().toStdString();
    long long integer = 0;
    int integerSize = 0;
    int fractalPower = 10;
    double fraction = 0;
    int exp = 0;
    bool dot = false, correct = true, exponential = false;
    char c = '.';
    for(int i = 0; i < str.length(); i++){
        if((str.at(i) < '0' || str.at(i) > '9') && str.at(i) != '.' && str.at(i) != 'e'){
            correct = false;
            break;
        }
        else if(str.at(i) == c && dot){
            correct = false;
            break;
        }
        else if(str.at(i) == c && !dot){
            dot = true;
        }
        else if(str.at(i) == 'e' && !exponential){
            exponential = true;
        }
        else if(str.at(i) == 'e' && exponential){
            correct = true;
        }
        else if(!dot && !exponential){
            integer = integer * 10 + str.at(i) - '0';
            ++integerSize;
        }
        else if(dot && !exponential){
            fraction = fraction + double(str.at(i) - '0') / fractalPower;
            fractalPower *= 10;
        }
        else if(exponential){
            exp = exp * 10 + str.at(i) - '0';
        }
    }
    if(exponential){
        for(int i = 0; i < exp; i++){
            ++integerSize;
            integer = integer * 10 + int(fraction*10);
            fraction = fraction * 10 - int(fraction*10);
        }
    }
    if(integerSize >= 19 && integer < LONG_LONG_MAX){
        QMessageBox::critical(this, "Error", "Incorrect input!\nToo huge integer part.\nRetry input.");
    }
    else if(exp >18){
        QMessageBox::critical(this, "Error", "Incorrect input!\nToo exponential part.\nRetry input.");
    }
    else if(!correct){
        QMessageBox::critical(this, "Error", "Incorrect input!\nRetry input.");
    }
    else{
        ui->outPutResult->setText(decimalToBinary(integer, fraction));
    }
}

QString MainWindow::decimalToBinary(long long integer, double fraction)
{
    return integerToBinary(integer) + "." + fractionToBinary(fraction, 8);
}

QString MainWindow::integerToBinary(long long number)
{
    if(number > 1){
        return integerToBinary(number / 2) + QString::number(number % 2);
    }
    else if(number == 1){
        return "1";
    }
    else{
        return "0";
    }
}

QString MainWindow::fractionToBinary(double number, int precision)
{
    if(precision > 0){
        if(2 * number >= 1){
            return "1" + fractionToBinary(2 * number - 1, precision - 1);
        }
        else{
            return "0" + fractionToBinary(2 * number, precision - 1);
        }
    }
    else{
        return "";
    }
}

