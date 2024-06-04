#include "transactions.h"

extern Bank_meneger& meneger;

Transactions::Transactions()
{

}

int Transactions::Transfer_money_from_card_to_card(QString from_card_number, double money, QString to_card_number){

    Bank_account* from_acc = meneger.Get_account_from_card(from_card_number);

    Bank_account* to_acc = meneger.Get_account_from_card(to_card_number);

    long long from_user_index = meneger.Get_user_index_from_card_name(from_card_number);
    long long to_user_index = meneger.Get_user_index_from_card_name(to_card_number);

    int result = do_transaction(from_user_index,to_user_index,from_acc, money, to_acc);

    return result;

}

int Transactions::Transfer_money_from_card_to_banking_acc(QString from_card_number, double money, QString banking_acc_number){

    Bank_account* from_acc = meneger.Get_account_from_card(from_card_number);
    Bank_account* to_acc = meneger.Get_banking_acc(banking_acc_number);

    long long from_user_index = meneger.Get_user_index_from_card_name(from_card_number);
    long long to_user_index = meneger.Get_user_index_from_bank_app(banking_acc_number);

    int result = do_transaction(from_user_index,to_user_index,from_acc, money, to_acc);

    return result;
}

int Transactions::Transfer_money_from_banking_app_to_card(QString banking_acc_number, double money, QString to_card_number){

    Bank_account* from_acc = meneger.Get_banking_acc(banking_acc_number);

    Bank_account* to_acc = meneger.Get_account_from_card(to_card_number);

    long long from_user_index = meneger.Get_user_index_from_bank_app(banking_acc_number);
    long long to_user_index = meneger.Get_user_index_from_card_name(to_card_number);

    int result = do_transaction(from_user_index,to_user_index,from_acc, money, to_acc);

    return result;
}

int Transactions::Transfer_money_from_banking_app_to_banking_app(QString from_banking_acc_number, double money, QString to_banking_acc_number){

    Bank_account* from_acc = meneger.Get_banking_acc(from_banking_acc_number);

    Bank_account* to_acc = meneger.Get_banking_acc(to_banking_acc_number);

    long long from_user_index = meneger.Get_user_index_from_bank_app(from_banking_acc_number);
    long long to_user_index = meneger.Get_user_index_from_bank_app(to_banking_acc_number);

    int result = do_transaction(from_user_index,to_user_index,from_acc, money, to_acc);

    return result;
}


int Transactions::do_transaction(long long from_user_index,long long to_user_index , Bank_account* from_acc, double money, Bank_account* to_acc){

    int result = 0;

    QMessageBox* box = new QMessageBox();
    box -> setWindowTitle("Error");


    if(from_acc == to_acc){
        box -> setText("Невозможен перевод на одинаковые номера");
        box -> exec();

        return 3;
    }

    if(from_acc -> Get_current_money() < money){

        box -> setText("Недостаточно средств");
        box -> exec();

        return 2;
    }

    double to_acc_current_money = to_acc -> Get_current_money();
    double from_acc_current_money = from_acc -> Get_current_money();

    double result_money = to_acc_current_money + money;

    to_acc -> Plus_money(money);
    from_acc -> Minus_money(money);


    if(result_money != to_acc -> Get_current_money()){
        qDebug() << result_money << to_acc -> Get_current_money();

        result = 1;

        to_acc -> SetMoney(to_acc_current_money);

        from_acc -> SetMoney(from_acc_current_money);

        box -> setText("Банковская ошибка");
        box -> exec();
    }

    else{
        from_acc -> Add_transaction(QDateTime::currentDateTime(), "Перевод средств", money);

        long long index = Bank_account::Get_acc_number(from_acc -> GetName()) - 1;

        QString card_number = meneger.Get_user_card_number(meneger.Get_user_index_from_bank_app(from_acc -> GetName()), index);

        long long first_index = meneger.Get_user_index_from_card_name(card_number);
        AllUsersFile::Add_transaction_to_file(first_index, card_number);

        AllUsersFile::Change_money_in_file(from_user_index, card_number ,QString::number(from_acc -> Get_current_money()));

        index = Bank_account::Get_acc_number(to_acc -> GetName()) - 1;

        card_number = meneger.Get_user_card_number(meneger.Get_user_index_from_bank_app(to_acc -> GetName()), index);

        to_acc -> Add_transaction(QDateTime::currentDateTime(), "Зачисление", money);
        long long second_index = meneger.Get_user_index_from_card_name(card_number);

        AllUsersFile::Add_transaction_to_file(second_index, card_number);
        AllUsersFile::Change_money_in_file(to_user_index, card_number ,QString::number(to_acc -> Get_current_money()));

    }

    return result;
}

int Transactions::Add_money_card(QString card_number, double money){
    int result = 0;

    Bank_account* account = meneger.Get_account_from_card(card_number);

    double current_money = account -> Get_current_money();

    double result_money = money + current_money;

    account -> Plus_money(money);

    if(result_money != account -> Get_current_money()){

        result = 1;

        QMessageBox* box = new QMessageBox();
        box -> setWindowTitle("Error");

        box -> setText("Банковская ошибка");
        box -> exec();

        account -> SetMoney(current_money);

    }
    else{
        account -> Add_transaction(QDateTime::currentDateTime(), "Зачисление", money);
    }

    return result;
}

int Transactions::Minus_money_card(QString card_number, double money, QString message){
    int result = 0;

    Bank_account* account = meneger.Get_account_from_card(card_number);

    double current_money = account -> Get_current_money();

    double result_money = current_money - money;

    if(result_money < 0){
        QMessageBox* box = new QMessageBox();
        box -> setWindowTitle("Error");

        box -> setText("недостаточно средств");
        box -> exec();

        return 2;
    }

    account -> Minus_money(money);

    if(result_money != account -> Get_current_money()){

        result = 1;

        QMessageBox* box = new QMessageBox();
        box -> setWindowTitle("Error");

        box -> setText("Банковская ошибка");
        box -> exec();

        account -> SetMoney(current_money);

    }
    else{
        account -> Add_transaction(QDateTime::currentDateTime(), message, money);
    }

    return result;
}
