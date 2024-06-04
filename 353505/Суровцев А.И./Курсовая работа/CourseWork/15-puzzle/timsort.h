#ifndef TIMSORT_H
#define TIMSORT_H

#include <QVector>

class TimSort
{
public:
    void insertionSort(QVector<long long> &arr, long long left, long long right);

    void merge(QVector<long long> &arr, long long l, long long m, long long r);

    void timSort(QVector<long long> &arr, long long n);
};

#endif // TIMSORT_H
