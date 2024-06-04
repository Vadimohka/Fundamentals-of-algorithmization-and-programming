#ifndef BANK_MENEGER_H
#define BANK_MENEGER_H

#include "user.h"
#include "card.h"
#include "allusersfile.h"

#include <QPair>

class Bank_meneger
{
private:
    QList<QPair<User*, QString>> user_list;
    QList<Card*> all_cards_list;

    QString all_users_file_path;
    QString folder_path;


    Bank_meneger();


public:

    static Bank_meneger& getInstance();   // Singleton
    long long GetUserCount();

    void AddUser(User* &, QString &);

    void ChangeUserName(long long, QString &);
    void ChangeUserSurname(long long, QString &);
    void ChangeUserMiddlename(long long, QString &);
    void ChangeUserBirthday(long long, QDate &);
    void ChangeUserEmail(long long, QString &);
    void ChangeUserLogin(long long, QString &);

    QString GetUserName(long long);
    QString GetUserSurname(long long);
    QString GetUserMiddlename(long long);
    QDate GetUserBirthDay(long long);
    QString GetUserLogin(long long);
    QString GetUserEmail(long long);
    QString GetUserId(long long);
    QString GetUserPassword(long long);

    void Set_folder_path(QString &);
    QString Get_folder_path();

    void Set_file_path_to_all_users(QString &);
    QString Get_file_path_to_all_users();

    QString MakeUserId(long long);
    void SetUserId(long long);

    void Debug_user(long long);

    void RemoveUser();
    void RemoveUser(long long index);

    bool Check_email(QString &);

    long long Is_user_login_exist(QString &);
    bool Check_password(QString &, int);

    void Add_to_user_new_Mastercard_card(long long );
    void Add_to_user_new_Visa_card(long long);

    void Set_money_to_bank_account(long long);

    void Minus_money_from_bank_account(long long);
    void Plus_money_to_bank_account(long long);

    Bank_account* Get_account_from_card(QString);
    Bank_account* Get_banking_acc(QString);

    void Add_card_to_scene(long long, long long);

    long long Get_all_card_count();
    long long Get_user_card_count(long long);

    QString Get_user_card_number(long long, long long);
    double Get_user_card_money(long long, long long);

    QString Get_user_card_pin(long long, long long);
    QString Get_user_card_cvv(long long, long long);
    QString Get_user_card_month(long long, long long);
    QString Get_user_card_year(long long, long long);

    QString Get_user_card_banking_app_name(long long, long long);

    void Register_new_Mastercard_card_to_user(long long);
    void Register_new_Visa_card_to_user(long long);

    void Set_card_to_user(long long, Card*);
    void Add_card(Card*);

    void Set_transaction_to_bank_acc(long long, QDateTime, QString, double);

    Card* Get_user_card(long long, long long);

    bool Is_card_number_exists(QString, long long &);
    bool Is_banking_app_exists(QString, long long &);

    long long Get_user_index_from_card_name(QString);
    long long Get_user_index_from_bank_app(QString);

};

#endif // BANK_MENEGER_H
