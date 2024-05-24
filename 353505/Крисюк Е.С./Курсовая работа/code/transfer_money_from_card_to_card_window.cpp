#include "transfer_money_from_card_to_card_window.h"
#include "ui_transfer_money_from_card_to_card_window.h"


Transfer_money_from_card_to_card_window::Transfer_money_from_card_to_card_window(QWidget *parent) : QDialog(parent),   ui(new Ui::Transfer_money_from_card_to_card_window)
{
    ui->setupUi(this);

}

Transfer_money_from_card_to_card_window::~Transfer_money_from_card_to_card_window()
{
    delete ui;
}

void Transfer_money_from_card_to_card_window::on_Cancel_button_clicked()
{
    close();
}


void Transfer_money_from_card_to_card_window::on_Transfer_button_clicked()
{
    QString from_card_number = ui -> From_card_line -> text();
    QString to_card_number = ui -> To_card_line -> text();

    QString money_str = ui -> Money_count_line -> text();

    long double money = AllUsersFile::From_QString_to_long_double(money_str);


    int state = Transactions::Transfer_money_from_card_to_card(from_card_number, money, to_card_number);

}

