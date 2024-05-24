#include "heapsort.h"

HeapSort::HeapSort() {}

void HeapSort::heapSort(int *arr, int n, QVector <QPair <int, int>>& vec)
{
    for (int i = n/2; i >= 0; i--) heap(arr, i, n, vec);
    for (int i = n - 1; i >= 1; i--) {
        vec.append(QPair<int, int> (0, i));
        HeapSort::swap(arr[0], arr[i]);
        heap(arr, 0, i, vec);
    }

}

void HeapSort::heap(int *arr, int i, int n, QVector <QPair <int, int>>& vec)
{
    int max = i;
    while (true){
        int child = 2 * i + 1;
        if (child < n && arr[child] > arr[max]) max = child;

        child++;
        if (child < n && arr[child] > arr[max]) max = child;

        if (max == i) break;
        else{
            vec.append(QPair<int, int> (max, i));
            HeapSort::swap(arr[max], arr[i]);
            i = max;
        }

    }
}

void HeapSort::swap(int &i, int &j)
{
    int sw = i;
    i = j;
    j = sw;
}
