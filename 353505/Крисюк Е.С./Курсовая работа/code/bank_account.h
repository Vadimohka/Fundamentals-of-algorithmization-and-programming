#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <QString>
#include <QDebug>
#include <QList>
#include <QPair>
#include <QDateTime>


class Bank_account
{
private:
    QString name;
    double money = 0;

    QList<QPair<QPair<QDateTime, QString>, double>> transactions_list;


public:
    Bank_account();

    void SetName(long long);
    void SetName(QString);
    static long long Get_acc_number(QString);

    void SetMoney(double);
    void Minus_money(double);
    void Plus_money(double);

    double Get_current_money();
    QString GetName();

    void Add_transaction(QDateTime, QString, double);
    long long Get_transacrions_count();

    QDateTime Get_transactions_time(long long);
    QString Get_transactions_state(long long);
    double Get_transactions_money(long long);

    QDateTime Get_last_transactions_time();
    QString Get_last_transactions_state();
    double Get_last_transactions_money();

};

#endif // BANK_ACCOUNT_H
