#include "register_new_card_window.h"
#include "ui_register_new_card_window.h"

extern Bank_meneger& meneger;

Register_new_card_window::Register_new_card_window(long long user_index,QWidget *parent) :QDialog(parent), ui(new Ui::Register_new_card_window)
{
    ui->setupUi(this);

    this -> user_index = user_index;

    QPalette palette;

    palette.setColor(QPalette::Button, QColor(231, 19, 82));
    ui -> Cancel_button -> setPalette(palette);

    palette.setColor(QPalette::Button, QColor(34, 245, 73));
    ui -> Register_card_button -> setPalette(palette);

}

Register_new_card_window::~Register_new_card_window()
{
    delete ui;
}

void Register_new_card_window::on_Cancel_button_clicked()
{
    close();
}

void Register_new_card_window::on_Visa_button_toggled(bool checked)
{

    if(checked){

        ui -> Mastercard_button -> setChecked(false);

        ui -> Visa_button -> setStyleSheet("background-color: white;");
        is_mastercard = false;

    }
    else{
        ui -> Mastercard_button -> setChecked(true);

        ui -> Visa_button -> setStyleSheet("background-color: rgba(211, 211, 211, 0.5);");

    }

}


void Register_new_card_window::on_Mastercard_button_toggled(bool checked)
{

    if(checked){

        ui -> Visa_button -> setChecked(false);

        ui -> Mastercard_button -> setStyleSheet("background-color: white;");
        is_mastercard = true;

    }
    else{
        ui -> Visa_button -> setChecked(true);

        ui -> Mastercard_button -> setStyleSheet("background-color: rgba(211, 211, 211, 0.5);");

    }

}


void Register_new_card_window::on_Register_card_button_clicked()
{
    if(is_mastercard){
        meneger.Register_new_Mastercard_card_to_user(user_index);

    }

    else{
        meneger.Register_new_Visa_card_to_user(user_index);
    }

    close();
}

