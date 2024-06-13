#ifndef LAB1T1_WORKWITHDATE_H
#define LAB1T1_WORKWITHDATE_H

#include <QtWidgets>

class workWithDate {

    QVector<QDate> datesList;

public:
    workWithDate() = default;

    void addDate(QDate date) {
        datesList.push_back(date);
    }

    QString getDate(int a) {
        if(a < datesList.size() && a >= 0) return fromDateToString(datesList[a]);
    }

    QString getPrevDate(int a);

    QString getNextDate(int a);

    bool getIsYearLeap(int a);

    long long cntDaysToBD(QDate bdDate, int a);

    long long getWeekNumber(int a);

    long long getDefWithPrev(int a);

    int changeDate(QDate wasDate, QDate newDate);

    static QString fromDateToString(QDate date);

};


#endif
