#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    count_of_digits = 0;
    result = 0;
    QIntValidator* val = new QIntValidator(-999999, 9999999);
    ui -> Number_line -> setValidator(val);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Number_line_textChanged(const QString &arg1)
{
    result = 0;
    if(ui -> Number_line -> text() != "")
        number = ui -> Number_line -> text().toLongLong();
    else{
        number = 0;
    }
    count_of_digits = 0;
    Result_output();
}

void MainWindow::Result_output(){

    if(number < 0){
        isMinus = true;
        number = abs(number);
    }
    else{
        isMinus = false;
    }
    Calculate_count_of_digits(number);
    count_of_digits--;

    result = Calculate_result(number);
    if(isMinus){
        result *= -1;
    }

    ui -> Result_line -> setText(QString::number(result));
}

long long MainWindow::Calculate_result(long long& number){
    if(count_of_digits > 0){
        count_of_digits--;

        result += number % 10 * pow(10, count_of_digits);

        number /= 10;
        return Calculate_result(number);

    }
    return result;
}

long long MainWindow::Calculate_count_of_digits(long long number){
    count_of_digits++;

    if(number > 0)
        return Calculate_count_of_digits(number / 10);

    return 0;
}
