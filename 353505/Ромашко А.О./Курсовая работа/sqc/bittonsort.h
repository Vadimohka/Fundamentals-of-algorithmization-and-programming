#ifndef BITTONSORT_H
#define BITTONSORT_H
#include <QVector>
#include <algorithm>
#include <iostream>


class BittonSort
{
public:
    BittonSort();
    static void bitseqsort(QVector<int> &arr, int left, int right, bool inv);
    static void makebitonic(QVector<int> &arr, int left, int right);
    static void bitonicsort(QVector<int> &arr);
};

#endif // BITTONSORT_H
