#ifndef SORT_H
#define SORT_H

#include <QVector>

class Sort
{
public:
    Sort();

    static void Sorty(QVector<int> &arr);
    static void SortAnimation(QVector<int> &arr, QVector<QVector<int> > &listOfStates);
};

#endif // SORT_H
