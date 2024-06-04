#ifndef MERGESORT_H
#define MERGESORT_H
#include <QPair>
#include <QVector>

class mergeSort
{
public:
    mergeSort();
    static void MergeSort(int* arr, int left, int right, QVector <QPair <int, int>>& vec);
    static void Merge(int arr[], int begin, int end, QVector <QPair <int, int>>& vec);
    void static swap(int& i, int& j);
};

#endif // MERGESORT_H
