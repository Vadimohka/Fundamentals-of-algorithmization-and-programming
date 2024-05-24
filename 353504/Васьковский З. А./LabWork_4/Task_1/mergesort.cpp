#include "mergesort.h"
#include <QDebug>
mergeSort::mergeSort() {}

void mergeSort::MergeSort(int* arr, int left, int right, QVector <QPair <int, int>>& vec)
{
    if (left < right){
        if (right - left == 1){
            if ((arr)[left] > (arr)[right]){
                vec.append(QPair<int, int>(left, right));
                mergeSort::swap(arr[left], arr[right]);
            }
        }
        else{
            MergeSort(arr, left, left + (right - left) / 2, vec);
            MergeSort(arr, left + (right - left) / 2 + 1, right, vec);
            Merge(arr, left, right, vec);

        }
    }
}

void mergeSort::Merge(int arr[], int begin, int end, QVector <QPair <int, int>>& vec)
{
    int i = begin;
    int mid = begin + (end - begin) / 2;
    int j = mid + 1;
    int k = 0;
    int d[1000];

    while (i <= mid && j <= end){
        if ((arr)[i] <= (arr)[j]){
            d[k] = arr[i];
            i++;
        }
        else{
            d[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid){
        d[k] = arr[i];
        i++;
        k++;
    }

    while (j <= end){
        d[k] = arr[j];
        j++;
        k++;
    }

    for(i = 0; i < k; ++i){
        int p;
        for (int z = 0; z < k ; ++z){
            if (arr[z + begin] == d[i]){
                p = z;
                vec.append(QPair<int, int>(begin + i, z + begin));
                mergeSort::swap(arr[i+ begin], arr[z + begin]);
                break;
            }
        }
    }
}

void mergeSort::swap(int &i, int &j)
{
    int sw = i;
    i = j;
    j = sw;
}
