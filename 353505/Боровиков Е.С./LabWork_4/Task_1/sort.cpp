#include "sort.h"
#include "qswap.h"

int Sort::runningFuctionsCntr = 0;
bool Sort::isOverflowed = false;

void Sort::mergeArrays(int *start, int *mid, int *end, int arrSize)
{
    int leftI = 0, rightI = 0;
    int *tempArr = new int[arrSize] ();
    while (leftI + rightI < arrSize) {
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
    }
    delete[] tempArr;
}

void Sort::Merge(int *start, int *end) {
    int arrSize = end - start;
    if (arrSize == 2) {
        if (*start > *(start + 1)) {
            qSwap(*start, *(start + 1));
        }
        return;
    }
    if (arrSize <= 1) { return; }

    int* mid = start + arrSize / 2;
    Merge(start, mid);
    Merge(mid, end);

    mergeArrays(start, mid, end, arrSize);
}

void Sort::Merge(int *array, int size) {
    Merge(array, array + size);
}

void Sort::heapify(int *array, int arrSize, int pos) {
    int largest = pos;
    int leftBranch = pos * 2 + 1, rightBranch = pos * 2 + 2;
    if (leftBranch > 0 && leftBranch < arrSize && array[leftBranch] > array[largest]) { largest = leftBranch; }
    if (rightBranch > 0 && rightBranch < arrSize && array[rightBranch] > array[largest]) { largest = rightBranch; }

    if (largest != pos) {
        qSwap(array[largest], array[pos]);
        heapify(array, arrSize, largest);
    }
}

void Sort::sortPart(int *&end, QVector<int> &partSizes) {
    ull size = partSizes.back();
    partSizes.pop_back();
    int* start = end - size;
    ull maxValue = *start;
    ull minValue = *start;
    for (int* i = start; i < end; ++i) {
        if (*i > maxValue) { maxValue = *i; }
        else if (*i < minValue) { minValue = *i; }
    }

    if (minValue == maxValue) { end -= size; }
    else {
        QVector<QVector<int>> tempValues (size);
        ull interpolationPos = 0;
        for (int* i = start; i < end; ++i) {
            interpolationPos = (*i - minValue) * (size - 1) / (maxValue - minValue);
            tempValues[interpolationPos].push_back(*i);
        }

        for (const auto &curVect : tempValues) {
            if (!curVect.empty()) {
                for (const auto &curValue : curVect) {
                    *(start) = curValue;
                    ++start;
                }
                partSizes.push_back(curVect.size());
            }
        }
    }

}

void Sort::Heap(int *array, int size) {
    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify(array, size, i);
    }

    for (int i = size - 1; i > 0; --i) {
        qSwap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

void Sort::Heap(int *start, int *end) {
    Heap(start, start - end);
}

void Sort::Quick(int *start, int *end) {
    if (end - start <= 1) { return; }

    auto pivotI = start + (end - start) / 2;
    int pivot = *pivotI;
    qSwap(*start, *pivotI);

    int *leftI = start + 1, *rightI = end - 1;
    while (rightI >= leftI) {
        while (*rightI >= pivot && rightI > start) { --rightI; }
        while (*leftI <= pivot && leftI < end) { ++leftI; }
        if (rightI >= leftI) {
            qSwap(*rightI, *leftI);
        }
    }
    qSwap(*start, *rightI);

    Quick(start, rightI);
    Quick(rightI + 1, end);
}

void Sort::Quick3Way(int* start, int* end) {
    if (end - start <= 1) { return; }

    int *lower = start, *greater = end - 1;
    int pivot = *start;
    int *i = start + 1;

    while (i <= greater) {
        if (*i < pivot) { qSwap(*lower++, *i++); }
        else if (*i > pivot) { qSwap(*i, *greater--); }
        else { ++i; }
    }

    Quick3Way(start, lower);
    Quick3Way(greater + 1, end);
}

void Sort::Quick(int *array, int size) {
    Quick(array, array + size);
}

void Sort::Quick3Way(int *array, int size) {
    Quick3Way(array, array + size);

}

void Sort::Interpolation(int *start, int *end) {
    Interpolation(start, end - start);
}

void Sort::Interpolation(int *array, int size) {
    int* end = array + size;
    QVector<int> sortPartSizes;
    sortPartSizes.push_back(size);
    while (!sortPartSizes.empty()) { sortPart(end, sortPartSizes); }
}

bool Sort::Quicks(int *start, int *end) {
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

    int *leftI = start + 1, *rightI = end - 1;
    while (rightI >= leftI) {
        while (*rightI >= pivot && rightI > start) { --rightI; }
        while (*leftI <= pivot && leftI < end) { ++leftI; }
        if (rightI >= leftI) {
            qSwap(*rightI, *leftI);
        }
    }
    qSwap(*start, *rightI);

    Quicks(start, rightI);
    Quicks(rightI + 1, end);

    --runningFuctionsCntr;

    if (runningFuctionsCntr == 0) { isOverflowed = false; }
    return true;
}

bool Sort::Quicks(int *array, int size) {
    return Quicks(array, array + size);
}

int Sort::maxFunctionsRunning()
{
    return MAX_FUNC_RUNNING;
}
