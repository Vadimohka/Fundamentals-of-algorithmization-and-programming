#include <QVector>
#include <iostream>

// Функция для обмена элементов
void swap(QVector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Функция интерполицеонной сортировки
void interpolationSort(QVector<int>& arr) {
    const int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Находим позицию для вставки элемента key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main() {
    QVector<int> numbers = {42, 17, 5, 23, 9, 31, 123, 2, 2, 2, 323, 23, 32};

    std::cout << "Исходный вектор: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    interpolationSort(numbers);

    std::cout << "Отсортированный вектор: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
