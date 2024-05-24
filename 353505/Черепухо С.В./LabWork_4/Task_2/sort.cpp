#include "sort.h"
#include "qswap.h"

int VSort::runningFuctionsCntr = 0;
bool VSort::isOverflowed = false;

void VSort::mergeArrays(int *start, int *mid, int *end, int arrSize)
{
    int leftI = 0, rightI = 0;
    int *tempArr = new int[arrSize] ();
    while (leftI + rightI < arrSize) {
        emitCompare(start + leftI, mid + rightI);
        if (start[leftI] < mid[rightI]) {
            tempArr[leftI + rightI] = start[leftI];
            ++leftI;
        }
        else {
            tempArr[leftI + rightI] = mid[rightI];
            ++rightI;
        }

        bool leftIsCompleted = start + leftI >= mid,
            rightIsCompleted = mid + rightI >= end;

        if (!leftIsCompleted && !rightIsCompleted) { continue; }

        while (leftIsCompleted && mid + rightI < end) {
            tempArr[leftI + rightI] = mid[rightI];
            ++rightI;
        }
        while (rightIsCompleted && start + leftI < mid) {
            tempArr[leftI + rightI] = start[leftI];
            ++leftI;
        }
        break;
    }
    for (int i = 0; i < arrSize; ++i) {
        start[i] = tempArr[i];
        emitChanging(start + i, tempArr[i]);
    }
    delete[] tempArr;
}

void VSort::heap(int *array, int size) {
    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify(array, size, i);
    }

    for (int i = size - 1; i > 0; --i) {
        qSwap(array[0], array[i]);
        emitSwapping(array, array + i);
        heapify(array, i, 0);
    }
}

void VSort::merge(int *start, int *end)
{
    int arrSize = end - start;
    if (arrSize == 2) {
        emitCompare(start, start + 1);
        if (*start > *(start + 1)) {
            qSwap(*start, *(start + 1));
            emitSwapping(start, start + 1);
        }
        return;
    }
    if (arrSize <= 1) { return; }

    int* mid = start + arrSize / 2;
    merge(start, mid);
    merge(mid, end);

    mergeArrays(start, mid, end, arrSize);
}

void VSort::quick(int *start, int *end) {
    if (end - start <= 1) { return; }

    auto pivotI = start + (end - start) / 2;
    int pivot = *pivotI;
    qSwap(*start, *pivotI);

    int *leftI = start + 1, *rightI = end - 1;
    while (rightI >= leftI) {
        while (*rightI >= pivot && rightI > start) {
            emitCompare(rightI, rightI);
            --rightI;
        }
        emitCompare(rightI, rightI); // nessesary
        while (*leftI <= pivot && leftI < end) {
            emitCompare(leftI, leftI);
            ++leftI;
        }
        emitCompare(leftI, leftI); // nessesary
        if (rightI >= leftI) {
            emitSwapping(rightI, leftI);
            qSwap(*rightI, *leftI);
        }
    }
    qSwap(*start, *rightI);
    emitSwapping(start, rightI);

    quick(start, rightI);
    quick(rightI + 1, end);
}

void VSort::quick3Way(int *start, int *end) {
    if (end - start <= 1) { return; }

    int *lower = start, *greater = end - 1;
    int pivot = *start;
    int *i = start + 1;

    while (i <= greater) {
        emitCompare(i, i);
        if (*i < pivot) {
            emitSwapping(lower, i);
            qSwap(*lower++, *i++);
        }
        else if (*i > pivot) {
            emitSwapping(greater, i);
            qSwap(*i, *greater--);
        }
        else { ++i; }
    }

    quick3Way(start, lower);
    quick3Way(greater + 1, end);
}

bool VSort::quicks(int *start, int *end) {
    if (end - start <= 1 && !isOverflowed) { return true; }

    if (isOverflowed) {
        return false;
    }
    ++runningFuctionsCntr;
    if (runningFuctionsCntr >= MAX_FUNC_RUNNING) {
        isOverflowed = true;
    };

    auto pivotI = start + (end - start) / 2;
    int pivot = *pivotI;
    qSwap(*start, *pivotI);
    emitSwapping(start, pivotI);

    int *leftI = start + 1, *rightI = end - 1;
    while (rightI >= leftI) {
        while (*rightI >= pivot && rightI > start) {
            emitCompare(rightI, rightI);
            --rightI;
        }
        emitCompare(rightI, rightI); // nessesary
        while (*leftI <= pivot && leftI < end) {
            emitCompare(leftI, leftI);
            ++leftI;
        }
        emitCompare(leftI, leftI); // nessesary
        if (rightI >= leftI) {
            emitSwapping(rightI, leftI);
            qSwap(*rightI, *leftI);
        }
    }
    qSwap(*start, *rightI);
    emitSwapping(start, rightI);

    bool stackCheckFailed = !quicks(start, rightI) || !quicks(rightI + 1, end);
    --runningFuctionsCntr;
    if (runningFuctionsCntr == 0) { isOverflowed = false; }
    if (stackCheckFailed) {
        return false;
    }
    return true;
}

