#include <iostream>
#include <chrono>
#include <ctime>

void printArr(int arr[], int n)
{
    std::cout<<"Your array: \n";
    for(int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void heapify(int arr[], int n, int i, int size) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        printArr(arr, size);
        heapify(arr, n, largest, size);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i, n);

    for (int i = n - 1; i >= 0; --i) {
        std::swap(arr[0], arr[i]);
        printArr(arr, n);
        heapify(arr, i, 0, n);
    }
}

int partition(int arr[], int low, int high, int size) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
            printArr(arr, size);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int n) {
    if (low < high) {
        int pi = partition(arr, low, high, n);
        quickSort(arr, low, pi - 1, n);
        quickSort(arr, pi + 1, high, n);
    }
}

void merge(int arr[], int left, int mid, int right, int size) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }

    delete[] L;
    delete[] R;

    printArr(arr, size);

}

void mergeSort(int arr[], int left, int right, int size) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        printArr(arr, right + 1);
        mergeSort(arr, left, mid, size);
        mergeSort(arr, mid + 1, right, size);
        merge(arr, left, mid, right, size);
    }
}

int binarySearch(int arr[], int target, int size) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}


int main()
{
    srand(time(0));
    int n;
    std::cout << "Write size of array: ";
    std::cin >> n;
    int* arr = new int[n];
    int* newArr = new int[n];
    std::cout << "Write your array: ";
    for(int i = 0; i < n; i++)
    {
        arr[i] = 1 + rand() % 100;
        newArr[i] = arr[i];
    }
    auto startTime = std::chrono::high_resolution_clock::now();
    printArr(arr, n);
    heapSort(arr, n);
    auto endTime = std::chrono::high_resolution_clock::now();
    std:: cout << "Sorted array: ";
    printArr(arr, n);
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    std::cout << "Time for execution of heap sort:  " << duration.count() << "\n";
    for(int i = 0; i < n; i++)
    {
        arr[i] = newArr[i];
    }
    startTime.~time_point();
    startTime = std::chrono::high_resolution_clock::now();
    printArr(arr, n);
    mergeSort(arr, 0, n - 1, n);
    endTime = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    std::cout << "Time for execution of merge sort:  " << duration.count() << "\n";
    delete[] arr;
    arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        arr[i] = newArr[i];
    }
    startTime.~time_point();
    startTime = std::chrono::high_resolution_clock::now();
    printArr(arr, n);
    quickSort(arr, 0, n - 1, n);
    endTime = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    std::cout << "Time for execution of quick sort:  " << duration.count() << "\n";
    std::cout<<"Write number to find: ";
    int number;
    std::cin >> number;
    std::cout << "Position of number in array: " << binarySearch(arr, number, n);
    return 0;
}
