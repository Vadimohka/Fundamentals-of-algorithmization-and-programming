#include "mydate.h"
#include "qdebug.h"

#include <QDateTime>

short MyDate::daysInMonth(short month, long long year){
    if (month == 2){
        if (year % 4 == 0)
            return 29;
        else return 28;
    } else if (month == 4 || month == 9 || month == 11)
        return 30;
    return 31;
}

bool MyDate::operator<(MyDate another)
{
    if (year!=another.year)
        return (year<another.year);
    if (month!=another.month)
        return (month<another.month);
    return (day<another.day);
}

bool MyDate::isValid()
{
    return vaild;
}

bool MyDate::validate(short day, short month, long long year){
    if(day < 1 || month < 1 || year < 1)
        return false;
    if(month > 12)
        return false;
    if(day > daysInMonth(month, year))
        return false;
    return true;
}

MyDate::MyDate(){
    this->year = 0001;
    this->month = 01;
    this->day = 01;
    this->vaild = true;
}

MyDate::MyDate(short day, short month, long long year) : MyDate(){
    if(day == 29 && month == 2 && !isLeap(year)){
        day = 28;
    }
    if (!validate(day, month, year)){
        this->vaild = false;
        return;
    }
    this->year = year;
    this->month = month;
    this->day = day;
    this->vaild = validate(this->day, this->month, this->year);
}

MyDate::MyDate(QString base) : MyDate(){
    QRegularExpression re("(\\d{2})\\.(\\d{2})\\.(\\d{4})");
    QRegularExpressionMatch match = re.match(base);
    if (match.hasMatch()) {
        this->day = match.captured(1).toInt();
        this->month = match.captured(2).toInt();
        this->year = match.captured(3).toInt();
        this->vaild = validate(this->day, this->month, this->year);
    } else{
        this->vaild = false;
    }
}

bool MyDate::isLeap(int year){
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
        return true;
    }
    return false;
}
const QString MyDate::toString(){
    return QString("%1.%2.%3").arg(day, 2, 10, QChar('0')).arg(month, 2, 10, QChar('0')).arg(year, 4, 10, QChar('0'));;
}
MyDate MyDate::nextDay(){
    MyDate nextDay(day, month, year);
    nextDay.day++;
    if (nextDay.day > daysInMonth(nextDay.month,nextDay.year)){
        nextDay.day = 1;
        nextDay.month++;
    }
    if (nextDay.month > 12){
        nextDay.month=1;
        nextDay.year++;
    }
    return nextDay;
}
MyDate MyDate::PreviousDay(){
    MyDate prevDay(day, month, year);
    prevDay.day--;
    if (prevDay.day < 0){
        prevDay.day = 1;
        prevDay.month--;
    }
    if (prevDay.month < 0){
        prevDay.month=1;
        prevDay.year--;
    }
    return prevDay;
}

MyDate MyDate::current(){
    QDate currentDate = QDate::currentDate();
    int day = currentDate.day();
    int month = currentDate.month();
    int year = currentDate.year();
    return MyDate(day, month, year);
}

qint64 MyDate::daysFromBegin(){
    qint64 days = 0;
    for (int var = 1; var < year; ++var) {
        days += (isLeap(var)) ? 365 : 366;
    }
    qint64 month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeap(year)) {
        month_days[1] = 29;
    }
    for (int var = 1; var < month; ++var) {
        days += month_days[var-1];
    }
    days += (day-1);
    return days;
}

qint64 MyDate::daysBetween(MyDate compare) {
    return compare.daysFromBegin() - daysFromBegin();
}

qint64 MyDate::daysTillBirthday(MyDate birthday){
    MyDate currentBirthday(birthday.day, birthday.month, year);
    qint64 days = daysBetween(currentBirthday);
    if (days <= 0){
        if(birthday.day == 29 && birthday.month == 2){
            birthday.day = 28;
        }
        currentBirthday.year = currentBirthday.year + 1;
        days = daysBetween(currentBirthday);
    }
    return days;
}
