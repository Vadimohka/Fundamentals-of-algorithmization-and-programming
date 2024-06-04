#ifndef CARD_H
#define CARD_H

#include <QString>
#include <QRandomGenerator>
#include <QDate>


#include "luna.h"
#include "bank_account.h"

class Card
{
private:

    QString card_number;
    Bank_account* bank_account;

    QString pin;

    QString month;
    QString year;

    QString cvv;

    void create_card_number(long long, QString);

    void create_cvv();

    void create_pin();

    void create_date();

    void create_bank_account(long long);

public:

    Card();

    void Create_Mastercard_card(long long);
    void Create_Visa_card(long long);

    void Set_money_to_bank_account(double);
    void Minus_money_from_bank_account(double);
    void Plus_money_to_bank_account(double);

    QString GetCardNumber();
    QString GetPin();
    QString GetCvv();
    QString GetMonth();
    QString GetYear();


    void Set_card_number(QString);
    void SetPin(QString);
    void SetCvv(QString);
    void SetMonth(QString);
    void SetYear(QString);

    void Set_bank_account_name(QString);

    double Get_current_money();
    QString Get_banking_app_name();

    long long Get_banking_app_transsactions_count();

    void Add_transaction(QDateTime, QString, double);

    Bank_account* Get_bank_account();


};

#endif // CARD_H
