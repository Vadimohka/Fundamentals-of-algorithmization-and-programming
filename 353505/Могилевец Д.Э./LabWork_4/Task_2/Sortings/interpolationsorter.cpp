#include "interpolationsorter.h"

InterpolationSorter::InterpolationSorter() {}

void InterpolationSorter::Sort(QVector<int> &arr)
{
    int start = 0;
    int size = arr.size();
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }
    }
    if (min != max) {
        QVector<QVector<int>> bucket(size);
        int interpolation = 0;
        for (int i = 0; i < size; i++) {
            interpolation = (int)(((double)(arr[i] - min) / (max - min)) * (size - 1));
            bucket[interpolation].push_back(arr[i]);
        }
        for (int i = 0; i < size; i++) {
            if (bucket[i].size() > 1) {
                Sort(bucket[i]);
            }
            for (size_t j = 0; j < bucket[i].size(); j++) {
                arr[start++] = bucket[i][j];
            }
        }
    }
}

void InterpolationSorter::SortAnimation(QVector<int> &arr, QVector<QVector<int> > &listOfStates)
{
    int start = 0;
    int size = arr.size();
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }
    }
    if (min != max) {
        QVector<QVector<int>> bucket(size);
        int interpolation = 0;
        for (int i = 0; i < size; i++) {
            interpolation = (int)(((double)(arr[i] - min) / (max - min)) * (size - 1));
            bucket[interpolation].push_back(arr[i]);
        }
        for (int i = 0; i < size; i++) {
            if (bucket[i].size() > 1) {
                listOfStates.append(arr);
                Sort(bucket[i]);
            }
            for (size_t j = 0; j < bucket[i].size(); j++) {
                arr[start++] = bucket[i][j];
            }
        }
    }
    listOfStates.append(arr);
}
