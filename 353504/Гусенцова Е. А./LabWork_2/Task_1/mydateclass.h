#ifndef MYDATECLASS_H
#define MYDATECLASS_H
#include <QString>

    class MyDateClass {
private:
    int MyDay, MyMonth, MyYear, NewDay, NewMonth, NewYear;

  public:
    struct Date {
        int day;
        int month;
        int year;
    };
    QString NextDay(int MyDay, int MyMonth, int MyYear);
    QString  PreviousDay( int MyDay, int MyMonth, int MyYear);
    int IsLeap(int MyYear);
    short WeekNumber( int MyDay, int MyMonth, int MyYear);
    int DaysTillYourBirthday(int MyDay, int MyMonth, int MyYear, int NewDay, int NewMonth, int NewYear);
    int Duration(int MyDay, int MyMonth, int MyYear, int NewDay, int NewMonth, int NewYear);
    int countLeapYears(int MyMonth, int MyYear);
};

#endif // MYDATECLASS_H

