#ifndef DATE_H
#define DATE_H

#include <QString>

class Date
{

private:

    long long Day;
    long long Month;
    long long Year;

public:

    Date();
    long long getDateDay();
    long long getDateMonth();
    long long getDateYear();
    void setValue( long long newDay , long long newMonth , long long newYear );
    long long getDifference( Date secondDate , bool IsBirthDay );
    Date getPreviusDate();
    Date getNextDate();
    QString IsLeap();



};

#endif // DATE_H
