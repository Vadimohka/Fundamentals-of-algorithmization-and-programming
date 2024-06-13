#include "mergesorting.h"

MergeSorting::MergeSorting() {}

void MergeSorting::sort(QVector<int>& arr, QHBoxLayout* visual) {
    mergeSort(arr, 0, arr.size() - 1, visual);
}

void MergeSorting::mergeSort(QVector<int>& arr, int left, int right, QHBoxLayout* visual) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle, visual);
        mergeSort(arr, middle + 1, right, visual);
        merge(arr, left, middle, right, visual);
    }
}

void MergeSorting::merge(QVector<int>& arr, int left, int middle, int right, QHBoxLayout* visual) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    QVector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;


    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {

            SortingAnimation::changeValue(visual, &arr, k, leftArr[i]);
            arr[k] = leftArr[i];
            ++i;
        } else {

            SortingAnimation::changeValue(visual, &arr, k, rightArr[j]);
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;

    }

    while (i < n1) {

        SortingAnimation::changeValue(visual, &arr, k, leftArr[i]);
        arr[k] = leftArr[i];
        ++i;
        ++k;

    }

    while (j < n2) {

        SortingAnimation::changeValue(visual, &arr, k, rightArr[j]);
        arr[k] = rightArr[j];
        ++j;
        ++k;

    }
}
