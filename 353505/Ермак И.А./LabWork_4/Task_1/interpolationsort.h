#ifndef INTERPOLATIONSORT_H
#define INTERPOLATIONSORT_H

#include <QVector>

class InterpolationSort
{
public:
    InterpolationSort();
    void interpolationSort(QVector<int>&, QVector<QVector<int> >&);
    void interpolationSort(QVector<int>&);
};

#endif // INTERPOLATIONSORT_H
