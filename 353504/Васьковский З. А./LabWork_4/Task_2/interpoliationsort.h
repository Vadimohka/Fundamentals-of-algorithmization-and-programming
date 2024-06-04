#ifndef INTERPOLIATIONSORT_H
#define INTERPOLIATIONSORT_H

#include <QPair>
#include <QVector>

class InterpoliationSort
{
public:
    InterpoliationSort();
    void static swap(int& i, int& j);
    void static interpolationSort(QVector<int>& A, QVector <QVector<int>>& motionVector);
};

#endif // INTERPOLIATIONSORT_H
