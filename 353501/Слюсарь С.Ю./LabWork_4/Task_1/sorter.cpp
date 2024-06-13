#include "sorter.h"

Sorter::Sorter(int *arr, int n)
{
    _arr = arr;
    _n = n;
}

void Sorter::heapify(int root, int n)
{
    int largest;
    bool done = 0;
    while((root * 2 <= n) && !done)
    {
        if (root * 2 == n)
        {
            largest = root * 2;
        }
        else if (_arr[root * 2] > _arr[root * 2 + 1])
        {
            largest = root * 2;
        }
        else
        {
            largest = root * 2 + 1;
        }
        if (_arr[root] < _arr[largest])
        {
            int a = _arr[root];
            _arr[root] = _arr[largest];
            _arr[largest] = a;
            root = largest;
            QEventLoop loop;
            QTimer::singleShot(0, &loop, SLOT(quit()));
            loop.exec();
            update();
        }
        else
        {
            done = 1;
        }
    }
}

void Sorter::heapSort(int n)
{
    for (int i = (n / 2); i >= 0; --i)
        heapify(i, n - 1);
    for (int i = n - 1; i >= 1; --i)
    {
        int a = _arr[0];
        _arr[0] = _arr[i];
        _arr[i] = a;
        QEventLoop loop;
        QTimer::singleShot(0, &loop, SLOT(quit()));
        loop.exec();
        update();
        heapify(0, i - 1);
    }
}

int Sorter::partition(int first, int last)
{

    int p = _arr[first];
    int count = 0;
    for (int i = first + 1; i <= last; i++)
    {
        if (_arr[i] <= p)
        {
            count++;
        }
    }
    int pIndex = first + count;
    qSwap(_arr[pIndex], _arr[first]);
    QEventLoop loop;
    QTimer::singleShot(10, &loop, SLOT(quit()));
    loop.exec();
    update();
    int i = first, j = last;

    while (i < pIndex && j > pIndex)
    {
        while (_arr[i] <= p) {
            i++;
        }
        while (_arr[j] > p) {
            j--;
        }
        if (i < pIndex && j > pIndex) {
            qSwap(_arr[i++], _arr[j--]);
            QEventLoop loop;
            QTimer::singleShot(10, &loop, SLOT(quit()));
            loop.exec();
            update();
        }
    }

    return pIndex;
}

void Sorter::quickSort(int first, int last)
{
    if (first >= last)
    {
        return;
    }
    int p = partition(first, last);
    quickSort(first, p - 1);
    quickSort(p + 1, last);
}

void Sorter::merge(int left, int mid, int right)
{
    int array1 = mid - left + 1;
    int array2 = right - mid;

    int *leftArray = new int[array1];
    int *rightArray = new int[array2];

    for (int i = 0; i < array1; ++i)
    {
        leftArray[i] = _arr[left + i];
        QEventLoop loop;
        QTimer::singleShot(0, &loop, SLOT(quit()));
        loop.exec();
        update();
    }
    for (auto j = 0; j < array2; ++j)
    {
        rightArray[j] = _arr[mid + 1 + j];
        QEventLoop loop;
        QTimer::singleShot(0, &loop, SLOT(quit()));
        loop.exec();
        update();
    }

    int indexOfArray1 = 0;
    int indexOfArray2 = 0;
    int indexOfMergedArray = left;

    while (indexOfArray1 < array1 && indexOfArray2 < array2)
    {
        if (leftArray[indexOfArray1] <= rightArray[indexOfArray2])
        {
            _arr[indexOfMergedArray] = leftArray[indexOfArray1];
            QEventLoop loop;
            QTimer::singleShot(0, &loop, SLOT(quit()));
            loop.exec();
            update();
            indexOfArray1++;
        }
        else
        {
            _arr[indexOfMergedArray] = rightArray[indexOfArray2];
            QEventLoop loop;
            QTimer::singleShot(0, &loop, SLOT(quit()));
            loop.exec();
            update();
            indexOfArray2++;
        }
        indexOfMergedArray++;
    }
    while (indexOfArray1 < array1)
    {
        _arr[indexOfMergedArray] = leftArray[indexOfArray1];
        QEventLoop loop;
        QTimer::singleShot(0, &loop, SLOT(quit()));
        loop.exec();
        update();
        indexOfArray1++;
        indexOfMergedArray++;
    }

    while (indexOfArray2 < array2)
    {
        _arr[indexOfMergedArray] = rightArray[indexOfArray2];
        QEventLoop loop;
        QTimer::singleShot(0, &loop, SLOT(quit()));
        loop.exec();
        update();
        indexOfArray2++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    leftArray = nullptr;
    delete[] rightArray;
    rightArray = nullptr;
}

void Sorter::mergeSort(int first, int last)
{
    if (first >= last)
    {
        return;
    }
    QEventLoop loop;
    QTimer::singleShot(0, &loop, SLOT(quit()));
    loop.exec();
    update();
    int mid = first + (last - first) / 2;
    mergeSort(first, mid);
    mergeSort(mid + 1, last);
    merge(first, mid, last);
}

int Sorter::binSearch(int n, int find)
{
    int l = 0;
    int r = n - 1;
    while(l <= r)
    {
        int m = l + (r - l) / 2;
        if (find == _arr[m])
        {
            return m;
        }
        else if (find < _arr[m])
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return -1;
}

void Sorter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(Qt::darkGreen);
    painter->setPen(Qt::black);
    for (int i = 0; i < _n; ++i)
    {
        painter->drawRect(-300 + 10 * i, 250 - _arr[i], 10, _arr[i]);
    }
}

QRectF Sorter::boundingRect() const
{
    return QRectF(-300, -250, 600, 500);
}
