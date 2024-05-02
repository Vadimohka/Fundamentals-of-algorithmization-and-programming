#include "quick_sort.h"

quick_sort::quick_sort() {}

QVector<QVector<long long>>& quick_sort::get_result(QVector<long long>& arr) {
    sort_result.push_back(arr);
    clock_t t0 = clock();
    sort(arr);
    size_t t = clock() - t0;
    time_of_sort = (double)t / CLOCKS_PER_SEC * 100000.0;
    sort_result.push_back(arr);
    return sort_result;
}

qint64 quick_sort::get_time_of_sort()
{
    return time_of_sort;
}

void quick_sort::sort(QVector<long long>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

void quick_sort::quickSort(QVector<long long>& arr, long long start, long long end) {
    if (start >= end)
        return;

    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);

    quickSort(arr, p + 1, end);
}

long long quick_sort::partition(QVector<long long>& arr, long long start, long long end) {
    long long pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);
    sort_result.push_back(arr);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            std::swap(arr[i++], arr[j--]);
            sort_result.push_back(arr);
        }
    }

    return pivotIndex;
}
