#include "date.h"

Date::Date()
{

}

QString Date::Next_Day(QString Date){

    std::string Date_string = Date.toStdString();

    std::tm date_tm = {};

    strptime(Date_string.c_str(),"%d.%m.%Y", &date_tm);

    date_tm.tm_mday = date_tm.tm_mday + 1;
    std::time_t time = std::mktime(&date_tm);

    std::tm* next_day = std::localtime(&time);

    char buffer[50];

    std::strftime(buffer, sizeof(buffer), "%d.%m.%Y", next_day);

    QString str(buffer);
    return str;
}

QString Date::Previous_Day(QString Date){

    std::string Date_string = Date.toStdString();

    std::tm date_tm = {};

    strptime(Date_string.c_str(),"%d.%m.%Y", &date_tm);

    date_tm.tm_mday = date_tm.tm_mday - 1;
    std::time_t time = std::mktime(&date_tm);

    std::tm* next_day = std::localtime(&time);



    char buffer[50];

    std::strftime(buffer, sizeof(buffer), "%d.%m.%Y", next_day);

    QString str(buffer);
    return str;
}

bool Date::Is_Leap(QString Year_str){
    bool is_leap = false;

    for(int i = 0, count = 0; i < Year_str.length(); ++i){
        if(Year_str[i] == '.'){
            count++;
        }
        if(count == 2){
            Year_str.remove(0,i + 1);
            break;
        }
    }

    qDebug() <<"Year_str" << Year_str;

    int year = Year_str.toInt();

    if(year % 4 == 0){
        is_leap = true;
    }
    if(year % 100 == 0){
        is_leap = false;
    }
    if(year % 400 == 0){
        is_leap = true;
    }

    return is_leap;
};

short Date::Week_Number(QString Date){

    std::string Date_string = Date.toStdString();

    std::tm date_tm = {};

    strptime(Date_string.c_str(),"%d.%m.%Y", &date_tm);

    short week_number = date_tm.tm_yday / 7 + 1;

    qDebug() << week_number;
    return week_number;
};

int Date::Days_Till_Your_Bithday(QString date){

    std::string dateString = date.toStdString();

    std::time_t current_time = std::time(nullptr);
    local_time = std::localtime(&current_time);

    char buffer[60];
    std::strftime(buffer, sizeof(buffer), "%d.%m", local_time);

    QString Current_Day_String(buffer);

    std::tm date_tm = {};
    date_tm.tm_year = local_time -> tm_year;

    strptime(dateString.c_str(), "%d.%m", &date_tm);

    std::time_t dateT = std::mktime(&date_tm);

    long long seconds_differ = 0;

    qDebug () << "dateT" << dateT;
    qDebug() << "current" << current_time;

    if(current_time < dateT)
      seconds_differ = std::difftime(dateT, current_time);

    else{
      qDebug() << "123";

      if(Date::Is_Leap(Current_Day_String)){
            seconds_differ = 366 * 60 * 60 * 24 - std::difftime(current_time, dateT);
      }
      else{
            seconds_differ = 365 * 60 * 60 * 24 - std::difftime(current_time, dateT);
      }

    }

    return seconds_differ / 60 / 60 / 24;
};

int Date::Duration(QString Date){

    std::string Date_String = Date.toStdString();

    std::time_t current_time = std::time(nullptr);
    local_time = std::localtime(&current_time);

    char buffer[60];
    std::strftime(buffer, sizeof(buffer), "%d.%m.%Y", local_time);

    QString Current_Day_String(buffer);

    std::tm date_tm = {};
    date_tm.tm_year = local_time -> tm_year;

    strptime(Date_String.c_str(), "%d.%m.%Y", &date_tm);

    std::time_t dateT = std::mktime(&date_tm);

    long long seconds_differ = 0;

    if(current_time < dateT)
      seconds_differ = std::difftime(dateT, current_time);

    else{
      qDebug() << "123";

      if(Date::Is_Leap(Current_Day_String)){
            seconds_differ = 366 * 60 * 60 * 24 - std::difftime(dateT, current_time);
      }
      else{
            seconds_differ = 365 * 60 * 60 * 24 - std::difftime(dateT, current_time);
      }

    }

    return seconds_differ / 60 / 60 / 24;
}
