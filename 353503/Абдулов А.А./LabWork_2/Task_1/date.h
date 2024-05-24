#ifndef DATE_H
#define DATE_H

#include <QObject>

class Date
{
public:
    Date();
    Date(int day, int month, int year);
    ~Date();

    Date NextDay();
    Date PreviousDay();
    static bool IsLeapYear(int year);
    [[nodiscard]] qint16 WeekNumber() const;
    static int DaysTillYourBirthday(const Date &birthday);
    static int Duration(Date date);
    static bool IsValidDate(int day, int month, int year);
    [[nodiscard]] QString ToString() const;
    [[nodiscard]] int getDay() const;
    void setDay(int d);
    [[nodiscard]] int getMonth() const;
    void setMonth(int m);
    [[nodiscard]] int getYear() const;
    void setYear(int y);

private:
    int day{};
    int month{};
    int year{};
};


#endif // DATE_H
