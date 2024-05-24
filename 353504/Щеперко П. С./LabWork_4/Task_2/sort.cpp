#include "sort.h"


void Sort::InterpolationSort(int *arr, int size)
{
    std::vector<int> divideSize;
    int end = size;
    divideSize.push_back(end);

    while (!divideSize.empty()) {
        int size = divideSize.back();
        divideSize.pop_back();
        int start = end - size;
        int min = arr[start];
        int max = arr[start];

        for (int i = start + 1; i < end; i++) {
            if (arr[i] < min) {
                min = arr[i];
            } else if (arr[i] > max) {
                max = arr[i];
            }
        }

        if (min == max) {
            end -= size;
        } else {
            int p = 0;
            std::vector<std::vector<int>> bucket(size);
            for (int i = start; i < end; i++) {
                p = static_cast<int>(((arr[i] - min) / static_cast<double>(max - min)) * (size - 1));
                bucket[p].push_back(arr[i]);
            }

            for (int i = 0; i < size; i++) {
                if (!bucket[i].empty()) {
                    for (int j = 0; j < bucket[i].size(); j++) {
                        arr[start++] = bucket[i][j];
                        std::swap(bucket[i][j], bucket[i][j+1]);
                        QEventLoop loop;
                        QTimer::singleShot(20, &loop, &QEventLoop::quit);
                        loop.exec();
                    }
                    divideSize.push_back(bucket[i].size());
                }
            }
        }
    }
}

int Sort::BinarySearch(int *arr, int size, int find)
{
    int l = 0, r = size - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == find) {
            return mid;
        }
        if (arr[mid] < find) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (arr[l] == find)
        return l;
    else if (arr[r] == find)
        return r;
    else
        return -1;
}

int Sort::BinPow(int num, int pow, int mod)
{
    if (pow == 0) {
        return 1;
    }
    if (pow % 2 == 1) {
        return (BinPow(num, pow - 1, mod) * num) % mod;
    }
    else {
        unsigned long long b = BinPow(num, pow / 2, mod) % mod;
        return (b * b) % mod;
    }
}
