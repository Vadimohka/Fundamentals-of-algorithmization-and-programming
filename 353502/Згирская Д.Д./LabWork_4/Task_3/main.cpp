#include <iostream>
#include <vector>

void toMaxHeap(int* array, int size, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    if (left < size && array[left] > array[largest])
        largest = left;
    if (right < size && array[right] > array[largest])
        largest = right;
    if (largest != root) {
        std::swap(array[root], array[largest]);
        toMaxHeap(array, size, largest);
    }
}

void heapSort(int array[], int size) {
    for (int i = size / 2 - 1; i >= 0; --i)
        toMaxHeap(array, size, i);
    for (int i = size - 1; i > 0; --i) {
        std::swap(array[0], array[i]);
        toMaxHeap(array, i, 0);
    }
}

int main() {
    std::vector<double> a;
    std::vector<double> b;
    int count;
    int number;
    int sortedArray[3];
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        std::cin >> number;
        a.push_back(number);
    }
    for (double i = 0, middle; i < count; i += 3) {
        if (i + 2 < count) {
           sortedArray[0] = a[i];
           sortedArray[1] = a[i + 1];
           sortedArray[2] = a[i + 2];
           heapSort(sortedArray, 3);
           b.push_back(sortedArray[1]);
        }
        else if (i + 1 < count) {
            middle = (a[i] + a[i + 1]) / 2;
            b.push_back(middle);
        }
    }
    for (auto B: b) {
        std::cout << B << ' ';
    }
    return 0;
}
