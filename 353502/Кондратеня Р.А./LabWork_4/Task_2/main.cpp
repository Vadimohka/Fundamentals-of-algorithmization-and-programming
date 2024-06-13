#include <iostream>
#include <ctime>

void printArr(int* arr, int n)
{
    for(int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int interpolate(int arr[], int low, int high, int target) {
    // Проверка граничных условий
    if (low <= high && target >= arr[low] && target <= arr[high]) {
        // Вычисление оценки позиции элемента
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        // Если элемент найден
        if (arr[pos] == target)
            return pos;

        // Если искомый элемент меньше текущего, рекурсивный вызов для левой части
        if (arr[pos] > target)
            return interpolate(arr, low, pos - 1, target);

        // Если искомый элемент больше текущего, рекурсивный вызов для правой части
        if (arr[pos] < target)
            return interpolate(arr, pos + 1, high, target);
    }

    // Элемент не найден
    return -1;
}

// Функция интерполяционной сортировки
void interpolationSort(int arr[], int size) {
    int n = size;

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Нахождение позиции для вставки текущего элемента
        int pos = interpolate(arr, 0, j, key);

        // Сдвиг элементов, чтобы освободить место для вставки
        while (j >= 0 && j >= pos) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Вставка элемента в правильную позицию
        arr[j + 1] = key;
        printArr(arr, size);
    }
}

long long binaryPower(int base, int exponent) {
    if (exponent == 0)
    {
        return 1;
    }
    else if (exponent == 1)
    {
        return base;
    }
    else
    {
        long long halfPower = binaryPower(base, exponent / 2);
        long long result = halfPower * halfPower;
        if (exponent % 2 != 0)
        {
            result *= base;
        }

        return result;
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
    std::cout << "Enter size of array: ";
    std::cin >> n;
    int* arr = new int[n];
    std::cout<<"Your array: \n";
    for(int i = 0; i < n; i++)
        arr[i] = 1 + rand() % 100;
    interpolationSort(arr, n);
    int number;
    std::cout << "Enter number you want to find: ";
    std::cin >> number;
    int index = binarySearch(arr, number, n);
    std::cout << "Index of number is " << index << "\n";
    std::cout << "Answer: " << binaryPower(index, n % number);
    return 0;
}
