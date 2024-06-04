#ifndef DATE_H
#define DATE_H
#include <qstring.h>
#include <QFileDialog>
#include <QDebug>
#include <QDate>
#include <QVector>

class Date
{
public:
    int day;
    int month;
    int year;
    Date();
    QString NextDay();
    QString PreviousDay();

    bool isLeap();
    long WeekNumber();

    int DaysTillYourBirthday(Date birthdaydate);
    int Duration(Date date, Date date2);

    void getDate(QString str, int *day_from_date, int *month_from_date, int *year_from_date);
    QString is_0_neaded(int num, bool plus);

    int month_amount_days[13]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month_vis_amount_days[13]{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

private:
    QDate date = QDate::currentDate();
    int current_day = date.day(), current_month = date.month(), current_year = date.year();
};

#endif // DATE_H
