#ifndef MYDATA_H
#define MYDATA_H

#include <QStandardItemModel>

class mydata
{
public:
    mydata();
    mydata NextDay();
    mydata PreviousDay();
    bool leaf();
    short WeekNumber();
    void set(QStandardItemModel *model, QModelIndex &index);
    int DaysTillYourBithday(mydata bithdaydate);
    int Duration (mydata date);
    void get(QString string);
    QString ret();

private:
    QString dates;
};

#endif // MYDATA_H
