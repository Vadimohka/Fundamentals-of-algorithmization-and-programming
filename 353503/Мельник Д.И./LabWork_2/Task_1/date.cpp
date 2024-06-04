#include "date.h"
#include <ctime>

constexpr int FIRST_DAY = 1;
constexpr int LAST_MONTH = 12;
constexpr int FIRST_MONTH = 1;
constexpr int DAYS_IN_WEEK = 7;
constexpr int START_OF_CENTURY = 1900;
constexpr int DAYS_IN_NON_LEAP_YEAR = 365;
constexpr int DAYS_IN_THIRTY_DAY_MONTH = 30;
constexpr int DAYS_IN_LEAP_FEBRUARY = 29;
constexpr int DAYS_IN_NON_LEAP_FEBRUARY = 28;
constexpr int DAYS_IN_THIRTY_ONE_DAY_MONTH = 31;

auto Date::nextDay() -> QString {
    Date nextDay(*this);
    if ((nextDay._day < DAYS_IN_NON_LEAP_FEBRUARY && nextDay._month != 2)
        || (nextDay._day < DAYS_IN_NON_LEAP_FEBRUARY && nextDay._month == 2 && !nextDay.isLeap())
        || (nextDay._day < DAYS_IN_LEAP_FEBRUARY && nextDay._month == 2 && nextDay.isLeap())
        || (nextDay._day < DAYS_IN_THIRTY_DAY_MONTH && (nextDay._month == 4 || nextDay._month == 6
        || nextDay._month == 9 || nextDay._month == 11))
        || (nextDay._day < DAYS_IN_THIRTY_ONE_DAY_MONTH && (nextDay._month != 2))) {
        nextDay._day++;
    } else {
        nextDay._day = FIRST_DAY;
        if (nextDay._month == LAST_MONTH) {
            nextDay._month = FIRST_MONTH;
            nextDay._year++;
        } else {
            nextDay._month++;
        }
    }
    return nextDay.toQString();
}


auto Date::previousDay() -> QString {
    Date prevDay(*this);
    if (prevDay._day > FIRST_DAY) {
        prevDay._day--;
    } else {
        if (prevDay._month == FIRST_MONTH) {
            prevDay._month = LAST_MONTH;
            prevDay._year--;
        } else {
            prevDay._month--;
        }

        if (prevDay._month == 2) {
            if (prevDay.isLeap()) {
                prevDay._day = DAYS_IN_LEAP_FEBRUARY;
            } else {
                prevDay._day = DAYS_IN_NON_LEAP_FEBRUARY;
            }
        } else if (prevDay._month == 4 || prevDay._month == 6 || prevDay._month == 9 || prevDay._month == 11) {
            prevDay._day = DAYS_IN_THIRTY_DAY_MONTH;
        } else {
            prevDay._day = DAYS_IN_THIRTY_ONE_DAY_MONTH;
        }
    }
    return prevDay.toQString();
}

auto Date::DaysInMonth(int month, int year) -> int {
    bool isLeap = false;

    constexpr int daysInMonth[2][12] = {
            {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
            {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

    if (year % 4 == 0) {
        isLeap = true;
    }
    if (year % 100 != 0 and year % 400 == 0) {
        isLeap = true;
    }

    return daysInMonth[isLeap][month - 1];
}

auto Date::isLeap() -> bool {
    if (_year % 4 != 0) {
        return false;
    } else if (_year % 100 != 0) {
        return true;
    } else if (_year % 400 != 0) {
        return false;
    } else {
        return true;
    }
}

/* Получаем количество дней до следующего дня рождения от текущей даты */
auto Date::daysTillYourBithday(const Date &bithdaydate) -> int {
    /* Получаем текущую дату */
    time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);

    /* Создаем объект Date для текущей даты */
    Date currentDate(now->tm_mday + 6, now->tm_mon, now->tm_year + START_OF_CENTURY);

    /* Создаем объект Date для следующего дня рождения */
    Date nextBirthday(bithdaydate._day, bithdaydate._month, currentDate._year);
    if (currentDate.duration(nextBirthday) < 0) {
        /* Если следующий день рождения уже прошел в этом году, используем день рождения в следующем году */
        if (currentDate.isLeap()) {
            nextBirthday._year++;
        }
        else{
            nextBirthday._year +=3;
        }
    }

    /* Вычисляем количество дней между текущей датой и следующим днем рождения */
    int days = currentDate.duration(nextBirthday);

    return days;
}

/* Вычисляем количество дней между текущей и данной датой */
auto Date::duration(const Date &date) -> int {
    /* Массив с количеством дней в каждом месяце (для высокосного и невысокосного года) */
    constexpr int daysInMonth[2][12] = {
            {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
            {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

    /* Создаем копии дат, которые будем изменять */
    Date startDate(*this);
    Date endDate(date);

    /* Проверяем, какая дата раньше, и меняем их местами, если нужно */
    if (startDate._year > endDate._year ||
        (startDate._year == endDate._year && startDate._month > endDate._month) ||
        (startDate._year == endDate._year && startDate._month == endDate._month && startDate._day > endDate._day)) {
        std::swap(startDate, endDate);
    }

    /* Вычисляем разницу в годах и количество високосных лет */
    int yearsDifference = endDate._year - startDate._year;
    int leapYears = yearsDifference / 4 - yearsDifference / 100 + yearsDifference / 400;

    /* Вычисляем количество дней */
    int days = 0;
    days += DAYS_IN_NON_LEAP_YEAR * yearsDifference + leapYears;
    days -= startDate._day;
    days += endDate._day;

    /* Учитываем количество дней в каждом месяце */
    for (int i = 0; i < startDate._month - 1; i++) {
        days -= daysInMonth[startDate.isLeap()][i];
    }

    for (int i = 0; i < endDate._month - 1; i++) {
        days += daysInMonth[endDate.isLeap()][i];
    }

    return days;
}

/* Получаем номер недели в году для текущей даты */
auto Date::weekNumber() -> short {
    /* Создаем структуру времени и заполняем ее данными объекта */
    std::tm timeStruct = {};
    timeStruct.tm_mday = _day;
    timeStruct.tm_mon = _month - 1;
    timeStruct.tm_year = _year - START_OF_CENTURY;
    mktime(&timeStruct);

    /* Вычисляем номер недели */
    return (timeStruct.tm_yday / DAYS_IN_WEEK) + 1;
}

/* Преобразуем дату в QString */
auto Date::toQString() -> QString {
    return QString("%1-%2-%3").arg(_day).arg(_month).arg(_year);
}
