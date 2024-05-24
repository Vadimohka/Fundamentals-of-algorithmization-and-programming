#ifndef DATE_H
#define DATE_H

#include <QMessageBox>
//#include "mainwindow.h"

#include <map>
#include <string>




class Date{
    friend class MainWindow;
public:
    Date(int DD, int MM, int YY);
    Date();

    //Technical specification methods
    Date NextDay();
    Date PreviousDay();
    int DaysTillYourBirthday(Date birthdayDate);

    bool IsLeap();

    short WeekNumber();

    int Duration(Date date);

    static QString ToString(Date date);
private:
    int m_day;
    int m_mounth;
    int m_year;

    unsigned char m_dayNumPerMounces[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};

#endif // DATE_H
