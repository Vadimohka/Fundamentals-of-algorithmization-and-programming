#include "sort.h"

Sort::Sort()
{
    setSceneRect(0, 0, SCENEWIDTH, SCENEHEIGHT);
}

void Sort::drawArr(int index1, int index2)
{
    double width = static_cast<double>(sceneRect().width()) / arr.size();
    double k = static_cast<double>(sceneRect().height()) / 2 / maxNum;
    double x_coord = 0;
    const double y_coord = static_cast<double>(sceneRect().height()) / 2;
    clear();
    QPen pen(Qt::black);
    QBrush brush(Qt::lightGray);
    for (int i = 0; i < arr.size(); i++) {
        if ((index1 >= 0 && index1 == i) || (index2 >= 0 && index2 == i)) {
            brush.setColor(Qt::green);
        }
        if (arr[i] > 0) {
            addRect(x_coord, y_coord - arr[i] * k, width, arr[i] * k, pen, brush);
        } else {
            addRect(x_coord, y_coord, width, qAbs(arr[i]) * k, pen, brush);
        }
        x_coord += width;
        brush.setColor(Qt::lightGray);
    }
    update();
    QCoreApplication::processEvents();
    QThread::msleep(SLEEP_TIME);
}

void Sort::ending()
{
    QPen pen(Qt::black);
    QBrush brush(Qt::green);
    double width = static_cast<double>(sceneRect().width()) / arr.size();
    double k = static_cast<double>(sceneRect().height()) / 2 / maxNum;
    double x_coord = 0;
    const double y_coord = static_cast<double>(sceneRect().height()) / 2;
    for (int i : arr) {
        if (i > 0) {
            addRect(x_coord, y_coord - i * k, width, i * k, pen, brush);
        } else {
            addRect(x_coord, y_coord, width, qAbs(i) * k, pen, brush);
        }
        x_coord += width;
    }
}

void Sort::setArr(QVector<int> inputArr)
{
    arr.clear();
    clear();
    arr = inputArr;
    if (!arr.empty()) {
        setMaxNum();
        drawArr(-1, -1);
    }
}

void Sort::setMaxNum()
{
    int temp = qAbs(arr[0]);
    for (int i : arr) {
        if (qAbs(i) > temp) {
            temp = qAbs(i);
        }
    }
    maxNum = temp;
}

//HeapSort

void Sort::heapify(int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (i != largest) {
        drawArr(largest, i);
        arr.swapItemsAt(i, largest);
        drawArr(largest, i);
        drawArr(-1, -1);
        heapify(n, largest);
    }
}

QString Sort::heapSort()
{
    QElapsedTimer timer;
    timer.start();
    for (int i = arr.size() / 2 - 1; i >= 0; i--) {
        heapify(arr.size(), i);
    }
    for (int i = arr.size() - 1; i > 0; i--) {
        drawArr(i, 0);
        arr.swapItemsAt(0, i);
        drawArr(i, 0);
        drawArr(-1, -1);
        heapify(i, 0);
    }
    millis = timer.elapsed();
    time = QString::number(millis / THOUSAND) + "." + QString::number(millis % THOUSAND);
    ending();
    return time;
}

//QuickSort

QString Sort::quickSort()
{
    QElapsedTimer timer;
    timer.start();

    quickSort(0, arr.size() - 1);

    millis = timer.elapsed();
    time = QString::number(millis / THOUSAND) + "." + QString::number(millis % THOUSAND);
    return time;
}

void Sort::quickSort(int start, int end)
{
    if (start >= end) {
        return;
    }

    int p = partition(start, end);

    quickSort(start, p - 1);
    quickSort(p + 1, end);
    ending();
}

int Sort::partition(int start, int end)
{
    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }

    int pivotIndex = start + count;

    drawArr(pivotIndex, start);
    arr.swapItemsAt(pivotIndex, start);
    drawArr(pivotIndex, start);
    drawArr(-1, -1);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            drawArr(i, j);
            arr.swapItemsAt(i, j);
            drawArr(i, j);
            drawArr(-1, -1);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

//mergeSort

QString Sort::mergeSort()
{
    QElapsedTimer timer;
    timer.start();

    mergeSort(0, arr.size() - 1);

    millis = timer.elapsed();
    time = QString::number(millis / THOUSAND) + "." + QString::number(millis % THOUSAND);
    return time;
}

