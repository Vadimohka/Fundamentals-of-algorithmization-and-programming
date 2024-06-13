#include "heapsorting.h"

HeapSorting::HeapSorting() {}

void HeapSorting::heapify(QVector<int>& arr, int N, int i, QHBoxLayout* arrayAnimation)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && arr[l] > arr[largest])
        largest = l;
    if (r < N && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        SortingAnimation::swappNumbers(arrayAnimation, &arr, i, largest);
        AbstractSorting::swap(arr[i], arr[largest]);
        heapify(arr, N, largest, arrayAnimation);
    }
}

void HeapSorting::sort(QVector<int>& arr, QHBoxLayout* arrayAnimation)
{
    for (int i = arr.size() / 2 - 1; i >= 0; i--)
        heapify(arr, arr.size(), i, arrayAnimation);
    for (int i = arr.size() - 1; i > 0; i--) {
        SortingAnimation::swappNumbers(arrayAnimation, &arr, 0, i);
        AbstractSorting::swap(arr[0], arr[i]);
        heapify(arr, i, 0, arrayAnimation);
    }
}


