#ifndef DATE_H
#define DATE_H
#include "QMap"
#include "QSet"
#include "QString"
#include "QDebug"
#include "QtMath"
#include "QMessageBox"
#include "QRegularExpression"

class Date
{
public:
    Date(int day, int month, int year);
    Date(QString string_date);
    Date NextDay();
    Date PreviousDay();
    bool IsLeap();
    short WeekNumber();
    short DayOfWeek();
    short DayOfYear();
    int DaysTillYourBithday(Date bithdaydate);
    int Duration (Date date, bool sign=false);
    QString StringDate();
    int GetDay();
    int GetYear();
    int GetMonth();
    void SetDate(int day, int month, int year);
    void SetDate(QString date);
    QString DayOfWeekString();
    bool IsValid();

    static bool IsLeap(int year);
    static short DaysInMonth(int month, int year);
    static bool CheckCorrectDate(int day, int month, int year);
    static bool CheckCorrectDate(QString *date);


protected:

    int day;
    int month;
    int year;


};

#endif // DATE_H
