#include "add_money_window.h"
#include "ui_add_money_window.h"

#include <iostream>

Add_money_window::Add_money_window(Card* card, long long user_index, QWidget *parent) : QDialog(parent), ui(new Ui::Add_money_window)
{
    ui->setupUi(this);
    current_card = card;
    current_user_index = user_index;

    QDoubleValidator* val = new QDoubleValidator(0,99999999, 2);
    ui -> Add_money_line -> setValidator(val);

    Update_window_money();

}

Add_money_window::~Add_money_window()
{
    delete ui;
}

void Add_money_window::on_Cancel_button_clicked()
{
    close();
}


void Add_money_window::on_Add_money_button_clicked()
{
    QString money_str = ui -> Add_money_line -> text().replace(',', '.');


    double money = AllUsersFile::From_QString_to_long_double(money_str);

    if(money + current_card -> Get_current_money() < 10000000000){
        double money = AllUsersFile::From_QString_to_long_double(money_str);

        Transactions::Add_money_card(current_card -> GetCardNumber(), money);
        AllUsersFile::Add_transaction_to_file(current_user_index, current_card -> GetCardNumber());

        Update_window_money();

    }
    else{
        QMessageBox* box = new QMessageBox();

        box -> setWindowTitle("Предупреждение");
        box -> setText("Значение слишком велико");
        box -> exec();
    }

}

void Add_money_window::Update_window_money(){
    ui -> Current_money_line -> setText(AllUsersFile::From_long_double_to_QString(current_card -> Get_current_money()));
}

void Add_money_window::on_Add_money_line_textChanged(const QString &text)
{
    int index_of_comma = text.indexOf(',');
    QString double_part = text.mid(index_of_comma + 1, text.length());

    if(index_of_comma == -1){
        index_of_comma = text.length();
        double_part = "";
    }

    QString int_part = text.mid(0,index_of_comma);


    if(int_part.length() > 8){
        QMessageBox* box = new QMessageBox();

        box -> setWindowTitle("Предупреждение");
        box -> setText("Значение слишком велико");

        int_part.remove(int_part.length() - 1, 1);

        ui -> Add_money_line -> setText(int_part + "," + double_part);

        box -> exec();
    }

}

