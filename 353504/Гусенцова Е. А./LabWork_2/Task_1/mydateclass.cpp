#include "mydateclass.h"

struct Date {
    int day;
    int month;
    int year;
};

const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int MyDateClass::countLeapYears(int MyMonth, int MyYear) {

    if (MyMonth        <= 2)
       MyYear--;
    return MyYear / 4 - MyYear / 100 + MyYear / 400;
}

int MyDateClass::Duration(int MyDay, int MyMonth, int MyYear, int NewDay, int NewMonth, int NewYear) {
    long int n1 = MyYear * 365 + MyDay;
    for (int i = 0; i < MyMonth - 1; i++)
        n1 += monthDays[i];
    n1 += countLeapYears(MyMonth, MyYear);

    long int n2 = NewYear * 365 + NewDay;
    for (int i = 0; i < NewMonth - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(NewMonth, NewYear);

    return (n2 - n1);
}

int MyDateClass::DaysTillYourBirthday(int MyDay, int MyMonth, int MyYear, int NewDay, int NewMonth, int NewYear) {
    long int n1 = MyYear * 365 + MyDay;
    for (int i = 0; i < MyMonth - 1; i++)
        n1 += monthDays[i];
    n1 += countLeapYears(MyMonth, MyYear);

    long int n2 = NewYear * 365 + NewDay;
    for (int i = 0; i < NewMonth - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(NewMonth, NewYear);

    return (n2 - n1);
}

short MyDateClass::WeekNumber(int MyDay, int MyMonth, int MyYear) {

    int dayOfWeek = 0;
    int dayOfYear = 0;
    for (int month = 1; month < MyMonth; ++month) {
        dayOfYear += monthDays[month - 1];
    }
    dayOfYear += MyDay;
        if (IsLeap(MyYear) && MyMonth > 2) {
        dayOfYear += 1;
    }

    int jan1Weekday = (dayOfWeek + 7 - ((dayOfYear - MyDay + 1) % 7)) % 7;
    int weekNumber = (dayOfYear + jan1Weekday - 1) / 7;
        if (MyMonth == 12 && MyDay >= 29) {
        int dec31Weekday = (jan1Weekday + dayOfYear - 1) % 7;
        if (dec31Weekday <= 3) {
            weekNumber = 1;
        } else {
            weekNumber = 52 + (dec31Weekday == 4);
        }
    }
    return weekNumber;
}


int MyDateClass::IsLeap(int MyYear) {

    if ((MyYear % 4 == 0) || ((MyYear % 400 == 0) && (MyYear % 100 == 0))) {
      MyYear=1;
    } else {
         MyYear=0;
    }
    return MyYear;
}
QString MyDateClass::NextDay(int MyDay, int MyMonth, int MyYear) {
    int NewDay = MyDay;
    int NewMonth = MyMonth;
    int NewYear = MyYear;

    if (MyMonth == 2) {
        if (IsLeap(MyYear)) {
            if (MyDay == 29) {
                NewDay = 1;
                NewMonth = 3;
            } else {
                NewDay = MyDay + 1;
            }
        }
        else {
            if (MyDay == 28) {
                NewDay = 1;
                NewMonth = 3;
            } else {
                NewDay = MyDay + 1;
            }
        }
    } else if ((MyMonth == 1) || (MyMonth == 3) || (MyMonth == 5) || (MyMonth == 7) || (MyMonth == 8) || (MyMonth == 10)) {
        if (MyDay == 31) {
            if (MyMonth == 12) {
                NewMonth = 1;
                NewDay = 1;
                NewYear = MyYear + 1;
            } else {
                NewMonth = MyMonth + 1;
                NewDay = 1;
            }
        } else {
            NewDay = MyDay + 1;
        }
    } else if ((MyMonth == 4) || (MyMonth == 6) || (MyMonth == 9) || (MyMonth == 11)) {
        if (MyDay == 30) {
            NewMonth = MyMonth + 1;
            NewDay = 1;
        } else {
            NewDay = MyDay + 1;
        }
    } else if (MyMonth == 12 && MyDay == 31) {
        NewYear = MyYear + 1;
        NewMonth = 1;
        NewDay = 1;
    } else {
        NewDay = MyDay + 1;
    }


    QString formattedDate = QString("%1.%2.%3").arg(NewDay, 2, 10, QLatin1Char('0')).arg(NewMonth, 2, 10, QLatin1Char('0')).arg(NewYear);
    return formattedDate;
}


QString MyDateClass::PreviousDay(int MyDay, int MyMonth, int MyYear) {
    int NewDay = MyDay;
    int NewMonth = MyMonth;
    int NewYear = MyYear;

    if (MyMonth == 3) {
        if (IsLeap(MyYear)) {
            if (MyDay == 1) {
                NewDay = 29;
                NewMonth = 2;
            } else {
                NewDay = MyDay - 1;
            }
        } else {
            if (MyDay == 1) {
                NewDay = 28;
                NewMonth = 2;
            } else {
                NewDay = MyDay - 1;
            }
        }
    } else if (MyMonth == 1) {
        if (MyDay == 1) {
            NewMonth = 12;
            NewDay = 31;
            NewYear = MyYear - 1;
        } else {
            NewDay = MyDay - 1;
        }
    } else if ((MyMonth == 5) || (MyMonth == 7) || (MyMonth == 10) || (MyMonth == 12)) {
        if (MyDay == 1) {
            NewMonth = MyMonth - 1;
            NewDay = 30;
        } else {
            NewDay = MyDay - 1;
        }
    } else {
        if (MyDay == 1) {
            NewMonth = MyMonth - 1;
            NewDay = 31;
        } else {
            NewDay = MyDay - 1;
        }
    }

    QString formattedDate = QString("%1.%2.%3").arg(NewDay, 2, 10, QLatin1Char('0')).arg(NewMonth, 2, 10, QLatin1Char('0')).arg(NewYear);
    return formattedDate;
}
