#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <QPair>
#include <QVector>

class QuickSort
{
public:
    QuickSort();
    void static qiuckSort(int* arr, int left, int right, QVector <QPair <int, int>>& vec, int &n);
    static void swap(int& i, int& j);
};

#endif // QUICKSORT_H
