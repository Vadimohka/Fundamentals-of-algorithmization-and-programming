#include "mydateclass.h"

enum { DAYSINFEBRUARY = 29, FEBRUARY = 2 };
void MyDateClass::addDate(QDate date)
{
    dateList.push_back(date);
}

QString MyDateClass::getDate(int num)
{
    if (num >= 0 && num < dateList.size()) {
        return dateToString(dateList[num]);
    }
    return nullptr;
}

QString MyDateClass::getNextDate(int num)
{
    return dateToString(dateList[num].addDays(1));
}

QString MyDateClass::getPreviousDate(int num)
{
    return dateToString(dateList[num].addDays(-1));
}

bool MyDateClass::isLeapYear(int num)
{
    return QDate::isLeapYear(dateList[num].year());
}

int MyDateClass::daysTillBirthday(QDate birthdayDate, int num)
{
    QDate currDate = dateList[num];
    int currYear = currDate.year();
    if (birthdayDate.day() == DAYSINFEBRUARY && birthdayDate.month() == FEBRUARY) {
        while (!QDate::isLeapYear(currYear)) {
            currYear++;
        }
    }
    birthdayDate.setDate(currYear, birthdayDate.month(), birthdayDate.day());

    int output = currDate.daysTo(birthdayDate);
    if (output < 0) {
        if (birthdayDate.day() == DAYSINFEBRUARY && birthdayDate.month() == FEBRUARY) {
            birthdayDate = birthdayDate.addYears(1);
            while (!QDate::isLeapYear(birthdayDate.year())) {
                birthdayDate = birthdayDate.addYears(1);
            }
            output = currDate.daysTo(birthdayDate);
        } else {
            birthdayDate = birthdayDate.addYears(1);
            output = currDate.daysTo(birthdayDate);
        }
    }
    return output;
}

int MyDateClass::weekNumber(int num)
{
    return static_cast<int>(dateList[num].weekNumber());
}

int MyDateClass::duration(int num)
{
    if (num >= 0 && num < dateList.size()) {
        return QDate::currentDate().daysTo(dateList[num]);
    }
    return -1;
}

int MyDateClass::changeDate(QDate oldDate, QDate newDate)
{
    int output = -1;
    for (int i = 0; i < dateList.size(); i++) {
        if (dateList[i] == oldDate) {
            dateList[i] = newDate;
        }
        if (output == -1) {
            output = i;
        }
    }
    return output;
}

QString MyDateClass::dateToString(QDate date)
{
    if (date.year() > 0) {
        return date.toString("dd.MM.yyyy");
    }
    date.setDate(date.year() * -1, date.month(), date.day());
    return date.toString("dd.MM.yyyy BC");
}
