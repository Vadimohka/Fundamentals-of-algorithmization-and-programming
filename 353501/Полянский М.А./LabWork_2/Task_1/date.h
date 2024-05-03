#ifndef DATE_H
#define DATE_H
#include <QDate>
#include <QString>

class Date
{
public:
    Date(int day, int month, int year);
    
    int day() const;
    int month() const;
    int year() const;

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    // methods
    Date nextDay() const;
    Date previousDay() const;
    short weekNumber() const;
    short dayOfWeek() const;
    static Date today();
    
    // static bool isStringValid(QString word);
    bool isDateValid() const; 
    static Date stringToDate(QString word);
    static QString dateToString(const Date& date);
    static QString weekdayToString(int weekday);
    static int duration(Date date1, Date date2);
    int getMonthLength(int mount, bool leap) const;
    QString toString() const;
    void getInfo(int* day, int* month, int* year) const;
    bool isLeapYear(int year) const;
public:
    static Date FromString(std::string dateStr);
    static Date fromQDate(QDate date);
private:
    short Day;
    short Month;
    short Year;
    
    int dayOfYear = 365;
    int absDuration();
    
};

#endif // DATE_H
