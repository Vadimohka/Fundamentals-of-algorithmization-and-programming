#include "bank_meneger.h"

Bank_meneger::Bank_meneger()
{

}

Bank_meneger& Bank_meneger::getInstance(){
    static Bank_meneger meneger;
    return meneger;
}

long long Bank_meneger::GetUserCount(){
    return user_list.length();
}

void Bank_meneger::Set_file_path_to_all_users(QString &path){
    all_users_file_path = path;
}

QString Bank_meneger::Get_file_path_to_all_users(){
    return all_users_file_path;
}

void Bank_meneger::Set_folder_path(QString &path){
    folder_path = path;
}

QString Bank_meneger::Get_folder_path(){
    return folder_path;
}

void Bank_meneger::AddUser(User* &user, QString &password){

    QPair<User*, QString> temp;

    temp.first = user;
    temp.second = password;

    user_list.append(temp);
}

void Bank_meneger::RemoveUser(){
    user_list.removeLast();
}

void Bank_meneger::RemoveUser(long long index){
    user_list.removeAt(index);
}

void Bank_meneger::ChangeUserName(long long index, QString &str){
    user_list[index].first -> setName(str);
}
void Bank_meneger::ChangeUserSurname(long long index, QString &str){
    user_list[index].first -> setSurname(str);
}
void Bank_meneger::ChangeUserMiddlename(long long index, QString &str){
    user_list[index].first -> setMiddlename(str);
}
void Bank_meneger::ChangeUserBirthday(long long index, QDate &date){
    user_list[index].first -> setBirthday(date);
}
void Bank_meneger::ChangeUserEmail(long long index, QString &str){
    user_list[index].first -> setEmail(str);
}

QString Bank_meneger::MakeUserId(long long index){

    QString temp_str = QString::number(index + 1);

    for(long long i = temp_str.length(); i < 16; ++i){
        temp_str.insert(0, "0");
    }
    return temp_str;

}

void Bank_meneger::SetUserId(long long index){
    QString temp_str = MakeUserId(index);

    user_list[index].first -> setId(temp_str);
}

void Bank_meneger::Debug_user(long long index){

    user_list[index].first -> Debug();
}


QString Bank_meneger::GetUserName(long long index){
    return user_list[index].first -> GetName();
}
QString Bank_meneger::GetUserSurname(long long index){
    return user_list[index].first -> GetSurname();
}
QString Bank_meneger::GetUserMiddlename(long long index){
    return user_list[index].first -> GetMiddlename();
}
QDate Bank_meneger::GetUserBirthDay(long long index){
    return user_list[index].first -> GetBirthday();
}
QString Bank_meneger::GetUserLogin(long long index){
    return user_list[index].first -> GetLogin();
}
QString Bank_meneger::GetUserEmail(long long index){
    return user_list[index].first -> GetEmail();
}
QString Bank_meneger::GetUserId(long long index){
    return user_list[index].first -> GetId();
}
QString Bank_meneger::GetUserPassword(long long index){
    return user_list[index].second;
}

bool Bank_meneger::Check_email(QString &email){
    bool is_true = true;

    QString temp;

    for(int i = 0; i < user_list.length(); ++i){
        temp = user_list[i].first -> GetEmail();

        if(temp == email){
            is_true = false;
            break;
        }
    }
    return is_true;
}

long long Bank_meneger::Is_user_login_exist(QString &login){
    int index = -1;

    QString temp;

    for(int i = 0; i < user_list.length(); ++i){
        temp = user_list[i].first -> GetLogin();

        if(login == temp){
            index = i;
            break;
        }
    }

    return index;
}

bool Bank_meneger::Check_password(QString &password, int index){

    return (user_list[index].second == password);
}


void Bank_meneger::Add_to_user_new_Mastercard_card(long long index){
    Card* card = new Card();

    card -> Create_Mastercard_card(all_cards_list.length() + 1);

    user_list[index].first -> AddCard(card);
    all_cards_list.append(card);

}

void Bank_meneger::Add_to_user_new_Visa_card(long long index){
    Card* card = new Card();

    card -> Create_Visa_card(all_cards_list.length() + 1);

    user_list[index].first -> AddCard(card);
    all_cards_list.append(card);

}


