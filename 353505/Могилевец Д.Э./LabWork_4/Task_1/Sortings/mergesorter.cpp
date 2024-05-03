#include "mergesorter.h"

MergeSorter::MergeSorter() {}

void MergeSorter::Sort(QVector<int> &vect)
{
    mergeSort(vect, 0, vect.size() - 1);
}

void MergeSorter::SortAnimation(QVector<int> &vect, QVector<QVector<int>>& listOfBeings)
{
    mergeSortForAnimation(vect, 0, vect.size() - 1, listOfBeings);
}

void MergeSorter::merge(QVector<int> &arr, int start, int mid, int end)
{
    int start2 = mid + 1;
    if (arr[mid] <= arr[start2]) {
        return;
    }
    while (start <= mid && start2 <= end) {
        if (arr[start] <= arr[start2]) {
            start++;
        }
        else {
            int value = arr[start2];
            int index = start2;
            while (index != start) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[start] = value;
            start++;
            mid++;
            start2++;
        }
    }
}

void MergeSorter::mergeSort(QVector<int> &arr, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void MergeSorter::mergeSortForAnimation(QVector<int> &arr, int l, int r, QVector<QVector<int>>& listOfBeings)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortForAnimation(arr, l, m, listOfBeings);
        mergeSortForAnimation(arr, m + 1, r, listOfBeings);
        merge(arr, l, m, r);
        listOfBeings.append(arr);
    }
}




