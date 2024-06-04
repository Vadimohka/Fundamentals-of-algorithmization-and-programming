#include "card.h"

Card::Card()
{
    bank_account = new Bank_account();
}

void Card::Create_Mastercard_card(long long card_number){

    create_bank_account(card_number);

    create_card_number(card_number, "5");

    create_cvv();
    create_pin();
    create_date();

}

void Card::Create_Visa_card(long long card_number){

    create_bank_account(card_number);

    create_card_number(card_number, "4");

    create_cvv();
    create_pin();
    create_date();

}

void Card::Set_money_to_bank_account(double money){
    bank_account -> SetMoney(money);
}

void Card::Plus_money_to_bank_account(double money){
    bank_account -> Plus_money(money);
}

void Card::Minus_money_from_bank_account(double money){
    bank_account -> Minus_money(money);
}


void Card::create_card_number(long long temp_number, QString first_symbol) {
    QString number;

    number.append(first_symbol);
    number.append("1");

    number.append("5269");

    number.append(QString::number(temp_number).rightJustified(9,'0'));

    number.append(Luna::GetNumber(number));

    number.insert(4," ");
    number.insert(9," ");
    number.insert(14," ");

    card_number = number;
}

void Card::create_bank_account(long long number){

    bank_account -> SetName(number);

    bank_account -> SetMoney(0);

}

void Card::create_cvv(){
    cvv = QString::number(QRandomGenerator::global() -> bounded(1,999)).rightJustified(3,'0');

}

void Card::create_pin(){
    pin = QString::number(QRandomGenerator::global() -> bounded(1,9999)).rightJustified(4,'0');

}

void Card::create_date(){
    month = QString::number(QDate::currentDate().month()).rightJustified(2,'0');

    year = QString::number(QDate::currentDate().year() + 4).rightJustified(2,'0');
}


QString Card::GetCardNumber(){
    return card_number;
}

QString Card::GetCvv(){
    return cvv;
}

QString Card::GetPin(){
    return pin;
}

QString Card::GetMonth(){
    return month;
}

QString Card::GetYear(){
    return year;
}

double Card::Get_current_money(){

    return bank_account -> Get_current_money();
}

QString Card::Get_banking_app_name(){
    return bank_account -> GetName();
}

Bank_account* Card::Get_bank_account(){
    return bank_account;
}

void Card::Set_card_number(QString value){
    card_number = value;
}

void Card::SetPin(QString value){
    pin = value;
}
void Card::SetCvv(QString value){
    cvv = value;
}
void Card::SetMonth(QString value){
    month = value;
}
void Card::SetYear(QString value){
    year = value;
}

long long Card::Get_banking_app_transsactions_count() {
    return bank_account -> Get_transacrions_count();
}

void Card::Set_bank_account_name(QString value){
    bank_account -> SetName(value);
}

void Card::Add_transaction(QDateTime time, QString str, double money) {
    bank_account -> Add_transaction(time, str, money);
}
