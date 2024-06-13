#ifndef DATE_H
#define DATE_H

#include <QString>
#include <QDate>
#include <QVector>
#include <cmath>

class Date
{
private:
    QDate birthDayDate = QDate(2006, 8, 1);
    QDate currentDate;
public:
    Date();
    QString NextDay();
    QString PreviousDay();
    int DaysTillYourBirthday();
    int Duration(QDate date);
    bool isLeap();
    int WeekNumber();
    QString FormatDate(QDate date);
    void setDate(QDate date);
    QDate getDate();
};

#endif // DATE_H
