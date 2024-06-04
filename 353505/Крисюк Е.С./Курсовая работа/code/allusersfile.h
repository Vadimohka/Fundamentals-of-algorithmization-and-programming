#ifndef ALLUSERSFILE_H
#define ALLUSERSFILE_H

#include <QString>
#include <QFile>
#include <QDir>
#include <QDebug>

#include "bank_meneger.h"
#include "sha256.h"
#include "blowfish.h"

class AllUsersFile
{
public:
    AllUsersFile();


    static void Add_user_base_data_to_all_users_file(long long index);

    static void Add_user_personal_data_to_file(long long);

    static void Users_in_file_to_meneger();

    static void Add_card_to_user(long long, long long);


    static double From_QString_to_long_double(QString);
    static QString From_long_double_to_QString(double);

    static void Change_money_in_file(long long, QString, QString);

    static void Add_transaction_to_file(long long, QString);
};

#endif // ALLUSERSFILE_H
