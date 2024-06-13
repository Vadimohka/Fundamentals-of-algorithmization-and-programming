#include "Array.h"
#include <QPainter>
#include <QVector>
#include <QRandomGenerator>
#include <QTimer>
#include <QThread>
#include <QCoreApplication>

RectArray::RectArray()
{
    toSort = generateRandomArray(number);
    color = getColor(number);
}

RectArray::~RectArray()
{
}

QRectF RectArray::boundingRect() const
{
    return QRectF(0, 0, 10, 10);
}

void RectArray::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::gray);

    painter->setBrush(Qt::gray);
    painter->setPen(Qt::black);
    for (int i = 0; i < number; i++)
    {
        if (color[i] == 0)
            painter->setBrush(Qt::gray);
        if (color[i] == 1)
            painter->setBrush(Qt::red);
        if (color[i] == 2)
            painter->setBrush(Qt::green);
        if (color[i] == 3)
            painter->setBrush(Qt::cyan);
        // qDebug() << i << "-" << toSort[i];
        painter->drawRect(i * width / number, 0, width / number, -(1 + toSort[i]) * (height / number));
    }
    // qDebug() << "________";
}

QVector<int> RectArray::generateRandomArray(int n)
{
    QVector<int> result;
    result.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        result.append(i);
    }

    for (int i = n - 1; i > 0; --i)
    {
        int j = QRandomGenerator::global()->bounded(i + 1);
        result.swapItemsAt(i, j);
    }

    return result;
}

QVector<int> RectArray::getColor(int n)
{
    QVector<int> result;
    result.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        result.append(0);
    }

    return result;
}

void RectArray::updateNumber()
{
    if (allowUpdateNumber)
    {
        color = getColor(number);
        toSort = generateRandomArray(number);
        update();
        allowSort = true;
    }
}

bool RectArray::isSorted()
{
    for (size_t i = 1; i < toSort.size(); ++i)
    {
        if (toSort[i] < toSort[i - 1])
        {
            return false;
        }
    }
    return true;
}

template <typename T>
void RectArray::swap(T &a, T &b, int one, int two)
{
    color[one] = 1;
    color[two] = 1;
    update();
    QCoreApplication::processEvents();
    QThread::msleep(00);

    T temp = a;
    a = b;
    b = temp;

    update();
    QCoreApplication::processEvents();
    QThread::msleep(00);

    color[one] = 0;
    color[two] = 0;
    update();
    QCoreApplication::processEvents();
    QThread::msleep(00);
}

void RectArray::heapSorting()
{
    allowUpdateNumber = false;
    if (allowSort)
    {
        heapSort(toSort);
        update();

        for (int i = 0; i < number; i++)
        {
            color[i] = 2;
            update();
            QCoreApplication::processEvents();
            QThread::msleep(00);
        }
        for (int i = 0; i < number; i++)
        {
            color[i] = 0;
        }
        update();
        QCoreApplication::processEvents();
        QThread::msleep(00);

        allowSort = false;
    }
    allowUpdateNumber = true;
}

template <typename T>
void RectArray::heapify(QVector<T> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest], i, largest);

        heapify(arr, n, largest);
    }
}

template <typename T>
void RectArray::heapSort(QVector<T> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i], 0, i);
        heapify(arr, i, 0);
    }
}

void RectArray::quickSorting()
{
    allowUpdateNumber = false;
    if (allowSort)
    {
        quickSort(toSort, 0, number - 1);
        update();

        for (int i = 0; i < number; i++)
        {
            color[i] = 2;
            update();
            QCoreApplication::processEvents();
            QThread::msleep(00);
        }
        for (int i = 0; i < number; i++)
        {
            color[i] = 0;
        }
        update();
        QCoreApplication::processEvents();
        QThread::msleep(00);
        allowSort = false;
    }
    allowUpdateNumber = true;
}

