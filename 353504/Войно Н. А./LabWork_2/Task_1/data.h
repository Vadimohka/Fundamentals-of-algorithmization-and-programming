#ifndef MY_DATA_H
#define MY_DATA_H

#include <QStandardItemModel>

class mydata
{
public:
    mydata();

    mydata NextDay();
    mydata PreviousDay();
    void setData(QStandardItemModel *model, QModelIndex *index, int row, int column);
    int DaysTillYourBithday(mydata bithdaydate);
    int Duration (mydata date);
private:

};

#endif // DATA_H
