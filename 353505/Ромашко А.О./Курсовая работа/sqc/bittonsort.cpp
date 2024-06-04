#include "bittonsort.h"

BittonSort::BittonSort() {}

void BittonSort::bitseqsort(QVector<int>& arr, int left, int right, bool inv) {
    if (right - left <= 1) return;
    int mid = left + (right - left) / 2;
    for (int i = left, j = mid; i < mid && j < right; i++, j++) {
        if (inv ^ (arr[i] > arr[j])) {
            std::swap(arr[i], arr[j]);
        }
    }
    bitseqsort(arr, left, mid, inv);
    bitseqsort(arr, mid, right, inv);
}

void BittonSort::makebitonic(QVector<int>& arr, int left, int right) {
    if (right - left <= 1) return;
    int mid = left + (right - left) / 2;
    makebitonic(arr, left, mid);
    bitseqsort(arr, left, mid, false);
    makebitonic(arr, mid, right);
    bitseqsort(arr, mid, right, true);
}

void BittonSort::bitonicsort(QVector<int>& arr) {
    int n = 1;
    int inf = *std::max_element(arr.begin(), arr.end()) + 1;
    while (n < arr.size()) n *= 2;

    QVector<int> a(n);
    int cur = 0;
    for (int i = 0; i < arr.size(); i++) {
        a[cur++] = arr[i];
    }
    while (cur < n) {
        a[cur++] = inf;
    }

    makebitonic(a, 0, n);
    bitseqsort(a, 0, n, false);

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = a[i];
    }
}

