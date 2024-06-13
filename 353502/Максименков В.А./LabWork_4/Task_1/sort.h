#ifndef SORT_H
#define SORT_H

#include <QVector>

class Sort
{
private:
    static void heapify(QVector<int>& v, int n, int i);
    static void Merge(QVector<int>& v, int l, int r);

public:
    Sort();

    static void HeapSort(QVector<int>& v, int n);
    static void QuickSort(QVector<int>& v, int l, int r);
    static void MergeSort(QVector<int>& v, int first, int last);
};

#endif // SORT_H
