#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui -> setupUi(this);
    QDoubleValidator* val = new QDoubleValidator(-99999,99999,5);
    ui -> System_10_line -> setValidator(val);
    ui -> System_10_line -> setMaxLength(10);
    count = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_System_10_line_textChanged(const QString &arg1)
{

    result_2_int_str.clear();
    result_2_double_str.clear();

    if(ui -> System_10_line -> text() != ""){

        number_str = ui -> System_10_line -> text();
        number_str.replace(",", ".");

        number_double = number_str.toDouble();

        bool is_have_minus = false;

        if(number_double < 0){
            is_have_minus = true;
            number_double *= -1;
        }

        number_int = int(number_double);

        double raz = number_double - number_int;

        Convert_int(number_int);
        if(raz != 0) {
            Convert_double(raz);
        }

        QString result;
        result = result_2_int_str;

        if(result_2_double_str.length() != 0) {
            result += ",";
            result += result_2_double_str;
        }


        if(is_have_minus) {
            result.insert(0,"[1]");
        }
        else {
            result.insert(0,"[0]");
        }
        ui -> System_2_line -> setText(result);

    }
    else{
        ui -> System_2_line -> setText("");
    }

}

long long MainWindow::Convert_int(long long number){
    if(number == 0){
        return 0;
    }
    result_2_int_str.insert(0,QString::number(number % 2));

    return Convert_int(number / 2);
}

double MainWindow::Convert_double(double number){

    if(count == 9 || number == 1){
        count = 0;
        return 0;
    }
    count ++;

    if(number > 1){
        number --;
    }

    result_2_double_str += QString::number(int(number * 2));

    return Convert_double(number * 2);
}
