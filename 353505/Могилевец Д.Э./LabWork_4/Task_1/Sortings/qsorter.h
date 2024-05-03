#ifndef QSORTER_H
#define QSORTER_H

#include <QVector>
#include "swapanimator.h"

class QSorter
{
private:
    void static InSort(QVector<int>&, int, int);
    void static InSortAnimation(QVector<int>&, int, int, QVector<QVector<int>>&);
    int partition(QVector<int>&, int, int);
public:
    QSorter();
    void static Sort(QVector<int>&);
    void static SortAnimation(QVector<int>&, QVector<QVector<int>>&);
};

#endif // QSORTER_H
