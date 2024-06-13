#include "date.h"
#include "qmessagebox.h"

Date::Date()
{

}

Date::~Date()
{

}

Date Date::NextDay() const
{
    Date nextDay = *this;
    ++nextDay.day;
    if(((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2 && nextDay.day==30){
        nextDay.day=1;
        nextDay.month = 3;
    }
    else if((year%4 != 0 || year % 100 == 0) && month == 2 && nextDay.day==29){
        nextDay.day=1;
        nextDay.month = 3;
    }
    else if(month == 12 && nextDay.day ==32){
        ++nextDay.year;
        nextDay.month = 1;
        nextDay.day = 1;
    }
    else if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && nextDay.day==32){
        ++nextDay.month;
        nextDay.day = 1;
    }
    else if((month == 4 || month == 6 || month == 9 || month == 11) && nextDay.day==31){
        ++nextDay.month;
        nextDay.day = 1;
    }
    return nextDay;
}

Date Date::PreviousDay() const
{
    Date previousDay = *this;
    --previousDay.day;
    if(previousDay.day == 0){
        if(((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 3){
            previousDay.day=29;
            previousDay.month = 2;
        }
        else if((year%4 != 0 || year % 100 == 0) && month == 3){
            previousDay.day=28;
            previousDay.month = 2;
        }
        else if(month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
            previousDay.day=30;
            --previousDay.month;
        }
        else if(month ==4 || month == 6 || month == 8 || month == 9 || month == 11){
            previousDay.day=31;
            --previousDay.month;
        }
        else if(month == 1){
            --previousDay.year;
            previousDay.month = 12;
            previousDay.day = 31;
        }

    }
    return previousDay;
}

bool Date::IsLeap() const
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

short Date::WeekNumber() const
{
    std::chrono::system_clock::time_point today = std::chrono::system_clock::now();
    std::time_t tt = std::chrono::system_clock::to_time_t(today);
    std::tm local_tm = *std::localtime(&tt);
    local_tm.tm_year = year - 1900;
    local_tm.tm_mon = month - 1;
    local_tm.tm_mday = day;
    std::time_t tt_new = std::mktime(&local_tm);
    int weekNumber = (local_tm.tm_yday + 7 - local_tm.tm_wday) / 7;
    return weekNumber;
}

int Date::DaysTillYourBirthday(Date birthdayDate) const
{
    std::tm date1 = {0,0,0,day,month - 1,year - 1900};
    std::tm date2 = {0,0,0,birthdayDate.day,birthdayDate.month - 1,birthdayDate.year - 1900};
    std::time_t time1 = std::mktime(&date1);
    std::time_t time2 = std::mktime(&date2);
    double days = std::difftime(time2, time1)/60/60/24;
    return (int)days;
}

int Date::Durration(Date date) const
{
    std::tm date1 = {0,0,0,day,month - 1,year - 1900};
    std::tm date2 = {0,0,0,date.day,date.month - 1,date.year - 1900};
    std::time_t time1 = std::mktime(&date1);
    std::time_t time2 = std::mktime(&date2);
    double days = std::difftime(time2, time1)/60/60/24;
    return (int)days;
}

void Date::QStringToDate(QString date)
{
    QString string = date;
    bool correct = true;
    QString substr;
    int dot = 0;
    for (int i = 0; i<string.length(); ++i){
        if((string[i]<'0' || string[i]>'9') && string[i]!='.'){
            correct = false;
        }
        if(string[i]=='.'){
            ++dot;
        }
    }
    if(dot>2){
        correct = false;
    }
    if(string.length() > 10 || string.length() < 5){
        correct = false;
    }
    else if(correct){
        int dot = 0;
        for(int i = string.length() - 1; i>=0 && string[i]!='.'; --i){
            ++dot;
        }

        if(dot>4){
            correct = false;
        }
        else{
            while(dot<4){
                string.insert(string.length() - dot, '0');
                dot++;
            }
        }

        dot = 0;
        for(int i = string.length() - 6; string[i]!='.' && i>=0; --i){
            dot++;
        }

        if(dot>2){
            correct = false;
        }
        else{
            while(dot<2){
                string.insert(string.length() - dot - 5, '0');
                dot++;
            }
        }
        dot = 0;
        for(int i = 0; string[i]!='.' && i <= string.length(); ++i){
            dot++;
        }

        if(dot>2){
            correct = false;
        }
        else{
            while(dot<2){
                string.insert(0, '0');
                dot++;
            }
        }
        substr = string.mid(0, 2);
        day = substr.toInt();
        substr = string.mid(3, 2);
        month = substr.toInt();
        substr = string.mid(6, 4);
        year = substr.toInt();
        if(month>12 || month < 0 || year < 0){
            correct = false;
        }

        if(day<0){
            correct = false;
        }
        else if(((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)  && month == 2 && day > 29){
            correct = false;
        }
        else if((year % 4 != 0 || year % 100 == 0) && year%400 != 0 && month == 2 && day > 28){
            correct = false;
        }
        else if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day>31){
            correct = false;
        }
        else if((month == 4 || month == 6 || month == 9 || month == 11) && day>30){
            correct = false;
        }
    }
    if(correct){
        substr = string.mid(0, 2);
        day = substr.toInt();
        substr = string.mid(3, 2);
        month = substr.toInt();
        substr = string.mid(6, 4);
        year = substr.toInt();
    }
    else{
        day = month = year = 0;
        QMessageBox::critical(nullptr, "Error", "INPUT ERROR!\nPlease, retry input");
    }
}

QString Date::DateToQString() const
{
    QString string;
    int Year = 0;
    if(day<10){
        string += '0';
    }
    string += QString::number(day) + '.' ;
    if(month<10){
        string += '0';
    }
    string += QString::number(month) + '.' ;
    if(year < 10){
        string += "000";
    }
    else if(year < 100){
        string += "00";
    }
    else if(year < 1000){
        string += '0';
    }
    if(year < 0){
        string = '-' + string;
        Year = qAbs(year);
    }
    else if(year == 0){
        string = '-' + string;
        Year = 1;
    }
    else{
        Year = year;
    }
    string +=QString::number(Year);
    return string;
}
