#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "card.h"
#include "bank_meneger.h"
#include <QString>
#include <QMessageBox>
\
#include "allusersfile.h"

class Transactions
{
private :
    static int do_transaction(long long,long long,Bank_account*, double, Bank_account*);
public:
    Transactions();

    static int Transfer_money_from_card_to_card(QString , double, QString);
    static int Transfer_money_from_card_to_banking_acc(QString, double, QString);
    static int Transfer_money_from_banking_app_to_card(QString, double, QString);
    static int Transfer_money_from_banking_app_to_banking_app(QString, double, QString);

    static int Add_money_card(QString, double);
    static int Minus_money_card(QString, double, QString);
};

#endif // TRANSACTIONS_H
