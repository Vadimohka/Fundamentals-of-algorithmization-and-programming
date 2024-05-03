#ifndef DATE_H
#define DATE_H

#include <QtMath>
#include <QString>

class Date
{
public:
    Date(short, short, int);

    Date NextDay();
    Date PreviousDay();

    //void StringToDate(QString a);
    Date StringToDate(QString);

    bool IsLeap();
    bool IsValid();

    short WeekNumber();
    int DaysTillYourBirthday(Date);
    int Duration(Date);
    int GetDay();
    int GetMonth();
    int GetYear();

    QString Print() const;
private:
    void MakeToStandart();

    int year;
    short day, month;
    bool is_leap = false;

    int monthes[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};

#endif // DATE_H
