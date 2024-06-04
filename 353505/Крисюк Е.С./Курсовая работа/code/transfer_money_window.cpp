#include "transfer_money_window.h"
#include "ui_transfer_money_window.h"

#include <QDoubleValidator>
#include <QIntValidator>

extern Bank_meneger& meneger;

Transfer_money_window::Transfer_money_window(QWidget *parent) :QDialog(parent),ui(new Ui::Transfer_money_window)
{
    ui->setupUi(this);
    QDoubleValidator* val = new QDoubleValidator(0,99999999,2);
    ui -> Money_line -> setValidator(val);

    QIntValidator* val_int = new QIntValidator(0,999);
    ui -> cvv_line -> setValidator(val);

    ui -> Transfer_button -> setFocus();

}

Transfer_money_window::~Transfer_money_window()
{
    delete ui;
}

void Transfer_money_window::on_Cancel_button_clicked()
{
    close();
}

bool Transfer_money_window::Is_lines_right(){

    bool is_right;

    QRegularExpression app_pattern("\\-.+G");
    QRegularExpression card_patter("^[0-9 ]+$");

    QString first_acc = ui -> From_account_line -> text();
    QString second_acc = ui -> To_account_line -> text();

    int first_index = ui -> comboBox -> currentIndex();
    int second_index = ui -> comboBox_2 -> currentIndex();

    if(first_index == 0){

        if(!card_patter.match(first_acc).hasMatch() || first_acc.length() != 19 || !Luna::Is_Normal(ui -> From_account_line -> text())){

            QMessageBox::warning(nullptr, "Предупреждение", "Ошибка при заполнении первого поля");
            return false;
        }

    }

    else if(first_index == 1){

        if(!app_pattern.match(first_acc).hasMatch() || first_acc.length() != 18){
            QMessageBox::warning(nullptr, "Предупреждение", "Ошибка при заполнении первого поля");
            return false;
        }
    }

    else if(second_index == 0){

        if(!card_patter.match(second_acc).hasMatch() || second_acc.length() != 19 || !Luna::Is_Normal(ui -> From_account_line -> text())){
            QMessageBox::warning(nullptr, "Предупреждение", "Ошибка при заполнении второго поля");
            return false;
        }
    }

    else if(second_index == 1){

        if(!app_pattern.match(second_acc).hasMatch() || second_acc.length() != 18){
            QMessageBox::warning(nullptr, "Предупреждение", "Ошибка при заполнении второго поля");
            return false;
        }
    }

    return true;
}

bool Transfer_money_window::Is_line_exist(int index, QString line, long long &card_index){

    long long user_index = 0;

    if(index == 0){
        return meneger.Is_card_number_exists(line,card_index);
    }
    else{
        return meneger.Is_banking_app_exists(line,card_index);
    }

    return false;
}
void Transfer_money_window::on_Transfer_button_clicked()
{

    if(ui -> From_account_line -> text() == "" || ui -> To_account_line -> text() == "" || ui -> cvv_line -> text() == ""){
        QMessageBox::warning(nullptr, "Предупреждение", "Поля не должны быть пустыми");
    }
    else{

        if(Is_lines_right()){

            int first_index = ui -> comboBox -> currentIndex();
            int second_index = ui -> comboBox_2 -> currentIndex();

            long long card_index = 0;
            long long second = 0;

            if(!Is_line_exist(first_index, ui -> From_account_line -> text(),card_index)){
                QMessageBox::warning(nullptr, "Предупреждение", "Поле 1: Такого номера не существует");
            }
            else{
                if(!Is_line_exist(second_index, ui -> To_account_line -> text(),second)){
                    QMessageBox::warning(nullptr, "Предупреждение", "Поле 2: Такого номера не существует");
                }
                else{

                    if(!Cvv_check(first_index, card_index)){
                        QMessageBox::warning(nullptr, "Предупреждение", "Поле cvv: Неправильный cvv");
                    }
                    else{
                        if(first_index == 0 && second_index == 0){
                            Transactions::Transfer_money_from_card_to_card(ui -> From_account_line -> text(), ui -> Money_line -> text().toDouble(), ui ->To_account_line -> text());

                        }
                        else if(first_index == 0 && second_index == 1){
                            Transactions::Transfer_money_from_card_to_banking_acc(ui -> From_account_line -> text(), ui -> Money_line -> text().toDouble(), ui ->To_account_line -> text());

                        }

                        else if(first_index == 1 && second_index == 0){
                            Transactions::Transfer_money_from_banking_app_to_card(ui -> From_account_line -> text(), ui -> Money_line -> text().toDouble(), ui ->To_account_line -> text());
                        }
                        else {
                            Transactions::Transfer_money_from_banking_app_to_banking_app(ui -> From_account_line -> text(), ui -> Money_line -> text().toDouble(), ui ->To_account_line -> text());
                        }
                        close();
                    }
                }
            }
        }

    }

}

bool Transfer_money_window::Cvv_check(int index, long long card_index){

    QString current_number_name = ui -> From_account_line -> text();

    QString cvv = ui -> cvv_line -> text();


    long long user_index;

    if(index == 0){
        user_index = meneger.Get_user_index_from_card_name(current_number_name);
    }
    else{
        user_index = meneger.Get_user_index_from_bank_app(current_number_name);
    }

    if(cvv != meneger.Get_user_card_cvv(user_index, card_index)){
        qDebug() << cvv << meneger.Get_user_card_cvv(user_index, card_index);
        return false;
    }


    return true;
}

