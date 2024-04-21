#ifndef DATE_H
#define DATE_H

#include <QDate>

class Date
{
public:
    Date();
    Date(short value_day, short value_month, short value_year);
    QString toString() const;
    static Date fromString(const QString& value);
    Date nextDay() const;
    Date previousDay() const;
    int Duration (const Date value_date) const;
    short weekNumber() const;
    short dayNumber() const;
    short getDay() const;
    short getMonth() const;
    short getYear() const;
    bool isLeap() const;
    void setDay(const short value);
    void setMonth(const short value);
    void setYear(const short value);

private:
    QDate date;
    long double a;
    short day = 0, month = 0, year = 0;
};

#endif // DATE_H
