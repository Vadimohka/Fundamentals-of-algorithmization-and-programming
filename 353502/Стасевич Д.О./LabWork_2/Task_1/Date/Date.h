//
// Created by darina on 3/30/24.
//

#ifndef TASK1_DATE_H
#define TASK1_DATE_H


#include <QString>
#include <ctime>
#include <QCache>

class Date {

public:
    Date(short d, short m, short y);
    Date NextDay() const;
    Date PreviousDay() const;
    bool IsLeap() const;
    static short WeekNumber(Date d);
    int DaysTillYourBirthday(Date birthdaydate) const;
    static int Duration (Date date);
    static int Duration (Date date1, Date date2);
    static QString DayToString(Date date);
    static Date StringToDate(const QString& s);

private:
    short day, month, year;
    bool leap;
    constexpr static short y[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    static bool IsLeap(short y);
    static Date GetToday();
    static short LeapTillNow(short y);
    static int DayFromBeginning(Date date);
};


#endif //TASK1_DATE_H
