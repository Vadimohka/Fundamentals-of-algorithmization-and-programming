//
// Created by acryoz on 28.2.24.
//
#pragma once
#ifndef UNTITLED5_DATE_H
#define UNTITLED5_DATE_H

#include "DateException.h"
#include <cmath>
#include <chrono>
#include <QMetaType>
#include <QVariant>

using ushort = unsigned short;
using uint = unsigned int;


class Date {
public:
    Date();
    Date(uint, uint, uint);
    Date(const Date&);
    bool isLeap() const;
    bool isValid() const;
    uint weekNumber() const;
    Date nextDay() const;
    Date previousDay() const;
    uint daysTillYourBirthday(const Date&) const;
    uint daysTo(const Date&) const;
    uint day() const;
    uint year() const;
    uint month() const;
    uint daynumber() const;
    Date& operator= (const Date&);
    static Date today();
    QString toQstring() const;
    bool operator<(const Date&) const;
    static Date fromString(const QString&);
private:
    uint m_year;
    uint m_day;
    uint m_month;
    bool valid;
};

uint weeks(uint y);
bool isLeapYear(uint y);
uint leapYearsBefore(uint);

Q_DECLARE_METATYPE(Date)
#endif //UNTITLED5_DATE_H