template <typename T>
int RectArray::partition(QVector<T> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j], i, j);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

template <typename T>
void RectArray::quickSort(QVector<T> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void RectArray::mergeSorting()
{
    allowUpdateNumber = false;
    if (allowSort)
    {
        mergeSort(toSort, 0, number - 1);
        update();

        for (int i = 0; i < number; i++)
        {
            color[i] = 2;
            update();
            QCoreApplication::processEvents();
            QThread::msleep(00);
        }
        for (int i = 0; i < number; i++)
        {
            color[i] = 0;
        }
        update();
        QCoreApplication::processEvents();
        QThread::msleep(00);
        allowSort = false;
    }
    allowUpdateNumber = true;
}

template <typename T>
void RectArray::merge(QVector<T> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    QVector<T> leftArr(n1);
    QVector<T> rightArr(n2);

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            color[k] = 1;
            // color[i] = 1;
            update();
            QCoreApplication::processEvents();
            QThread::msleep(00);

            arr[k] = leftArr[i];

            update();
            QCoreApplication::processEvents();
            QThread::msleep(00);

            color[k] = 0;
            // color[i] = 0;
            update();
            QCoreApplication::processEvents();
            QThread::msleep(00);

            i++;
        }
        else
        {
            color[k] = 1;
            // color[j] = 1;
            update();
            QCoreApplication::processEvents();
            QThread::msleep(00);

            arr[k] = rightArr[j];

            update();
            QCoreApplication::processEvents();
            QThread::msleep(00);

            color[k] = 0;
            // color[j] = 0;
            update();
            QCoreApplication::processEvents();
            QThread::msleep(00);

            j++;
        }
        k++;
    }
    update();
    QCoreApplication::processEvents();
    QThread::msleep(00);

    while (i < n1)
    {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

template <typename T>
void RectArray::mergeSort(QVector<T> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void RectArray::interpolationSorting()
{
    allowUpdateNumber = false;
    if (allowSort)
    {
        int minVal = *std::min_element(toSort.begin(), toSort.end());
        int maxVal = *std::max_element(toSort.begin(), toSort.end());
        interpolationSort(toSort, 0, number - 1, minVal, maxVal);
        update();

        for (int i = 0; i < number; i++)
        {
            color[i] = 2;
            update();
            QCoreApplication::processEvents();
            QThread::msleep(00);
        }
        for (int i = 0; i < number; i++)
        {
            color[i] = 0;
        }
        update();
        QCoreApplication::processEvents();
        QThread::msleep(00);
        allowSort = false;
    }
    allowUpdateNumber = true;
}

template <typename T>
void RectArray::interpolationSort(QVector<T>& arr, int low, int high, int minVal, int maxVal) {
    if (low < high) {
        int interpolation = static_cast<int>((static_cast<double>(arr[low] - minVal) / (maxVal - minVal)) * (high - low));
        int pivot = arr[low + interpolation];

        int left = low, right = high;
        while (left <= right) {
            while (arr[left] < pivot) {
                left++;
            }
            while (arr[right] > pivot) {
                right--;
            }
            if (left <= right) {
                swap(arr[left], arr[right], left, right);
                left++;
                right--;
            }
        }

        interpolationSort(arr, low, right, minVal, pivot);
        interpolationSort(arr, left, high, pivot, maxVal);
    }
}

int RectArray::binarySearch(int target)
{
    for (int i = 0; i < number; i++)
    {
        color[i] = 0;
    }
    int left = 0;
    int right = toSort.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        color[mid] = 3;
        update();
        QCoreApplication::processEvents();
        QThread::msleep(45);

        if (toSort[mid] == target)
        {
            return mid;
        }
        else if (toSort[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }

        update();
        QCoreApplication::processEvents();
        QThread::msleep(45);

        color[mid] = 0;
        update();
        QCoreApplication::processEvents();
        QThread::msleep(45);
    }

    return -1;

}
