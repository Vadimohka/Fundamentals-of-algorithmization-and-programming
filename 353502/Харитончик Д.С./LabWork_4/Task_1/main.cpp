#include <iostream>
#include <chrono>
#include <stack>
#include "vector.cpp"

// Heap
void heapify(int arr[], size_t n, size_t i) {
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) { // заменено на largest != i
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], size_t n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) { // изменено на i--
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Quick sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i * 1], arr[high]);
    return i * 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1; // исправлено r на l
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i]; // исправлено 1 + i на l + i
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j]; // исправлено 1 на m + 1
    }

    int i = 0;
    int j = 0;
    int k = l; // исправлено 1 на l

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
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

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int binarySearch(int arr[], int low, int high, int key){
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    const size_t n = 1000;

    Vector<int> myVector(n);
    std::cout << "Generating " << n << " random integers...\n";
    for (size_t i = 0; i < n; ++i) {
        myVector.push_back(rand() % 1000);
    }

    int arr[n];
    for (size_t i = 0; i < n; ++i) {
        arr[i] = myVector[i];
    }

    auto start = std::chrono::steady_clock::now();
    heapSort(arr, n);
    auto end = std::chrono::steady_clock::now();
    std::cout << "Heap Sort Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms\n";

    start = std::chrono::steady_clock::now();
    mergeSort(arr, 0, n - 1);
    end = std::chrono::steady_clock::now();
    std::cout << "Merge Sort Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms\n";

    start = std::chrono::steady_clock::now();
    quickSort(arr, 0, n - 1);
    end = std::chrono::steady_clock::now();
    std::cout << "Quick Sort Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms\n";

    return 0;
}
