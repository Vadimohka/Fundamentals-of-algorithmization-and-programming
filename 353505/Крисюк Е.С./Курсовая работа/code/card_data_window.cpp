#include "card_data_window.h"
#include "ui_card_data_window.h"

Card_data_window::Card_data_window(long long user_index ,Card* card,QWidget *parent) :QDialog(parent),ui(new Ui::Card_data_window)
{
    ui->setupUi(this);

    current_card = card;
    current_user_index = user_index;

    ui -> Cvv_line -> setText(current_card -> GetCvv());
    ui -> Money_line -> setText(AllUsersFile::From_long_double_to_QString(current_card -> Get_current_money()));
    ui -> Month_line -> setText(current_card -> GetMonth());
    ui -> Number_line -> setText(current_card -> GetCardNumber());
    ui -> Pin_line -> setText(current_card -> GetPin());
    ui -> Banking_app_line -> setText(current_card -> Get_banking_app_name());
    ui -> Year_line -> setText(current_card -> GetYear());


}

Card_data_window::~Card_data_window()
{
    delete ui;
}

void Card_data_window::on_Accept_button_clicked()
{
    close();
}


void Card_data_window::on_Add_money_to_card_button_clicked()
{
    add_money_window = new Add_money_window(current_card, current_user_index);
    add_money_window -> exec();

    ui -> Money_line -> setText(AllUsersFile::From_long_double_to_QString(current_card -> Get_current_money()));

    AllUsersFile::Change_money_in_file(current_user_index, current_card -> GetCardNumber(), ui -> Money_line -> text());

}

