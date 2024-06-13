#ifndef INTERPOLATIONSORT_H
#define INTERPOLATIONSORT_H

#include <QtWidgets>

class InterpolationSort : public QObject
{
    Q_OBJECT
public:
    InterpolationSort();
    void sort(QVector<int> &arr);
    void interpolationSort(QVector<int> &arr, int l, int h, int min, int max);
signals:
    void arrChanged();
};

#endif // INTERPOLATIONSORT_H