void Sort::mergeSort(int start, int end)
{
    if (start >= end) {
        return;
    }

    int mid = start + (end - start) / 2;
    mergeSort(start, mid);
    mergeSort(mid + 1, end);
    merge(start, mid, end);
    ending();
}

void Sort::merge(int left, int mid, int right)
{
    int leftArrSize = mid - left + 1;
    int rightArrSize = right - mid;
    QVector<int> leftArr;
    QVector<int> rightArr;

    for (int i = 0; i < leftArrSize; i++) {
        leftArr.push_back(arr[left + i]);
    }
    for (auto j = 0; j < rightArrSize; j++) {
        rightArr.push_back(arr[mid + 1 + j]);
    }

    int leftArrIndex = 0;
    int rightArrIndex = 0;
    int newArrIndex = left;

    while (leftArrIndex < leftArrSize && rightArrIndex < rightArrSize) {
        if (leftArr[leftArrIndex] <= rightArr[rightArrIndex]) {
            drawArr(newArrIndex, -1);
            arr[newArrIndex] = leftArr[leftArrIndex];
            drawArr(newArrIndex, -1);
            drawArr(-1, -1);
            leftArrIndex++;
        } else {
            drawArr(newArrIndex, -1);
            arr[newArrIndex] = rightArr[rightArrIndex];
            drawArr(newArrIndex, -1);
            drawArr(-1, -1);
            rightArrIndex++;
        }
        newArrIndex++;
    }

    while (leftArrIndex < leftArrSize) {
        drawArr(newArrIndex, -1);
        arr[newArrIndex] = leftArr[leftArrIndex];
        drawArr(newArrIndex, -1);
        drawArr(-1, -1);
        leftArrIndex++;
        newArrIndex++;
    }

    while (rightArrIndex < rightArrSize) {
        drawArr(newArrIndex, -1);
        arr[newArrIndex] = rightArr[rightArrIndex];
        drawArr(newArrIndex, -1);
        drawArr(-1, -1);
        rightArrIndex++;
        newArrIndex++;
    }
}

//interpolationSort

QString Sort::interpolationSort()
{
    QElapsedTimer timer;
    timer.start();

    int minVal = arr[0];
    int maxVal = arr[0];
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    interpolationSort(0, arr.size() - 1, minVal, maxVal);

    millis = timer.elapsed();
    time = QString::number(millis / THOUSAND) + "." + QString::number(millis % THOUSAND);
    return time;
}

void Sort::interpolationSort(int start, int end, int minVal, int maxVal)
{
    if (start < end) {
        int interpolation = static_cast<int>(
            (static_cast<double>(arr[start] - minVal) / (maxVal - minVal)) * (end - start));
        int temp = arr[start + interpolation];

        int left = start, right = end;
        while (left <= right) {
            while (arr[left] < temp) {
                left++;
            }
            while (arr[right] > temp) {
                right--;
            }
            if (left <= right) {
                drawArr(left, right);
                arr.swapItemsAt(left, right);
                drawArr(left, right);
                drawArr(-1, -1);
                left++;
                right--;
            }
        }

        interpolationSort(start, right, minVal, temp);
        interpolationSort(left, end, temp, maxVal);
    }
}

//binSearch

int Sort::binSearch(int key)
{
    int l = 0;
    int r = arr.size() - 1;
    int mid = (l + r) / 2;
    bool flag = false;
    while (l <= r && !flag) {
        mid = (l + r) / 2;
        drawArr(mid, -1);
        if (arr[mid] == key) {
            flag = true;
        } else if (arr[mid] > key) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (!flag) {
        drawArr(-1, -1);
        return -1;
    } else {
        return mid;
    }
}

int Sort::binPow(int digit, int power, int mod)
{
    if (power == 0) {
        return 1;
    }
    uint64_t i = binPow(digit % mod, power / 2, mod) % mod;
    if (power % 2 == 0) {
        return (i * i) % mod;
    } else {
        return ((digit % mod) * ((i * i) % mod)) % mod;
    }
}

QVector<int> Sort::getArr()
{
    return arr;
}
