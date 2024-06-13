#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    one = false;
    second = false;
    QIntValidator* val_1 = new QIntValidator(0, 9);
    ui -> Number_1_line -> setValidator(val_1);
    QIntValidator* val_2 = new QIntValidator(0,999999);
    ui -> Number_2_line -> setValidator(val_2);

    max_length = 9999999;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Number_1_line_textChanged(const QString &arg1)
{
    if(ui -> Number_1_line -> text() != ""){
        one = true;

        QString temp = ui -> Number_1_line -> text();
        if(temp.toInt() == 2){
            max_length = 20000;
        }
        else if(temp.toInt() == 3){
            max_length = 8;
        }
        else if(temp.toInt() == 4){
            max_length = 1;
        }
        QString temp_2 = ui -> Number_2_line -> text();

        if(temp_2 != ""){
            if(temp_2.toInt() > max_length ){
                ui -> Number_2_line -> setText(QString::number(max_length));
            }
        }
    }
    else{
        ui -> Result_line -> setText("");
        one = false;
    }

    Result_output();
}


void MainWindow::on_Number_2_line_textChanged(const QString &arg1)
{
    if(ui -> Number_2_line -> text() != ""){
        second = true;
        QString temp = ui -> Number_2_line -> text();

        if(temp.toInt() > max_length){
            ui -> Number_2_line -> setText(QString::number(max_length));
        }
    }
    else{
        ui -> Result_line -> setText("");
        second = false;
    }
    Result_output();
}
void MainWindow::Result_output(){
    QString number_1, number_2;

    number_1 = ui -> Number_1_line -> text();
    number_2 = ui -> Number_2_line -> text();

    if(one && second){
        QString result;
        result = QString::number(Calculate_Result(number_1.toLongLong(), number_2.toLongLong()));
        ui -> Result_line -> setText(result);
    }
}

long long MainWindow::Calculate_Result(long long number_1, long long number_2){

    if(number_1 == 0){
        return number_2 + 1;
    }
    else if(number_1 > 0 && number_2 == 0){
        return Calculate_Result(number_1 - 1, 1);
    }
    else if(number_1 > 0 && number_2 > 0){

        return Calculate_Result(number_1 - 1, Calculate_Result(number_1, number_2 - 1));

    }

    return -1;
}
