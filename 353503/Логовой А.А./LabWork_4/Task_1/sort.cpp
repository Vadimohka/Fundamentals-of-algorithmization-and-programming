#include "sort.h"
#include <mainwindow.h>
#include <sortvisualizer.h>
#include <magicnumbers.h>

void Sort::heapify(int* arr, int size, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left] > arr[largest]){
        largest = left;
    }

    if (right < size && arr[right] > arr[largest]){
        largest = right;
    }

    if (largest != index) {
        MainWindow::skip(STOP);
        emit arrayUpdated(arr_global, SIZE);
        qSwap(arr[index],arr[largest]);
        heapify(arr, size, largest);
    }
}

void Sort::heapSort(int* arr, int size)
{
    arr_global = arr;
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
        MainWindow::skip(STOP);
        emit arrayUpdated(arr_global, SIZE);
    }

    for (int i = size - 1; i >= 0; i--) {
        qSwap(arr[0],arr[i]);
        heapify(arr, i, 0);
        MainWindow::skip(STOP);
        emit arrayUpdated(arr_global, SIZE);
    }
}

void Sort::merge(int* arr, int left, int middle, int right)
{
    arr_global = arr;
    int left_size = middle - left + 1;
    int right_size = right - middle;

    int* leftArray = new int[left_size];
    int* rightArray = new int[right_size];

    for (int i = 0; i < left_size; i++){
        leftArray[i] = arr[left + i];
    }
    for (int j = 0; j < right_size; j++){ 
        rightArray[j] = arr[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;

    for (; i < left_size && j < right_size; k++) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        }
        else {
            arr[k] = rightArray[j];
            j++;
        }
        MainWindow::skip(STOP);
        emit arrayUpdated(arr_global, SIZE);
    }


    for (; i < left_size; i++, k++){
        arr[k] = leftArray[i];
    }

    for (; j < right_size; j++, k++){
        arr[k] = rightArray[j];
    }

    delete[] leftArray;
    delete[] rightArray;
}

void Sort::mergeSort(int* arr, int left, int right)
{
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);

        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);

        emit arrayUpdated(arr_global, SIZE);
    }
}

void Sort::quickSort(int* arr, int start, int end)
{
    arr_global = arr;
    if (start >= end){
        return;
    }
    int part_sort = partQuickSort(arr, start, end);
    MainWindow::skip(STOP);
    emit arrayUpdated(arr_global, SIZE);
    quickSort(arr, start, part_sort - 1);
    quickSort(arr, part_sort, end);

}

int Sort::partQuickSort(int* arr, int left, int right)
{

    int mid = arr[(left + right) / 2];
    while (left <= right) {
        while (arr[left] < mid){
            left++;
        }
        while (arr[right] > mid){
            right--;
        }
        if (left <= right) {
            qSwap(arr[left], arr[right]);
            MainWindow::skip(STOP);
            emit arrayUpdated(arr_global, SIZE);
            left++;
            right--;
        }
    }
    return left;
}

void Sort::interpolationSort(int* arr, int start, int size) {
    arr_global = arr;

    int min = arr[start];
    int max = arr[start];

    for (int i = start + 1; i < start + size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }
    }

    if (min == max)
        return;

    double factor = static_cast<double>(size - 1) / (max - min);

    int* count = new int[size]();
    int* sorted = new int[size];

    for (int i = start; i < start + size; i++) {
        int index = static_cast<int>((arr[i] - min) * factor);
        count[index]++;
    }

    for (int i = 1; i < size; i++) {
        count[i] += count[i - 1];
    }

    for (int i = start + size - 1; i >= start; i--) {
        int index = static_cast<int>((arr[i] - min) * factor);
        sorted[--count[index]] = arr[i];
    }

    for (int i = start; i < start + size; i++) {
        arr[i] = sorted[i - start];
        MainWindow::skip(STOP);
        emit arrayUpdated(arr_global, SIZE);
    }

    delete[] count;
    delete[] sorted;
}
