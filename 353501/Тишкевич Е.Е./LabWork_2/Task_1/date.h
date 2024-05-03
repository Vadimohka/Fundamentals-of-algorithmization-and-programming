#ifndef DATE_H
#define DATE_H

#include <QtWidgets>

class Date {


public:
    QVector<QDate> datesList={};
    Date() = default;

    void addDate(QDate data) {
        datesList.push_back(data);
    }

    int getSize()
    {
        return datesList.size();
    }

    void deleteDate(int index) {
        datesList.erase(datesList.begin()+index);
    }

    void changeDate(int  index, QDate newDate)
    {
        datesList[index]= newDate;
    }

    void clear()
    {
        datesList.clear();
    }

    QString getDate(int a) {
        if(a < datesList.size() && a >= 0) return fromDateToString(datesList[a]);
        else return "";
    }


    QString prevDate(int a);

    QString nextDate(int a);

    bool isLeap(int a);

    long long getWeekNumber(int a);

    long long getDefWithPrev(int a);

    long long getDiff(int, QDate);

    int changeDate(QDate wasDate, QDate newDate);

    static QString fromDateToString(QDate date);

};


#endif
