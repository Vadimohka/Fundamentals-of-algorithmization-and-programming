#ifndef DATE_H
#define DATE_H

#include <QString>
#include <QMainWindow>
#include "QFileDialog"
#include "QVector"

const int dateSize = 10, five = 5, six = 6, ten = 10, n28 = 28, thousand = 1000, hundred = 100,
          n29 = 29, n30 = 30, seven = 7, eight = 8, n12 = 12, n31 = 31, hundred4 = 400, n365 = 365,
          n59 = 59, n90 = 90, n120 = 120, n151 = 151, n181 = 181, n212 = 212, n243 = 243,
          n273 = 273, n304 = 304, n334 = 334, nine = 9, n11 = 11;

class Date
{
public:
    QString date = "00.00.0000";
    int year = 0, month = 0, day = 0;
    Date();
    explicit Date(QString);
    Date NextDay();
    Date PreviousDay();
    bool isLeap(int checkYear);
    int16_t WeekNumber();
    int DaysTillYourBirthday(Date birthdaydate);
    int Duration(Date date);
    int DateInDays(int day, int month, int year);
    bool error = false;
};

#endif // DATE_H
