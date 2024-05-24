#include "bank_account.h"

Bank_account::Bank_account()
{

}

void Bank_account::SetName(long long number){

    QString number_str = QString::number(number);
    number_str = number_str.rightJustified(9,'0');


    QString result;

    result += "96251";

    QString temp = number_str.mid(3, 6);


    QString temp_16 = QString::number((temp.toInt() + 999) * 5,16);

    result += temp_16.toUpper();
    result += '-';

    QString temp_start = number_str.mid(0,3);

    QString temp_start_16 = QString::number(temp_start.toInt() * 5,16);

    result += temp_start_16.toLower();

    result += "G";

    result = result.leftJustified(18,'0');

    name = result;

}

void Bank_account::SetName(QString value){
    name = value;
}

long long Bank_account::Get_acc_number(QString acc_number){
    long long result = -1;

    acc_number.remove(0,5);

    QString first_part;
    QString second_part;

    int index_of_first_separator = acc_number.indexOf('-');

    first_part = acc_number.mid(0,index_of_first_separator);

    int index_of_second_separator = acc_number.indexOf('G');

    second_part = acc_number.mid(index_of_first_separator + 1, index_of_second_separator - index_of_first_separator - 1);


    int first_number = first_part.toInt(nullptr,16) / 5 - 999;
    int second_number = second_part.toInt(nullptr,16) / 5;

    result = second_number * 1000000 + first_number;


    return result;
}

void Bank_account::SetMoney(double number){
    money = number;
}

void Bank_account::Minus_money(double number){
    money -= number;
}

void Bank_account::Plus_money(double number){
    money += number;
}

double Bank_account::Get_current_money(){
    return money;
}

QString Bank_account::GetName(){
    return name;
}

long long Bank_account::Get_transacrions_count(){
    return transactions_list.length();
}

void Bank_account::Add_transaction(QDateTime time,QString message , double money){

    QPair<QPair<QDateTime, QString>, double> temp = {{time, message}, money};

    transactions_list.append(temp);

}


QDateTime Bank_account::Get_transactions_time(long long index){

    return transactions_list[index].first.first;
}

QString Bank_account::Get_transactions_state(long long index){

    return transactions_list[index].first.second;
}
double Bank_account::Get_transactions_money(long long index){

    return transactions_list[index].second;
}


QDateTime Bank_account::Get_last_transactions_time(){

    return transactions_list[transactions_list.length() - 1].first.first;
}

QString Bank_account::Get_last_transactions_state(){

    return transactions_list[transactions_list.length() - 1].first.second;
}

double Bank_account::Get_last_transactions_money(){

    return transactions_list[transactions_list.length() - 1].second;
}
