#include <iostream>
#include <chrono>

using Time = std::chrono::time_point<std::chrono::high_resolution_clock>;
using Delta = std::chrono::milliseconds;

void interpolationSort(int array[], int n) {
    for (int i = 1; i < n; i++) {
        int pivot = array[i];
        int left = 0, right = i - 1;
        int denominator = array[right] - array[left];

        if (denominator == 0) {
            while (left <= right && pivot < array[right]) {
                right--;
            }
        } else {
            while (left <= right) {
                int middle = left + ((pivot - array[left]) * (right - left)) / denominator;
                if (array[middle] < pivot)
                    left = middle + 1;
                else if (array[middle] > pivot)
                    right = middle - 1;
                else {
                    left = middle;
                    break;
                }
            }
        }

        for (int j = i - 1; j >= left; j--)
            array[j + 1] = array[j];

        array[left] = pivot;

        for (int i = 0; i < n; ++i) {
            std::cout << array[i] << " ";
        }
    }
}

long binSearch(int *array, int size, int digit) {
    bool exist = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] == digit) {
            exist = 1;
            break;
        }
    }
    if (exist) {
        int left = -1;
        int right = size;
        while (left < right - 1) {
            int middle = (left + right) / 2;
            if (array[middle] < digit)
                left = middle;
            else
                right = middle;
        }
        return right;
    }
    else {
        return  -1;
    }
}

long long binPow (int digit, int powder, int mod) {
    while (digit % mod >= mod)
        digit %= mod;
    if (powder == 1)
        return powder;
    else if (powder % 2 == 0) {
        return binPow(digit * digit, powder / 2, mod);
    }
    else {
        return binPow(digit * digit, powder / 2, mod) * digit;
    }
}

int main() {
    int n;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    Time timeStart = std::chrono::high_resolution_clock::now();

    interpolationSort(array, n);
    std::cout << "\nArray:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
    }

    Time timeEnd = std::chrono::high_resolution_clock::now();
    Delta duration = std::chrono::duration_cast<Delta>(timeEnd - timeStart);
    std::cout << "Sort Time: " << duration.count() << " ms\n";

    int digit;
    std::cin >> digit;
    int index = binSearch(array, n, digit);
    std::cout << "\nBinPow Result: " << binPow(index, n, digit);
}