void VSort::interpolation(int *array, int size) {
    int* end = array + size;
    QVector<int> sortPartSizes;
    sortPartSizes.push_back(size);
    while (!sortPartSizes.empty()) { sortPart(end, sortPartSizes); }
}

void VSort::heapify(int *array, int arrSize, int pos) {
    int largest = pos;
    int leftBranch = pos * 2 + 1, rightBranch = pos * 2 + 2;
    if (leftBranch > 0 && leftBranch < arrSize) {
        emitCompare(array + leftBranch, array + largest);
    }
    if (leftBranch > 0 && leftBranch < arrSize && array[leftBranch] > array[largest]) { largest = leftBranch; }
    if (leftBranch > 0 && leftBranch < arrSize) {
        emitCompare(array + rightBranch, array + largest);
    }
    if (rightBranch > 0 && rightBranch < arrSize && array[rightBranch] > array[largest]) { largest = rightBranch; }

    if (largest != pos) {
        qSwap(array[largest], array[pos]);
        emitSwapping(array + largest, array + pos);
        heapify(array, arrSize, largest);
    }
}

void VSort::sortPart(int* &end, QVector<int> &partSizes)
{
    int size = partSizes.back();
    partSizes.pop_back();
    int* start = end - size;
    int maxValue = *start;
    int minValue = *start;
    for (int* i = start; i < end; ++i) {
        emitCompare(i, i);
        if (*i > maxValue) { maxValue = *i; }
        else if (*i < minValue) { minValue = *i; }
    }

    if (minValue == maxValue) { end -= size; }
    else {
        QVector<QVector<int>> tempValues (size);
        int interpolationPos = 0;
        for (int* i = start; i < end; ++i) {
            emitCompare(i, i);
            interpolationPos = (*i - minValue) * (size - 1) / (maxValue - minValue); /////////////
            tempValues[interpolationPos].push_back(*i);
        }

        for (const auto &curVect : tempValues) {
            if (!curVect.empty()) {
                for (const auto &curValue : curVect) {
                    *(start) = curValue;
                    emitChanging(start, curValue);
                    ++start;
                }
                partSizes.push_back(curVect.size());
            }
        }
    }
}

void VSort::skip(int ms) {
    QEventLoop loop;
    QTimer::singleShot(ms, &loop, &QEventLoop::quit);
    loop.exec();
}

void VSort::updateDelays(int size)
{
    _compDelay = qMax(MIN_COMP_DELAY, MAX_COMP_DELAY / size);
    _changeDelay = qMax(MIN_CHANGE_DELAY, MAX_CHANGE_DELAY / size);
    _swapDelay = qMax(MIN_SWAP_DELAY, MAX_SWAP_DELAY / size);
}

void VSort::emitCompare(int *a, int *b) {
    emit startComparison(a, b);
    skip(_compDelay);
    emit finishComparison(a, b);
    skip(1);
}

void VSort::emitChanging(int *i, int value) {
    emit changing(i, value);
    skip(_changeDelay);
}

void VSort::emitSwapping(int *a, int *b) {
    emit swapping(a, b);
    skip(_swapDelay);
}

void VSort::Merge(int *start, int *end) {
    updateDelays(end - start);
    merge(start, end);
    emit finish();
}

void VSort::Merge(int *array, int size) {
    updateDelays(size);
    merge(array, array + size);
    emit finish();
}

void VSort::Heap(int *array, int size) {
    heap(array, size);
    emit finish();
}

void VSort::Heap(int *start, int *end) {
    updateDelays(end - start);
    heap(start, start - end);
    emit finish();
}

void VSort::Quick(int *start, int *end) {
    updateDelays(end - start);
    quick(start, end);
    emit finish();
}

void VSort::Quick3Way(int* start, int* end) {
    updateDelays(end - start);
    quick3Way(start, end);
    emit finish();
}

void VSort::Quick(int *array, int size) {
    updateDelays(size);
    quick(array, array + size);
    emit finish();
}

void VSort::Quick3Way(int *array, int size) {
    updateDelays(size);
    quick3Way(array, array + size);
    emit finish();
}

void VSort::Interpolation(int *start, int *end) {
    updateDelays(end - start);
    interpolation(start, end - start);
    emit finish();
}

void VSort::Interpolation(int *array, int size) {
    updateDelays(size);
    interpolation(array, size);
    emit finish();
}

bool VSort::Quicks(int *start, int *end) {
    updateDelays(end - start);
    bool temp = quicks(start, end);
    emit finish();
    return temp;
}

bool VSort::Quicks(int *array, int size) {
    updateDelays(size);
    bool temp = quicks(array, array + size);
    emit finish();
    return temp;
}

int VSort::maxFunctionsRunning()
{
    return MAX_FUNC_RUNNING;
}
