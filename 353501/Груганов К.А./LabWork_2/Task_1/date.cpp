#include "date.h"

Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::~Date()
{

}

int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

Date Date::NextDay()
{
    struct tm date = {};
    date.tm_mday = day;
    date.tm_mon = month - 1;
    date.tm_year = year - 1900;
    time_t timeStamp = mktime(&date);
    timeStamp += 86400;
    date = *localtime(&timeStamp);
    return Date(date.tm_mday, date.tm_mon + 1, date.tm_year + 1900);
}

Date Date::PreviousDate()
{
    struct tm date = {};
    date.tm_mday = day;
    date.tm_mon = month-1;
    date.tm_year = year - 1900;
    time_t timeStamp = mktime(&date);
    timeStamp -=86400;
    date = *localtime(&timeStamp);
    return Date(date.tm_mday, date.tm_mon+1, date.tm_year + 1900);
}

Date Date::getCurrentTime()
{
    time_t currTime = time(nullptr);
    tm *localTime = localtime(&currTime);
    int day = localTime->tm_mday;
    int month = localTime->tm_mon+1;
    int year = localTime->tm_year+1900;
    return Date(day,month,year);
}

bool Date::IsLeap()
{
    return (year % 4 == 0 && year % 100 !=0) || (year % 400 ==0);
}

short Date::WeekNumber()
{
    tm date={};
    date.tm_mday = day;
    date.tm_mon = month-1;
    date.tm_year = year - 1900;
    mktime(&date);

    int weekNumber = (date.tm_yday + 10 - (date.tm_wday ? date.tm_wday : 7)) / 7;

    if(weekNumber == 0){
        weekNumber = 52;
    }
    return weekNumber;
}

/*int Date::Duration(Date date)
{
    time_t currentTime;
    time(&currentTime);

    struct tm givenDate = {};
    givenDate.tm_mday = date.day;
    givenDate.tm_mon = date.month-1;
    givenDate.tm_year = date.year - 1900;

    time_t givenTime = mktime(&givenDate);

    double diffInSec = difftime(givenTime,currentTime);
    int diffDays = diffInSec/(3600*24);
    return diffDays;
}*/

int Date::Duration(Date date1, Date date2)
{
    struct tm Date1 = {};
    Date1.tm_mday = date1.day;
    Date1.tm_mon = date1.month - 1;
    Date1.tm_year = date1.year - 1900;

    struct tm Date2 = {};
    Date2.tm_mday = date2.day;
    Date2.tm_mon = date2.month - 1;
    Date2.tm_year = date2.year - 1900;

    time_t time1 = mktime(&Date1);
    time_t time2 = mktime(&Date2);

    double diffInSec = difftime(time1,time2);
    int diffInDays = diffInSec/(3600*24);

    return abs(diffInDays);
}

QString Date::formatDate(const Date &date)
{
   QString dateString = QString("%1.%2.%3")
                                 .arg(date.getDay(), 2, 10, QChar('0'))
                                 .arg(date.getMonth(), 2, 10, QChar('0'))
                                 .arg(date.getYear(), 4, 10, QChar('0'));

        return dateString;

}

QVector<Date> Date::readDatesFromFile(const QString &fileName)
{
        QVector<Date> dates;
        bool error = false;

        QFile file(fileName);

        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if (file.size() == 0) {
            return dates;
        }

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList dateParts = line.split(" ");
            for (const QString &datePart : dateParts) {
                if (datePart.startsWith(".") || datePart.endsWith(".")) {
                    error = true;
                    break;
                }
                QStringList parts = datePart.split(".");
                if (parts.size() == 3) {
                    bool Ok;
                    int day = parts[0].toInt(&Ok);
                    if (!Ok) {
                        error = true;
                        break;
                    }
                    int month = parts[1].toInt(&Ok);
                    if (!Ok) {
                        error = true;
                        break;
                    }
                    int year = parts[2].toInt(&Ok);
                    if (!Ok) {
                        error = true;
                        break;
                    }
                    if (!Date::isValidDate(day, month, year)) {
                        error = true;
                        break;
                    }
                    Date date(day, month, year);
                    dates.append(date);
                }
            }
            if (error) {
                break;
            }
        }
        file.close();
        }
        if (error) {
        qDebug() << "Ошибка при открытии файла";
        dates.clear();
        }

        return dates;
}

void Date::addDateToFile(const QString &fileName, const Date &date)
{

    QFile file(fileName);
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream stream(&file);
        QString contents = stream.readAll();

        int lastSpaceIndex = contents.lastIndexOf(" ");
        if (lastSpaceIndex != -1) {
        contents.insert(lastSpaceIndex+1, QString("%1.%2.%3 ")
                                                .arg(date.getDay(), 2, 10, QChar('0'))
                                                .arg(date.getMonth(), 2, 10, QChar('0'))
                                                .arg(date.getYear(), 4, 10, QChar('0')));
        }
        else{
        contents.append( QString("%1.%2.%3 ")
                                                 .arg(date.getDay(), 2, 10, QChar('0'))
                                                 .arg(date.getMonth(), 2, 10, QChar('0'))
                                                 .arg(date.getYear(), 4, 10, QChar('0')));
        }
        file.seek(0);
        stream << contents;
        file.close();
    }
}
void Date::writeDateToFile(const QString &fileName, const Date &date,int row)
{
    QFile file(fileName);
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream in(&file);

        in.seek(row * 11);

        in<<formatDate(date);


        file.close();
    }
}

void Date::removeDateFromFile(const QString &filename)
{
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream stream(&file);
        QString content = stream.readAll();

        int lastIndex = content.length();
        if (lastIndex >= 0) {
        content.truncate(lastIndex-11);
        }

        file.resize(0);
        stream << content;

        file.close();
    }
}

bool Date::isValidDate(int day, int month, int year)
{
    bool isLeap = (year % 4 ==0 && year %100!=0) || (year % 400 ==0);

    if(month<1 || month>12){
        return false;
    }

    if(day<1){
        return false;
    }

    int daysInMonth;

    if(month==2){
        daysInMonth = isLeap ? 29 : 28;
    }else if(month ==4 || month ==6 || month == 9 || month == 11){
        daysInMonth =30;
    }else{
        daysInMonth = 31;
    }

    if (day > daysInMonth){
        return false;
    }

    return true;
}

void Date::clearFile(const QString &filename)
{
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        file.resize(0);
    }
}

int Date::DaysTillYourBirthday(Date birthdaydate)
{
    if(Duration(birthdaydate,*this)<0){
        birthdaydate.year+=1;
    }
    return abs(Duration(birthdaydate,*this));
}
