#ifndef FUNCTIONS_FOR_DATE_H
#define FUNCTIONS_FOR_DATE_H

#include <QDate>
#include "my_date.h"

class functions_for_Date
{
public:
    QVector <My_Date> list_of_dates;
    functions_for_Date();
    void add_new_Date(My_Date newDate);
    QString from_myDate_toString(My_Date date);
    QString get_Date(int position);
    QString get_prev_Date(int position);
    QString get_next_Date(int position);
    bool isLY(int position);
    long long daysTo(My_Date endDate, My_Date startDate);
    int DaysTillYourBithday(My_Date bithdaydate, int position, bool &q);
};

#endif // FUNCTIONS_FOR_DATE_H
