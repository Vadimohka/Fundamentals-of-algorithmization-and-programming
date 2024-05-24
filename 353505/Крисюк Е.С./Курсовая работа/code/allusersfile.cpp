
#include "allusersfile.h"
#include <iostream>

extern Bank_meneger& meneger;

AllUsersFile::AllUsersFile()
{

}

void AllUsersFile::Add_user_base_data_to_all_users_file(long long index){

    QString file_path = meneger.Get_file_path_to_all_users();


    QFile file(file_path);

    QString login = meneger.GetUserLogin(index);
    QString password = meneger.GetUserPassword(index);

    login = SHA256::GetSha256(login);

    if(file.open(QIODevice::Append | QIODevice::Text)){

        QTextStream stream(&file);
        stream << login << '\n';
        stream << password << '\n';

        file.close();

    }
    else{
        qDebug() << "Add user file dont open";
    }
}

void AllUsersFile::Add_user_personal_data_to_file(long long index){

    QString id = "/" + meneger.GetUserId(index);

    QString new_user_folder_path = meneger.Get_folder_path() + id;
    QString new_user_file_path = meneger.Get_folder_path() + id + id;

    QDir dir(new_user_folder_path);

    if(!dir.exists()){

        dir.mkdir(new_user_folder_path);

    }

    QFile file(new_user_file_path);

    if(file.open(QIODevice::Append | QIODevice::Text)){
        QTextStream stream(&file);

        stream << BlowFish::Encrypt(meneger.GetUserSurname(index)) << '\n';
        stream << BlowFish::Encrypt(meneger.GetUserName(index)) << '\n';
        stream << BlowFish::Encrypt(meneger.GetUserMiddlename(index)) << '\n';
        stream << BlowFish::Encrypt(meneger.GetUserBirthDay(index).toString("dd.MM.yyyy")) << '\n';
        stream << BlowFish::Encrypt(meneger.GetUserEmail(index)) << '\n';
        stream << BlowFish::Encrypt(meneger.GetUserLogin(index)) << '\n';
        stream << BlowFish::Encrypt(meneger.GetUserId(index)) << '\n';

        file.close();
    }

}

void AllUsersFile::Users_in_file_to_meneger(){

    int count = 0;

    QString path = meneger.Get_file_path_to_all_users();
    QFile file(path);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);

        QString line;

        while(!stream.atEnd()){
            line = stream.readLine();

            User* user = new User();
            user -> setLogin(line);

            line = stream.readLine();

            QString password = line;

            QString person_path = "/" + meneger.MakeUserId(count);
            QString user_folder_path = meneger.Get_folder_path() + person_path;



            QString path = user_folder_path + person_path;

            QFile person_file(path);

            if(person_file.open(QIODevice::ReadOnly | QIODevice::Text)){
                QTextStream person_file_stream(&person_file);

                QString surname = BlowFish::Decrypt(person_file_stream.readLine());
                QString name = BlowFish::Decrypt(person_file_stream.readLine());
                QString middlename = BlowFish::Decrypt(person_file_stream.readLine());
                QDate date = QDate::fromString(BlowFish::Decrypt(person_file_stream.readLine()), "dd.MM.yyyy");
                QString email = BlowFish::Decrypt(person_file_stream.readLine());
                QString login = BlowFish::Decrypt(person_file_stream.readLine());
                QString id = BlowFish::Decrypt(person_file_stream.readLine());


                user -> setName(name);
                user -> setSurname(surname);
                user -> setMiddlename(middlename);
                user -> setBirthday(date);
                user -> setEmail(email);
                user -> setLogin(login);
                user -> setId(id);
                meneger.AddUser(user,password);

                count++;
            }

            QString card_path = user_folder_path + "/cards";


            QDir card_dir(card_path);

            if(card_dir.exists()){

                QStringList files_list = card_dir.entryList();
                QString folder_name;
                QString file_name;

                for(int i = 0; i < files_list.length(); ++i){
                    if(files_list[i] == "." || files_list[i] == ".."){
                        continue;
                    }

                    folder_name = card_path + "/" + files_list[i];

                    QDir card_dir(folder_name);

                    if(!card_dir.exists()){
                        card_dir.mkdir(folder_name);
                    }
                    file_name = folder_name + "/" + files_list[i];

                    QFile card_file(file_name);

                    Card* card = new Card();;

                    QString transaction_folder_path = folder_name + "/transactions";

                    QDir trans_dir(transaction_folder_path);

                    if(trans_dir.exists()){

                        QString trans_file_path = transaction_folder_path + "/Transactions";

                        QFile trans_file(trans_file_path);

                        if(trans_file.open(QIODevice::ReadOnly | QIODevice:: Text)){

                            QTextStream trans_stream(&trans_file);

                            QString date_str, state_str, money_str;

                            while(!trans_stream.atEnd()){
                                date_str = BlowFish::Decrypt(trans_stream.readLine());
                                state_str = BlowFish::Decrypt(trans_stream.readLine());
                                money_str = BlowFish::Decrypt(trans_stream.readLine());

                                QDateTime date = QDateTime::fromString(date_str,"hh:mm:ss dd-MM-yyyy");
                                double money = From_QString_to_long_double(money_str);

                                card -> Add_transaction(date, state_str, money);

                            }
                            trans_file.close();
                        }
                    }

                    if(card_file.open(QIODevice::ReadOnly | QIODevice::Text)){

                        QTextStream card_stream(&card_file);

                        QString card_number = BlowFish::Decrypt(card_stream.readLine());

                        QString banking_app_number = BlowFish::Decrypt(card_stream.readLine());

                        QString pin = BlowFish::Decrypt(card_stream.readLine());
                        QString cvv = BlowFish::Decrypt(card_stream.readLine());
                        QString year = BlowFish::Decrypt(card_stream.readLine());
                        QString month = BlowFish::Decrypt(card_stream.readLine());

                        double money = From_QString_to_long_double(BlowFish::Decrypt(card_stream.readLine()));

                        card -> Set_card_number(card_number);
                        card -> Set_bank_account_name(banking_app_number);
                        card -> SetPin(pin);
                        card -> SetCvv(cvv);
                        card -> SetYear(year);
                        card -> SetMonth(month);
                        card -> Set_money_to_bank_account(money);

                        meneger.Set_card_to_user(meneger.GetUserCount() - 1, card);
                        meneger.Add_card(card);

                        card_file.close();

                    }
                    else{
                        qDebug() << "not open";
                    }

                }
            }
        }

        file.close();
    }
}

