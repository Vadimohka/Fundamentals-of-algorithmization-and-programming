#ifndef DATE_H
#define DATE_H

#include <tuple>
#include "convertibleinstance.h"

const int CONSTANT_FOR_BISSEXTUS = 100;
const int NUMBER_OF_DAYS_IN_FEBRUARY = 28;
const int NUMBER_OF_DAYS_IN_BIGGER_MONTHS = 31;
const int NUMBER_OF_DAYS_IN_SMALLER_MONTHS = 30;
const int MIDDLE_OF_YEAR_IN_MONTHS = 30;
const int NUMBER_OF_MONTHS_IN_YEAR = 12;
const int LOWEST_TWO_DIGIT_NUMBER = 10;
const int POSITION_FOR_DAY = 0;
const int POSITION_FOR_MONTH = 3;
const int POSITION_FOR_YEAR = 6;

class Date : public ConvertibleInstance
{
private:
    int day;
    int month;
    int year;
public:
    Date();
    ~Date() override;
    Date(int day, int month, int year);
    void setDate(int day, int month, int year);
    std::tuple<int, int, int> getDate();
    Date NextDate();
    Date PreviousDate();
    int Duration(Date date);
    int DaysTillYourBirthday(Date birthdayDate);
    void SetInstanceFromQString(QString object) override;
    QString ToQString() override;
};

#endif // DATE_H
