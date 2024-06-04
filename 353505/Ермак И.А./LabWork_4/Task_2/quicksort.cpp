#include "quicksort.h"

QuickSort::QuickSort() {}

void QuickSort::swap(int &a, int &b) {
    int k = a;
    a = b;
    b = k;
}

void QuickSort::quickSort(QVector<int> &arr)
{
    BuiltInQuickSort(arr, 0, arr.size() - 1);
}

void QuickSort::quickSort(QVector<int> &arr, QVector<QVector<int>> &list)
{
    BuiltInQuickSort(arr, list, 0, arr.size() - 1);
}


void QuickSort::BuiltInQuickSort(QVector<int> &arr, int left, int right)
{
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        BuiltInQuickSort(arr, left, j);
    if (i < right)
        BuiltInQuickSort(arr, i, right);
}

void QuickSort::BuiltInQuickSort(QVector<int> &arr, QVector<QVector<int> > &list, int left, int right)
{
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            list.append(arr);
            i++;
            j--;
        }
    }
    if (left < j)
        BuiltInQuickSort(arr, list, left, j);
    if (i < right)
        BuiltInQuickSort(arr, list, i, right);
}
