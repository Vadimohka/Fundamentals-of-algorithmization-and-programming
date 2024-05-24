#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <QVector>

class QuickSort
{
public:
    QuickSort();

    void quickSort(QVector<int> &, QVector<QVector<int>> &);
    void quickSort(QVector<int> &);
private:
    void BuiltInQuickSort(QVector<int> &, QVector<QVector<int>> &, int, int);
    void BuiltInQuickSort(QVector<int> &, int, int);
    void swap(int&, int&);
};

#endif // QUICKSORT_H
