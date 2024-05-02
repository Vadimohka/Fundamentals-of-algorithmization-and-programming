#include "binary_search.h"

binary_search::binary_search() {}

QVector<long long> &binary_search::get_result(QVector<long long> &arr, long long target)
{
    binarySearch(arr, target);
    return search_result;
}

long long binary_search::binarySearch(const QVector<long long> &arr, long long target)
{
    long long left = 0;
    long long right = arr.size() - 1;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        search_result.push_back(mid);
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}
