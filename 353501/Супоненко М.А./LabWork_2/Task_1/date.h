#pragma once 

#include <QObject>
#include <QGraphicsItem>
#include <QDebug>

class Date //: public QObject
{
    // Q_OBJECT
private:
   int day;
   int month;
   int year;


public:
    explicit Date(int day, int month, int year);
    // ~Date();

    Date NextDay();     
    Date PreviousDay();
    bool IsLeap();  
    short WeekNumber();     
    int DaysTillYourBithday(const Date& birthday);   
    int Duration(const Date& other);
    bool isLess(Date n);
    QString ToString();
};

