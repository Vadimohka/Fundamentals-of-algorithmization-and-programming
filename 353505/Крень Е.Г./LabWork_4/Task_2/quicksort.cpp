#include "quicksort.h"

QuickSort::QuickSort()
{
}

static void QSort(QVector<int> &arr, int left, int right, Widget* w)
{
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot){
            //comparisions++;
            //arrayAccesses++;
            i++;
        }
        while (arr[j] > pivot){
            //comparisions++;
            //arrayAccesses++;
            j--;
        }
        if (i <= j) {
            std::swap(arr[i],arr[j]);
            //arrayAccesses+=2;
            //swaps++;
            w->sortAnimation(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        QSort(arr, left, j, w);
    if (i < right)
        QSort(arr, i, right, w);
}
