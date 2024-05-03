#include "heap_sort.h"

heap_sort::heap_sort() {}

QVector<QVector<long long> > &heap_sort::get_result(QVector<long long> &arr)
{
    sort_result.push_back(arr);
    clock_t t0 = clock();
    sort(arr);
    size_t t = clock() - t0;
    time_of_sort = (double)t / CLOCKS_PER_SEC * 100000.0;
    sort_result.push_back(arr);
    return sort_result;
}

qint64 heap_sort::get_time_of_sort()
{
    return time_of_sort;
}

void heap_sort::sort(QVector<long long> &arr)
{
    long long n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void heap_sort::heapify(QVector<long long> &arr, long long n, long long i)
{
    long long largest = i;
    long long l = 2 * i + 1;
    long long r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        sort_result.push_back(arr);
        heapify(arr, n, largest);
    }
}
