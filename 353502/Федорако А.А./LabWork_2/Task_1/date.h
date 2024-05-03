#ifndef DATE_H
#define DATE_H
#include <QString>
#include <time.h>
#include <vector>

class Date
{
public:
    Date NextDay();
    Date PreviousDay();
    bool IsLeap();
    bool IsLeap(int year);
    Date();
    Date(int valueDay, int valueMonth, int valueYear);
    int getDay();
    int getYear();
    int getMonth();
    void setDay(int newDay);
    void setMonth(int newMonth);
    void setYear(int newYear);
    Date getNowDate();
    QString getNameDayOfWeek();
    int daysTillYourBithday(Date bithdayDate);
    int WeekNumber();
    int Duration();
    Date fromString(QString date);
    QString toString();
    QString getStrNowDate();
    QString getStrNowTime();
    std::vector<int> getVectorDayIntMonth(int year);
private:
    bool isTwoDateSame(Date firstDate, Date secondDate);
    bool isSecondDateMoreFirst(Date firstDate, Date secondDate);
    int getQuantityYearBetweenTime(int leftBorderYear, int rightBorderYear);
    int const NumberSecondsInYear = 31536000;
    int const NumberSecondsInFourYear = 126230400;
    int const NumberSecondsInDay = 86400;
    int const NumberSecondsInHour = 3600;
    int const NumberSecondsInMinute = 60;
    int const TimeZoneMinsk = +3;
    int const StartNumberToCountNowYear = 1970;
    int const StartNumberToCountNowDay = 1;
    int const StartNumberToCountNowMonth = 1;
    std::vector<QString> arrDayWeek {"Monday","Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    int getNumberDayBetweenTwoDate(Date firstDate, Date secondDate);
    int const NumberMonthInYear = 12;
    int const NumberFirstTypeOfSetFour = 4;
    int const NumberSecondTypeOfSetOneHundred = 100;
    int const NumberThirdTypeOfSetFourHundred = 4;
    int const NumberDayInLeapYear = 366;
    int const NumberDayInNotLeapYear = 366;
    int const NumberDayInWeek = 7;
    int const NumberYearFromLeapToLeapYear = 3;
    int const NumberDayFebruaryLeap = 29;
    int const NumberDateFirstMonth = 31;
    int const NumberDateSecondMonth = 28;
    int const NumberDateThirdMonth = 31;
    int const NumberDateFourthMonth = 30;
    int const NumberDateFivethMonth = 31;
    int const NumberDateSixthMonth = 30;
    int const NumberDateSeventhMonth = 31;
    int const NumberDateEighthMonth = 31;
    int const NumberDateNinthMonth = 30;
    int const NumberDateTenthMonth = 30;
    int const NumberDateEleventhMonth = 30;
    int const NumberDateTwelfthMonth = 31;


    int year;
    int month;
    int day;
    int nowYear;
    int nowMonth;
    int nowDay;
    int nowHour;
    int nowMinute;
    int nowSecond;
};

#endif // DATE_H

