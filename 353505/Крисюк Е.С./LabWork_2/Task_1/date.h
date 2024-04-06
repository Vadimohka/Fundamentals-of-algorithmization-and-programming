#ifndef DATE_H
#define DATE_H

#include <ctime>
#include <QDebug>
#include <iostream>
#include <sstream>
#include <string>

class Date
{
public:
    Date();
    QString Current_date;
    QString Next_Day(QString);
    QString Previous_Day(QString);
    bool Is_Leap(QString);
    short Week_Number(QString);
    int Days_Till_Your_Bithday(QString);
    int Duration(QString);

private:
    std::tm* local_time;
};


#endif // DATE_H