void Bank_meneger::Set_money_to_bank_account(long long money){

}


Bank_account* Bank_meneger::Get_account_from_card(QString number_of_card){
    number_of_card.remove(' ');

    QString temp = number_of_card.mid(6,9);

    int index_of_last_zero = 0;

    for(int i = 0; i < number_of_card.length(); ++i){
        if(temp[i] == '0'){
            index_of_last_zero++;
        }
        else{
            break;
        }
    }


    temp.remove(0,index_of_last_zero);

    return all_cards_list.at(temp.toInt() - 1) -> Get_bank_account();
}

Bank_account* Bank_meneger::Get_banking_acc(QString number){

    long long index = Bank_account::Get_acc_number(number);
    return all_cards_list.at(index - 1) -> Get_bank_account();
}

long long Bank_meneger::Get_all_card_count(){
    return all_cards_list.length();
}

long long Bank_meneger::Get_user_card_count(long long index){
    return user_list[index].first -> Get_cards_count();
}


QString Bank_meneger::Get_user_card_number(long long index, long long card_index){
    return user_list[index].first -> Get_card_number(card_index);
}


double Bank_meneger::Get_user_card_money(long long index, long long card_index){
    return user_list[index].first -> Get_card_money(card_index);
}

QString Bank_meneger::Get_user_card_pin(long long index, long long card_index){
    return user_list[index].first -> Get_card_pin(card_index);
}

QString Bank_meneger::Get_user_card_cvv(long long index, long long card_index){
    return user_list[index].first -> Get_card_cvv(card_index);
}
QString Bank_meneger::Get_user_card_month(long long index, long long card_index){
    return user_list[index].first -> Get_card_month(card_index);
}
QString Bank_meneger::Get_user_card_year(long long index, long long card_index){
    return user_list[index].first -> Get_card_year(card_index);
}
QString Bank_meneger::Get_user_card_banking_app_name(long long index, long long card_index){
    return user_list[index].first -> Get_card_banking_app_name(card_index);
}

void Bank_meneger::Set_card_to_user(long long index, Card* card){
    user_list[index].first -> AddCard(card);
}

void Bank_meneger::Add_card(Card* card){
    all_cards_list.append(card);
}
void Bank_meneger::Register_new_Mastercard_card_to_user(long long index){

    Card* card = user_list[index].first -> Register_new_Mastercard_card(all_cards_list.length() + 1);

    AllUsersFile::Add_card_to_user(index, user_list[index].first -> Get_cards_count() - 1);

    all_cards_list.append(card);


}

bool Bank_meneger::Is_card_number_exists(QString number, long long &card_index){
    for(long long i = 0; i < all_cards_list.length(); ++i){
        if(number == all_cards_list[i] -> GetCardNumber()){
            card_index = i;
            return true;

        }
    }
    return false;
}

bool Bank_meneger::Is_banking_app_exists(QString number, long long& card_index){
    for(long long i = 0; i < all_cards_list.length(); ++i){
        if(number == all_cards_list[i] -> Get_banking_app_name()){
            card_index = i;
            return true;
        }
    }
    return false;
}

long long Bank_meneger::Get_user_index_from_card_name(QString name){

    for(long long i = 0; i < user_list.length(); ++i){
        for(long long j = 0; j < user_list[i].first -> Get_cards_count(); ++j){
            if(user_list[i].first -> Get_card_number(j) == name){
                return i;
            }
        }
    }
    return -1;
}

long long Bank_meneger::Get_user_index_from_bank_app(QString name){
    for(long long i = 0; i < user_list.length(); ++i){
        for(long long j = 0; j < user_list[i].first -> Get_cards_count(); ++j){
            if(user_list[i].first -> Get_card_banking_app_name(j) == name){
                return i;
            }
        }
    }
    return -1;
}

Card* Bank_meneger::Get_user_card(long long index, long long card_index){
    return user_list[index].first -> Get_card(card_index);
}

void Bank_meneger::Register_new_Visa_card_to_user(long long index){

    Card* card = user_list[index].first -> Register_new_Visa_card(all_cards_list.length() + 1);

    AllUsersFile::Add_card_to_user(index, user_list[index].first -> Get_cards_count() - 1);

    all_cards_list.append(card);
}
