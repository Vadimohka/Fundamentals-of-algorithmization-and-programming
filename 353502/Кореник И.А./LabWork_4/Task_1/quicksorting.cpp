#include "quicksorting.h"

QuickSorting::QuickSorting() {}

void QuickSorting::InSort(QVector<int> &arr, int left, int right, QHBoxLayout *visual)
{
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            SortingAnimation::swappNumbers(visual, &arr, i , j);
            AbstractSorting::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        InSort(arr, left, j, visual);
    if (i < right)
        InSort(arr, i, right, visual);
}

void QuickSorting::sort(QVector<int> &vect, QHBoxLayout *visual)
{
    InSort(vect, 0, vect.size() - 1, visual);
}
