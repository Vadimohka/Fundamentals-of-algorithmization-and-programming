#include "sort.h"

void Sort::HeapSort(int *arr, int size)
{
    int n = size;

    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        QEventLoop loop;
        QTimer::singleShot(20, &loop, &QEventLoop::quit);
        loop.exec();
        Heapify(arr, i, 0);
    }

}

void Sort::QuickSort(int *arr, int left, int right)
{
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            QEventLoop loop;
            QTimer::singleShot(20, &loop, &QEventLoop::quit);
            loop.exec();
            i++;
            j--;
        }
    }
    if (left < j)
        QuickSort(arr, left, j);
    if (i < right)
        QuickSort(arr, i, right);
}

void Sort::MergeSort(int *arr, int left, int right)
{
    if (left < right) {
        int m = left + (right - left) / 2;

        MergeSort(arr, left, m);
        MergeSort(arr, m + 1, right);

        Merge(arr, left, m, right);
    }
}

void Sort::Heapify(int *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        QEventLoop loop;
        QTimer::singleShot(20, &loop, &QEventLoop::quit);
        loop.exec();
        Heapify(arr, n, largest);
    }
}

void Sort::Merge(int* arr, int left, int m, int right) {
    int i, j, k;
    int n1 = m - left + 1;
    int n2 = right - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    QEventLoop loop;
    QTimer::singleShot(20, &loop, &QEventLoop::quit);
    loop.exec();
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

