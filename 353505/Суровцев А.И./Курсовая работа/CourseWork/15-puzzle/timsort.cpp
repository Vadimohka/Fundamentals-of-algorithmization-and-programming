#include "timsort.h"

void TimSort::insertionSort(QVector<long long> &arr, long long left, long long right) {
    for (long long i = left + 1; i <= right; i++) {
        long long temp = arr[i];
        long long j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void TimSort::merge(QVector<long long> &arr, long long l, long long m, long long r) {
    long long len1 = m - l + 1, len2 = r - m;
    QVector<long long> left(len1), right(len2);
    for (long long i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (long long i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
    long long i = 0;
    long long j = 0;
    long long k = l;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < len1) {
        arr[k] = left[i];
        k++;
        i++;
    }
    while (j < len2) {
        arr[k] = right[j];
        k++;
        j++;
    }
}

void TimSort::timSort(QVector<long long> &arr, long long n) {
    const long long RUN = 32;
    for (long long i = 0; i < n; i += RUN)
        insertionSort(arr, i, std::min((i + RUN - 1), (n - 1)));

    for (long long size = RUN; size < n; size = 2 * size) {
        for (long long left = 0; left < n; left += 2 * size) {
            long long mid = left + size - 1;
            long long right = std::min((left + 2 * size - 1), (n - 1));
            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}
