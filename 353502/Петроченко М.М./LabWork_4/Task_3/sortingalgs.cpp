//
// Created by acryoz on 6.4.24.
//
#include "../headers/sortingalgs.h"
#include <QDebug>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>

Sorting::Sorting() {
    this->text_stream = new QTextStream(&this->interpolation_sort_log);
}

void Sorting::heapify(int* array, int len, int cur_leaf) {
    int left = 2 * cur_leaf + 1;
    int right = 2 * cur_leaf + 2;
    int biggest = cur_leaf;
    if (left < len && array[biggest] < array[left]) {
        biggest = left;
    }
    if (right < len && array[biggest] < array[right]) {
        biggest = right;
    }
    if (biggest != cur_leaf) {
        std::swap(array[cur_leaf], array[biggest]);
        emit changed(cur_leaf, biggest);
        heapify(array, len, biggest);
    }
}

void Sorting::buildHeap(int* array, int len) {
    for (int i = std::floor(len / 2) - 1; i >= 0; --i) {
        heapify(array, len, i);
    }
}

void Sorting::heapSort(int* array, int len) {
    buildHeap(array, len);
    int heaplen = len;
    while (heaplen > 1) {
        std::swap(array[0], array[heaplen - 1]);
        emit changed(0, heaplen - 1);
        heaplen -= 1;
        buildHeap(array, heaplen);
    }
}

void Sorting::merge(int* arr, int left, int mid, int right) {
    int len1 = mid - left + 1;
    int len2 = right - mid;
    int len = right - left + 1;
    int left_index = 0;
    int right_index = 0;
    int* left_sub = new int[len1];
    int* right_sub = new int[len2];
    for (int c = 0; c < len1; ++c) {
        left_sub[c] = arr[left + c];
    }
    for (int c = 0; c < len2; ++c) {
        right_sub[c] = arr[c + mid + 1];
    }
    for (int j = left; j < left + len; ++j) {
        if (left_index < len1 && right_index < len2 &&
            left_sub[left_index] <= right_sub[right_index]) {
            arr[j] = left_sub[left_index];
            emit changed(j, left + left_index);
            ++left_index;
        } else if (left_index < len1 && right_index >= len2) {
            arr[j] = left_sub[left_index];
            emit changed(j, left + left_index);
            ++left_index;
        } else if (left_index < len1 && right_index < len2 &&
                   right_sub[right_index] < left_sub[left_index]) {
            arr[j] = right_sub[right_index];
            emit changed(j, mid + 1 + right_index);
            ++right_index;
        } else if (left_index >= len1 && right_index < len2) {
            arr[j] = right_sub[right_index];
            emit changed(j, mid + 1 + right_index);
            ++right_index;
        }
    }
    delete[] left_sub;
    delete[] right_sub;
}

void Sorting::mergeSort(int* array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int Sorting::partition(int* array, int left, int right) {
    int pivot = array[left + (right - left) / 2];
    int i = left;
    int j = right;
    while (i <= j) {
        while (array[i] < pivot) {
            ++i;
        }
        while (array[j] > pivot) {
            --j;
        }
        if (i >= j) {
            break;
        }
        std::swap(array[i++], array[j--]);
        emit changed(i - 1, j + 1);
    }
    return j;
}

int Sorting::partition(QVector<int>& array, int left, int right) {
    int pivot = array[left + (right - left) / 2];
    int i = left;
    int j = right;
    while (i <= j) {
        while (array[i] < pivot) {
            ++i;
        }
        while (array[j] > pivot) {
            --j;
        }
        if (i >= j) {
            break;
        }
        std::swap(array[i++], array[j--]);
        emit changed(i - 1, j + 1);
    }
    return j;
}

void Sorting::quickSort(int* array, int left, int right) {
    if (left < right) {
        int piv = partition(array, left, right);
        quickSort(array, left, piv);
        quickSort(array, piv + 1, right);
    }
}

void Sorting::clear() {
    this->interpolation_step = 0;
    this->text_stream->flush();
    this->interpolation_sort_log.clear();
}

void Sorting::interpolationSort(QVector<int>& vec) {
    *this->text_stream << "Step " << this->interpolation_step++
                       << ":\nVector: ";
    for (int item : vec) {
        *this->text_stream << item << ' ';
    }
    *this->text_stream << '\n';
    int pos = 0;
    int min = vec[0];
    int max = vec[0];
    for (int item : vec) {
        if (item > max) {
            max = item;
        } else if (item < min) {
            min = item;
        }
    }
    if (min == max) {
        return;
    }
    QVector<QVector<int>> buckets(vec.length());
    for (int item : vec) {
        int bucket_index =
            std::floor((double)(item - min) / (max - min) * (vec.length() - 1));
        buckets[bucket_index].push_back(item);
    }
    for (int i = 0; i < buckets.length(); ++i) {
        if (!buckets[i].isEmpty()) {
            *this->text_stream << "Bucket " << i << ": ";
            for (int item : buckets[i]) {
                *this->text_stream << item << " ";
            }
            *this->text_stream << '\n';
        }
    }
    for (int i = 0; i < vec.length(); ++i) {
        if (buckets[i].length() > 1) {
            interpolationSort(buckets[i]);
        }
        for (int j = 0; j < buckets[i].length(); ++j) {
            vec[pos++] = buckets[i][j];
        }
    }
    *this->text_stream << "\nSorted vec:";
    for (int item : vec) {
        *this->text_stream << item << ' ';
    }
}

void Sorting::print(int* array, int len) {
    for (int i = 0; i < len; ++i) {
        std::cout << array[i] << ", ";
    }
    std::cout << '\n';
}

QString Sorting::getLogs() {
    return this->interpolation_sort_log;
}

QVector<QVector<int>> Sorting::splitInMs(QVector<int>& vec, int m) {
    int size = (vec.size() % m == 0) ? vec.size() / m : vec.size() / m + 1;
    QVector<QVector<int>> res(size);
    int j = 0;
    for (int i = 0; i < size; ++i) {
        for (int k = 0; k < m; ++k) {
            res[i].push_back(vec[j + k]);
        }
        j += m;
    }
    for (; j < vec.size(); ++j) {
        res[size - 1].push_back(vec[j]);
    }
    return res;
}

QVector<int> Sorting::kthOrder(QVector<int>& vec, int k, int m) {
    auto split = this->splitInMs(vec, m);
    QVector<int> res(split.size());
    for (int i = 0; i < split.size(); ++i) {
        int left = 0;
        int right = split[i].length() - 1;
        if (split[i].size() < k) {
            int avg = 0;
            for (int number : split[i]) {
                avg += number;
            }
            avg /= split[i].size();
            res[i] = avg;
        } else {
            while (true) {
                int partition = this->partition(split[i], left, right);
                if (k < partition) {
                    right = partition;
                } else if (k > partition) {
                    left = partition + 1;
                } else {
                    res[i] = split[i][partition];
                    break;
                }
            }
        }
    }
    return res;
}
