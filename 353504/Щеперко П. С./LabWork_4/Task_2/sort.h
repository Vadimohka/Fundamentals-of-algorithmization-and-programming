#ifndef SORT_H
#define SORT_H

#include <QVector>
#include <QTimer>
#include <QEventLoop>

class Sort
{
public:
    static void InterpolationSort(int *arr, int size);
    static int BinarySearch(int *arr, int size, int find);
    static int BinPow(int num, int pow, int mod);
};

#endif // SORT_H
