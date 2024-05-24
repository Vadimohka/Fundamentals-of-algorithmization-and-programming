
#include "sort.h"
#include "QTimer"
#include "QEventLoop"
#include <QCoreApplication>

sort::sort()
{

}


void sort::quick_sort(int* a, int left, int right, int max, QVector<Rectangle*>& rect, int w0, int h0, QMainWindow* mainWindowPtr, int n){
    Rectangle::foo(a,n,max,rect, w0, h0, mainWindowPtr);
    int l = left;
    int r = right;
    int pos = a[(l+r)/2];
    while (l < r){
        while (a[l] < pos){
            l++;
        }
        while (a[r] > pos){
            r--;
        }
        if (l <= r){
            if (l != r){
            int buf = a[l];
            a[l] = a[r];
            a[r] = buf;
            }
            r--;
            l++;
            Rectangle::foo(a,n,max,rect, w0, h0, mainWindowPtr);
            QEventLoop loop;
            QTimer::singleShot(100, &loop, &QEventLoop::quit); // Ожидание 0.5 секунды
            loop.exec();
        }
    }

    if (r > left) {

        quick_sort(a, left, r, max, rect, w0, h0, mainWindowPtr, n);

    }
    if (l < right){

        quick_sort(a, l, right, max, rect, w0, h0, mainWindowPtr, n);

    }
}


  // Процедура для преобразования в двоичную кучу поддерева с корневым узлом i, что является
// индексом в arr[]. n - размер кучи

void sort::heapify(int* arr, int n, int i, int max, QVector<Rectangle*>& rect, int w0, int h0, QMainWindow* mainWindowPtr, int num)
{
    Rectangle::foo(arr,num,max,rect, w0, h0, mainWindowPtr);
    int largest = i;
    // Инициализируем наибольший элемент как корень
    int l = 2*i + 1; // левый = 2*i + 1
    int r = 2*i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        int buf = arr[largest];
        arr[largest] = arr[i];
        arr[i] = buf;
        Rectangle::foo(arr,num,max,rect, w0, h0, mainWindowPtr);
        QEventLoop loop;
        QTimer::singleShot(100, &loop, &QEventLoop::quit); // Ожидание 0.5 секунды
        loop.exec();
        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest, max, rect, w0, h0, mainWindowPtr, num);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
void sort::heapSort(int* arr, int n, int max, QVector<Rectangle*>& rect, int w0, int h0, QMainWindow* mainWindowPtr, int num)
{
    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, max, rect, w0, h0, mainWindowPtr, num);

    // Один за другим извлекаем элементы из кучи
    for (int i=n-1; i>=0; i--)
    {
        int buf = arr[0];
        arr[0] = arr[i];
        arr[i] = buf;
        Rectangle::foo(arr,n,max,rect, w0, h0, mainWindowPtr);
        QEventLoop loop;
        QTimer::singleShot(100, &loop, &QEventLoop::quit); // Ожидание 0.5 секунды
        loop.exec();

        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0, max, rect, w0, h0, mainWindowPtr, num);
    }
}


void sort::merge(int* array, int const left, int const mid, int const right, int max, QVector<Rectangle*>& rect, int w0, int h0, QMainWindow* mainWindowPtr, int num)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Создание временных массивов
    auto *leftArray = new int[subArrayOne],
        *rightArray = new int[subArrayTwo];

    // Копирование данных во временные массивы leftArray[] и rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    // Инициализация индексов первого и второго подмассивов
    auto indexOfSubArrayOne = 0,
        indexOfSubArrayTwo = 0;

    // Инициализация индекса объединенного массива
    int indexOfMergedArray = left;

    // Слияние временных массивов обратно в array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            Rectangle::foo(array, num, max, rect, w0, h0, mainWindowPtr);
            QCoreApplication::processEvents();
            QEventLoop loop;
            QTimer::singleShot(100, &loop, &QEventLoop::quit);
            loop.exec();
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            Rectangle::foo(array, num, max, rect, w0, h0, mainWindowPtr);
            QCoreApplication::processEvents();
            QEventLoop loop;
            QTimer::singleShot(100, &loop, &QEventLoop::quit);
            loop.exec();
        }
        indexOfMergedArray++;
    }

    // Копирование оставшихся элементов leftArray[], если есть
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
        Rectangle::foo(array, num, max, rect, w0, h0, mainWindowPtr);
        QCoreApplication::processEvents();
        QEventLoop loop;
        QTimer::singleShot(100, &loop, &QEventLoop::quit);
        loop.exec();
    }

    // Копирование оставшихся элементов rightArray[], если есть
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
        Rectangle::foo(array, num, max, rect, w0, h0, mainWindowPtr);
        QCoreApplication::processEvents();
        QEventLoop loop;
        QTimer::singleShot(100, &loop, &QEventLoop::quit);
        loop.exec();
    }

    Rectangle::foo(array, num, max, rect, w0, h0, mainWindowPtr);
    QCoreApplication::processEvents();
    QEventLoop loop;
    QTimer::singleShot(100, &loop, &QEventLoop::quit);
    loop.exec();
}


// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted
void sort::mergeSort(int* array, int const begin, int const end, int max, QVector<Rectangle*>& rect, int w0, int h0, QMainWindow* mainWindowPtr, int num)
{
    // Returns recursively
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid, max, rect, w0, h0, mainWindowPtr, num);
    mergeSort(array, mid + 1, end, max, rect, w0, h0, mainWindowPtr, num);
    merge(array, begin, mid, end, max, rect, w0, h0, mainWindowPtr, num);
    Rectangle::foo(array, num, max, rect, w0, h0, mainWindowPtr);
    QCoreApplication::processEvents();
       QEventLoop loop;
    QTimer::singleShot(100, &loop, &QEventLoop::quit);
    loop.exec();
}

int sort::binsearch(int* arr, int l, int r, int digit){

    if (r-l == 0){
        if (arr[l] == digit){
            return l;
        }
        else {
            return -1;
        }
    }

    int mid = arr[(r + l)/2];

    if (mid == digit) {
        return (r+l)/2;
    }

    if (mid > digit){
        return binsearch(arr, l, (r+l)/2, digit);
    }

    if (mid < digit){
        return binsearch(arr,(r+l)/2+1, r, digit);
    }

}
