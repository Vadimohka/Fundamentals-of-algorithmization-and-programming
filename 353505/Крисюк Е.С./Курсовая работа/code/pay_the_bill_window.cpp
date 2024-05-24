#include "pay_the_bill_window.h"
#include "ui_pay_the_bill_window.h"

Pay_the_bill_window::Pay_the_bill_window(long long index, Card* card,QWidget *parent) :QDialog(parent),ui(new Ui::Pay_the_bill_window)
{
    ui->setupUi(this);

    user_index = index;
    current_card = card;
}

Pay_the_bill_window::~Pay_the_bill_window()
{
    delete ui;
}



void Pay_the_bill_window::on_Cancel_button_clicked()
{
    close();
}


void Pay_the_bill_window::on_Pay_button_clicked()
{
    double money = ui -> Cost_line -> text().toDouble();
    QString message = ui -> comboBox -> currentText();

    int index = Transactions::Minus_money_card(current_card -> GetCardNumber(), money, message);

    if(index == 0){
        AllUsersFile::Add_transaction_to_file(user_index, current_card -> GetCardNumber());
    }

    close();

}


void Pay_the_bill_window::on_comboBox_currentIndexChanged(int index)
{
    if(index == 0){
        ui -> Cost_line -> setText("8");
    }
    else if(index == 1){
        ui -> Cost_line -> setText("10");
    }
}

