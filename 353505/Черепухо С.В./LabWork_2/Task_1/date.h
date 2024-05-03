#ifndef DATE_H
#define DATE_H

#include <QDate>
#include <QString>

class Date
{
public:
    Date();
    Date NextDay();
    Date PreviousDay();
    bool IsLeap();
    short WeekNumber();
    int DaysTillYourBirthday(Date birthdaydate);
    int Duration(Date dute);

    void setDay(int dd);
    void setMonth(int mm);
    void setYear(int yy);

    int getDay();
    int getMonth();
    int getYear();

    bool checkDate();

    QString getString();

private:
    int d, m, y;
};

#endif // DATE_H