void AllUsersFile::Add_card_to_user(long long user_index, long long card_index){

    QString id = "/" + meneger.GetUserId(user_index);

    QString folder_path_to_user = meneger.Get_folder_path() + id;


    QString cards_folder_path = folder_path_to_user + "/cards";

    QDir dir(cards_folder_path);

    if(!dir.exists()){

        dir.mkdir(cards_folder_path);

    }


    QString path_to_card_folder = cards_folder_path + "/" + meneger.Get_user_card_number(user_index, card_index);

    QDir card_dir(path_to_card_folder);

    if(!card_dir.exists()){
        card_dir.mkdir(path_to_card_folder);
    }

    QString path_to_card = path_to_card_folder +  "/" + meneger.Get_user_card_number(user_index, card_index);

    QFile file(path_to_card);

    if(file.open(QIODevice::Append | QIODevice::Text)){
        QTextStream stream(&file);

        stream << BlowFish::Encrypt(meneger.Get_user_card_number(user_index, card_index)) << '\n';
        stream << BlowFish::Encrypt(meneger.Get_user_card_banking_app_name(user_index, card_index)) << '\n';

        stream << BlowFish::Encrypt(meneger.Get_user_card_pin(user_index, card_index)) << '\n';
        stream << BlowFish::Encrypt(meneger.Get_user_card_cvv(user_index, card_index)) << '\n';

        stream << BlowFish::Encrypt(meneger.Get_user_card_year(user_index, card_index)) << '\n';
        stream << BlowFish::Encrypt(meneger.Get_user_card_month(user_index, card_index)) << '\n';

        stream << BlowFish::Encrypt(From_long_double_to_QString(meneger.Get_user_card_money(user_index, card_index))) << '\n';

        file.close();

    }

    else{
        qDebug() << "файл не открылся";
    }

}

QString AllUsersFile::From_long_double_to_QString(double number){

    return QString::number(number);
}

double AllUsersFile::From_QString_to_long_double(QString str){

    double result = 0;

    int dot_index = str.indexOf('.');

    if(dot_index == -1){
        dot_index = str.length();
    }

    QString int_part_str = str.mid(0,dot_index);
    result += int_part_str.toLongLong();

    QString double_part_str = str.mid(dot_index + 1, str.length()).leftJustified(2,'0');


    double double_part = double_part_str.toInt() / 100.0;

    result += double_part;

    return result;
}


void AllUsersFile::Change_money_in_file(long long user_index, QString card_number, QString money){

    QString id = "/" + meneger.GetUserId(user_index);

    QString path = meneger.Get_folder_path() + id + "/cards" + "/" + card_number + "/" + card_number;

    QFile file(path);
    qDebug() << "path" << path;

    money = BlowFish::Encrypt(money);

    if(file.open(QIODevice::ReadWrite | QIODevice::Text)){
        QTextStream stream(&file);

        QString line;

        qint64 last_pos = 0;

        qint64 pos = 0;

        while(!stream.atEnd()){

            line = stream.readLine();

            last_pos = pos;
            pos += line.toUtf8().length() + 1;
        }

        file.resize(last_pos);

        stream << money;

        file.close();
    }
}

void AllUsersFile::Add_transaction_to_file(long long user_index, QString card_number){

    QString id = "/" + meneger.GetUserId(user_index);

    QString folder_path = meneger.Get_folder_path() + id + "/cards" + "/" + card_number + "/transactions";

    QDir dir(folder_path);

    if(!dir.exists()){
        dir.mkdir(folder_path);
    }

    QString file_path = folder_path + "/Transactions";

    qDebug() << file_path;
    QFile file(file_path);

    if(file.open(QIODevice::Append | QIODevice::Text)){
        QTextStream stream(&file);

        Bank_account* account = meneger.Get_account_from_card(card_number);

        stream << BlowFish::Encrypt(account -> Get_last_transactions_time().toString("hh:mm:ss dd-MM-yyyy")) << '\n';
        stream << BlowFish::Encrypt(account -> Get_last_transactions_state()) << '\n';
        stream << BlowFish::Encrypt(QString::number(account -> Get_last_transactions_money())) << '\n';

        file.close();
    }
    else{
        qDebug() << "Not open";
    }

}
