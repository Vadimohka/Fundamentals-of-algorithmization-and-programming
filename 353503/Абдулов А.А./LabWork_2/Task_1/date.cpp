#include "date.h"
#include <QDate>

constexpr qint16 leapYearMult = 400;
constexpr qint16 daysInWeek = 7;
constexpr qint16 base = 10;

enum DaysInMonth
{
    TwentyEight = 28,
    TwentyNine,
    Thirty,
    ThirtyOne
};

enum Months
{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

enum DaysInYear
{
    DaysInLeapYear = 366,
    DaysInNonLeapYear = 365
};

Date::Date() = default;

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

Date::~Date() = default;

Date Date::NextDay() {
    Date nextDay = *this;
    if (nextDay.day < TwentyEight) {
        nextDay.day++;
    } else if (nextDay.day == TwentyEight) {
        if (nextDay.month == February) {
            if (IsLeapYear(nextDay.year)) {
                nextDay.day++;
            } else {
                nextDay.day = 1;
                nextDay.month++;
            }
        } else {
            nextDay.day++;
        }
    } else if (nextDay.day == TwentyNine) {
        if (nextDay.month == February) {
            nextDay.day = 1;
            nextDay.month++;
        } else {
            nextDay.day++;
        }
    } else if (nextDay.day == Thirty) {
        if (nextDay.month == April || nextDay.month == June || nextDay.month == September || nextDay.month == November) {
            nextDay.day = 1;
            nextDay.month++;
        } else {
            nextDay.day++;
        }
    } else if (nextDay.day == ThirtyOne) {
        if (nextDay.month == December) {
            nextDay.day = 1;
            nextDay.month = 1;
            nextDay.year++;
        } else {
            nextDay.day = 1;
            nextDay.month++;
        }
    }
    return nextDay;
}

Date Date::PreviousDay() {
    Date previousDay = *this;
    if (previousDay.day > 1) {
        previousDay.day--;
    } else if (previousDay.day == 1) {
        if (previousDay.month == 1) {
            previousDay.day = ThirtyOne;
            previousDay.month = December;
            previousDay.year--;
        } else if (previousDay.month == March) {
            if (IsLeapYear(previousDay.year)) {
                previousDay.day = TwentyNine;
                previousDay.month--;
            } else {
                previousDay.day = TwentyEight;
                previousDay.month--;
            }
        } else if (previousDay.month == February || previousDay.month == April || previousDay.month == June || previousDay.month == August || previousDay.month == September || previousDay.month == November) {
            previousDay.day = ThirtyOne;
            previousDay.month--;
        } else {
            previousDay.day = Thirty;
            previousDay.month--;
        }
    }
    return previousDay;
}

bool Date::IsLeapYear(int year) {
    if (year % 4 != 0 || year % leapYearMult != 0) {
        return false;
    } else {
        return true;
    }
}

int Date::DaysTillYourBirthday(const Date &birthday) {
    int daysTillBirthday = 0;
    Date currentDate(QDate::currentDate().day(), QDate::currentDate().month(), QDate::currentDate().year());
    int nextYear = currentDate.year + 1;

    if (currentDate.month == birthday.month) {
        if (birthday.day < currentDate.day) {
            if (IsLeapYear(currentDate.year)) {
                daysTillBirthday = DaysInLeapYear - currentDate.day + birthday.day;
            } else {
                daysTillBirthday = DaysInNonLeapYear - currentDate.day + birthday.day;
            }
        } else {
            daysTillBirthday = birthday.day - currentDate.day;
        }
    } else if (currentDate.month < birthday.month) {
        for (int i = currentDate.month; i < birthday.month; i++) {
            if (i == February) {
                if (IsLeapYear(currentDate.year)) {
                    daysTillBirthday += TwentyNine;
                } else {
                    daysTillBirthday += TwentyEight;
                }
            } else if (i == April || i == June || i == September || i == November) {
                daysTillBirthday += Thirty;
            } else {
                daysTillBirthday += ThirtyOne;
            }
        }
        daysTillBirthday += birthday.day - currentDate.day;
    } else {
        for (int i = currentDate.month; i <= December; i++) {
            if (i == February) {
                if (IsLeapYear(currentDate.year)) {
                    daysTillBirthday += TwentyNine;
                } else {
                    daysTillBirthday += TwentyEight;
                }
            } else if (i == April || i == June || i == September || i == November) {
                daysTillBirthday += Thirty;
            } else {
                daysTillBirthday += ThirtyOne;
            }
        }
        for (int i = 1; i < birthday.month; i++) {
            if (i == February) {
                if (IsLeapYear(nextYear)) {
                    daysTillBirthday += TwentyNine;
                } else {
                    daysTillBirthday += TwentyEight;
                }
            } else if (i == April || i == June || i == September || i == November) {
                daysTillBirthday += Thirty;
            } else {
                daysTillBirthday += ThirtyOne;
            }
        }
        daysTillBirthday += birthday.day - currentDate.day;
    }

    return daysTillBirthday;
}

int Date::Duration(Date date) {
    int duration = 0;
    Date currentDate(QDate::currentDate().day(), QDate::currentDate().month(), QDate::currentDate().year());

    if (currentDate.year == date.year) {
        if (currentDate.month == date.month) {
            duration = date.day - currentDate.day;
        } else {
            for (int i = currentDate.month; i < date.month; i++) {
                if (i == February) {
                    if (IsLeapYear(currentDate.year)) {
                        duration += TwentyNine;
                    } else {
                        duration += TwentyEight;
                    }
                } else if (i == April || i == June || i == September || i == November) {
                    duration += Thirty;
                } else {
                    duration += ThirtyOne;
                }
            }
            duration += date.day - currentDate.day;
        }
    } else {
        if (date.year < currentDate.year) {
            int tempYear = date.year;
            date.year = currentDate.year;
            currentDate.year = tempYear;
        }

        for (int i = currentDate.year; i < date.year; i++) {
            if (IsLeapYear(currentDate.year)) {
                duration += DaysInLeapYear;
            } else {
                duration += DaysInNonLeapYear;
            }
        }

        if (date.month < currentDate.month) {
            int tempYear = date.month;
            date.month = currentDate.month;
            currentDate.month = tempYear;
        }

        for (int i = currentDate.month; i < date.month; i++) {
            if (i == February) {
                if (IsLeapYear(currentDate.year)) {
                    duration += TwentyNine;
                } else {
                    duration += TwentyEight;
                }
            } else if (i == April || i == June || i == September || i == November) {
                duration += Thirty;
            } else {
                duration += ThirtyOne;
            }
        }
        duration += date.day - currentDate.day;
    }
    return duration;
}


qint16 Date::WeekNumber() const {
    Date beginOfYear(1, 1, year);
    int numberOfDays = 0;

    if (beginOfYear.year == year) {
        if (beginOfYear.month == month) {
            numberOfDays = day - beginOfYear.day;
        } else {
            for (int i = beginOfYear.month; i < month; i++) {
                if (i == February) {
                    if (IsLeapYear(beginOfYear.year)) {
                        numberOfDays += TwentyNine;
                    } else {
                        numberOfDays += TwentyEight;
                    }
                } else if (i == April || i == June || i == September || i == November) {
                    numberOfDays += Thirty;
                } else {
                    numberOfDays += ThirtyOne;
                }
            }
            numberOfDays += day - beginOfYear.day;
        }
    } else {
        for (int i = beginOfYear.year; i < year; i++) {
            if (IsLeapYear(beginOfYear.year)) {
                numberOfDays += DaysInLeapYear;
            } else {
                numberOfDays += DaysInNonLeapYear;
            }
        }

        for (int i = beginOfYear.month; i < month; i++) {
            if (i == February) {
                if (IsLeapYear(beginOfYear.year)) {
                    numberOfDays += TwentyNine;
                } else {
                    numberOfDays += TwentyEight;
                }
            } else if (i == April || i == June || i == September || i == November) {
                numberOfDays += Thirty;
            } else {
                numberOfDays += ThirtyOne;
            }
        }
        numberOfDays += day - beginOfYear.day;
    }
    return static_cast<qint16>(numberOfDays / daysInWeek + 1);
}


bool Date::IsValidDate(int day, int month, int year) {
    if (year < 0) {
        return false;
    }
    if (month < January || month > December) {
        return false;
    }
    if (day < 1) {
        return false;
    }
    if (month == February) {
        if (IsLeapYear(year)) {
            if (day > TwentyNine) {
                return false;
            }
        } else {
            if (day > TwentyEight) {
                return false;
            }
        }
    } else if (month == April || month == June || month == September || month == November) {
        if (day > Thirty) {
            return false;
        }
    } else {
        if (day > ThirtyOne) {
            return false;
        }
    }
    return true;
}


QString Date::ToString() const {
    QString str = QString("%1.%2.%3").arg(day, 2, base, QChar('0')).arg(month, 2, base, QChar('0')).arg(year, 4, base, QChar('0'));
    return str;
}


int Date::getDay() const {
    return day;
}

void Date::setDay(int d) {
    Date::day = d;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int m) {
    Date::month = m;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int y) {
    Date::year = y;
}
