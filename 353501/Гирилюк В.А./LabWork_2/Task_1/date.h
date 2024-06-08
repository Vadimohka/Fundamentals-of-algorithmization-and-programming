#ifndef DATE_H
#define DATE_H

#include <chrono>
#include <ctime>
#include <QString>
#include <QDebug>
#include <QMessageBox>


class Date
{

public:
    int day = 0;
    int month = 0;
    int year = 0;
    Date();
    ~Date();
    Date NextDay() const;
    Date PreviousDay() const;
    bool IsLeap() const;
    short WeekNumber() const;
    int DaysTillYourBirthday(Date birthdayDate) const;
    int Durration(Date date) const;
    void QStringToDate(QString date);
    QString DateToQString() const;
};

#endif // DATE_H
