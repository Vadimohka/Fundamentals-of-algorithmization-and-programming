#include "merge_sort.h"

merge_sort::merge_sort() {}

QVector<QVector<long long> >& merge_sort::get_result(QVector<long long>& arr) {
    sort_result.push_back(arr);
    clock_t t0 = clock();
    sort(arr);
    size_t t = clock() - t0;
    time_of_sort = (double)t / CLOCKS_PER_SEC * 100000.0;
    sort_result.push_back(arr);
    return sort_result;
}

qint64 merge_sort::get_time_of_sort()
{
    return time_of_sort;
}

void merge_sort::sort(QVector<long long>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}

void merge_sort::mergeSort(QVector<long long>& arr, long long left, long long right) {
    if (left < right) {
        long long middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

void merge_sort::merge(QVector<long long>& arr, long long left, long long middle, long long right) {
    long long n1 = middle - left + 1;
    long long n2 = right - middle;

    QVector<long long> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[middle + 1 + j];

    long long i = 0, j = 0, k = left;
    bool changed = false;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            if (arr[k] != leftArr[i])
                changed = true;
            arr[k] = leftArr[i];
            ++i;
        } else {
            if (arr[k] != rightArr[j])
                changed = true;
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
        if (changed)
            sort_result.push_back(arr);
    }

    while (i < n1) {
        if (arr[k] != leftArr[i])
            changed = true;
        arr[k] = leftArr[i];
        ++i;
        ++k;
        if (changed)
            sort_result.push_back(arr);
    }

    while (j < n2) {
        if (arr[k] != rightArr[j])
            changed = true;
        arr[k] = rightArr[j];
        ++j;
        ++k;
        if (changed)
            sort_result.push_back(arr);
    }
}

