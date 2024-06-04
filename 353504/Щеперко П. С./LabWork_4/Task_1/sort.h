#ifndef SORT_H
#define SORT_H

#include <QTimer>
#include <QEventLoop>
#include <utility>

class Sort
{
public:
    static void HeapSort(int *arr, int size);
    static void QuickSort(int *arr, int left, int right);
    static void MergeSort(int* arr, int left, int right);

private:
    static void Heapify(int* arr, int n, int i);
    static void Merge(int* arr, int left, int m, int right);
};

#endif // SORT_H
