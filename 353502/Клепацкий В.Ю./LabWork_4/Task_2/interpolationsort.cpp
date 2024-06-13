#include "interpolationsort.h"

InterpolationSort::InterpolationSort() {}

void InterpolationSort::sort(QVector<int> &arr)
{
    int min = *std::min_element(arr.begin(), arr.end());
    int max = *std::max_element(arr.begin(), arr.end());
    interpolationSort(arr, 0, arr.size() - 1, min, max);
}

void InterpolationSort::interpolationSort(QVector<int> &arr, int l, int h, int min, int max)
{
    if (l < h) {
        int pos = (int) ((double) (arr[l] - min) / (max - min)) * (h - l);
        pos = std::max(0, std::min(pos, h - l));
        int temp = arr[l + pos];
        int first = l;
        int end = h;
        while (first <= end) {
            while (arr[first] < temp) {
                emit arrChanged();
                first++;
            }
            while (arr[end] > temp) {
                emit arrChanged();
                end--;
            }

            if (first <= end) {
                std::swap(arr[first], arr[end]);
                emit arrChanged();
                first++;
                end--;
            }
        }
        interpolationSort(arr, l, end, min, temp);
        interpolationSort(arr, first, h, temp, max);
    }
}
