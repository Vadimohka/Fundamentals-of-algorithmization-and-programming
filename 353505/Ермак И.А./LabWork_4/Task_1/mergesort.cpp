#include "mergesort.h"
#include "qcontainerfwd.h"

MergeSort::MergeSort() {}

void MergeSort::mergeSort(QVector<int> &vector)
{
    BuiltInMergeSort(vector, 0, vector.size() - 1);
}

void MergeSort::mergeSort(QVector<int> &vector, QVector<QVector<int>>& list)
{
    BuiltInMergeSort(vector, list, 0, vector.size() - 1);
}

void MergeSort::Merge(QVector<int> &arr, int start, int mid, int end)
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

void MergeSort::BuiltInMergeSort(QVector<int> &arr, int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;
        BuiltInMergeSort(arr, left, mid);
        BuiltInMergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

void MergeSort::BuiltInMergeSort(QVector<int> &arr, QVector<QVector<int>>& list, int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;
        BuiltInMergeSort(arr, list, left, mid);
        BuiltInMergeSort(arr, list, mid + 1, right);
        Merge(arr, left, mid, right);
        list.append(arr);
    }
}
