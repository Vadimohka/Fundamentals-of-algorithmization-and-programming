#include "heapsort.h"

HeapSort::HeapSort() {}

void HeapSort::swap(int &a, int &b) {
    int k = a;
    a = b;
    b = k;
}


void HeapSort::heap(QVector<int>& arr, int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (right < N && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heap(arr, N, largest);
    }
}

void HeapSort::heapSort(QVector<int>& arr)
{
    for (int i = arr.size() / 2 - 1; i >= 0; i--)
        heap(arr, arr.size(), i);
    for (int i = arr.size() - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heap(arr, i, 0);
    }
}

void HeapSort::heapSort(QVector<int> &arr, QVector<QVector<int> > &list)
{
    for (int i = arr.size() / 2 - 1; i >= 0; i--)
        heap(arr, arr.size(), i);
    for (int i = arr.size() - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        list.push_back(arr);
        heap(arr, i, 0);
    }
}
