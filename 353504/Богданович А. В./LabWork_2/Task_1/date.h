#ifndef DATE_H
#define DATE_H

#include <QDate>

class Date {
private:
    int day;
    int month;
    int year;

    int NumOfDays[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    Date(int, int, int);
    Date();

    Date NextDate();
    Date PreviousDate();
    bool IsLeap();
    short WeekNumber();
    static int DaysTillYourBithday(Date bithdaydate);
    static int Duration(Date date);

    bool isDateCorrect();
    int DaysInThisYear();
    static Date getTodaysDate();
    int DateToDays();

    QString getDate();

};

Date StringToDate(QString);


#endif // DATE_H
