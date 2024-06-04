#include "sorts.h"

void heapify(SVector& array, int size, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    if (left < size && array[left] > array[largest])
    {
        largest = left;
    }
    if (right < size && array[right] > array[largest])
    {
        largest = right;
    }
    if (largest != root)
    {
        std::swap(array[root], array[largest]);
        array.emitSignal(root, array[root]);
        array.emitSignal(largest, array[largest]);
        heapify(array, size, largest);
    }
}

void Sorts::heapSort(SVector& array)
{
    for (int i = array.size() / 2 - 1; i >= 0; --i)
    {
        heapify(array, array.size(), i);
    }
    for (int i = array.size() - 1; i >= 0; --i)
    {
        std::swap(array[0], array[i]);
        array.emitSignal(0, array[0]);
        array.emitSignal(i, array[i]);
        heapify(array, i, 0);
    }
}

void merge(SVector& array, int left, int mid, int right)
{
    int size1 = mid - left + 1;
    int size2 = right - mid;

    int* leftA = new int[size1];
    int* rightA = new int[size2];

    for (int i = 0; i < size1; ++i)
    {
        leftA[i] = array[left + i];
    }
    for (int i = 0; i < size2; ++i)
    {
        rightA[i] = array[mid + 1 + i];
    }

    int i = 0, j = 0, k;

    for (k = left; k <= right && i < size1 && j < size2; ++k)
    {
        if (leftA[i] <= rightA[j])
        {
            array[k] = leftA[i++];
        }
        else
        {
            array[k] = rightA[j++];
        }
        array.emitSignal(k, array[k]);
    }
    for (; i < size1; ++i)
    {
        array[k++] = leftA[i];
        array.emitSignal(k - 1, array[k - 1]);
    }
    for (; j < size2; ++j)
    {
        array[k++] = rightA[j];
        array.emitSignal(k - 1, array[k - 1]);
    }
    delete[] leftA;
    delete[] rightA;
}

void Sorts::mergeSort(SVector& array, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

void Sorts::quickSort(SVector& array, int left, int right)
{
    int l = left, r = right;
    int mid = array[(l + r) / 2];
    while (l <= r)
    {
        while (array[l] < mid)
        {
            l++;
        }
        while (array[r] > mid)
        {
            r--;
        }
        if (l <= r)
        {
            std::swap(array[l++], array[r--]);
            array.emitSignal(l - 1, array[l - 1]);
            array.emitSignal(r + 1, array[r + 1]);
        }
    }
    if (left < r)
    {
        quickSort(array, left, r);
    }
    if (right > l)
    {
        quickSort(array, l, right);
    }
}

int Sorts::binsearch(SVector& array, int digit)
{
    int left = 0, right = array.size() - 1;
    while (right > left)
    {
        int mid = (left + right) / 2;
        if (array[mid] > digit)
        {
            right = mid - 1;
        }
        else if (array[mid] < digit)
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    if (array[left] == digit)
    {
        return left;
    }
    else
    {
        return -1;
    }
}
