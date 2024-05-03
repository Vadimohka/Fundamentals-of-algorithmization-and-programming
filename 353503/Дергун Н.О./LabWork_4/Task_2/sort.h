#ifndef SORT_H
#define SORT_H

#include <QVector>
#include <QObject>
#include <QEventLoop>
#include <QTimer>


const int MAX_COMP_DELAY = 600;
const int MAX_CHANGE_DELAY = 500;
const int MAX_SWAP_DELAY = 500;
const int MIN_COMP_DELAY = 6;
const int MIN_CHANGE_DELAY = 5;
const int MIN_SWAP_DELAY = 5;


class VSort : public QObject {
    Q_OBJECT

    static const int MAX_FUNC_RUNNING = 9000;
    static int runningFuctionsCntr;
    static bool isOverflowed;

    int _compDelay;
    int _changeDelay;
    int _swapDelay;

    void mergeArrays(int *start, int *mid, int *end, int arrSize);
    void heapify(int *array, int arrSize, int pos);
    void sortPart(int* &end, QVector<int> &partSizes);
    void skip (int ms);
    void updateDelays(int size);
    void emitCompare(int* a, int* b);
    void emitChanging(int* i, int value);
    void emitSwapping(int* a, int* b);

    void heap(int* array, int size);
    void merge(int* start, int* end);
    void quick(int* start, int* end);
    void quick3Way(int* start, int* end);
    bool quicks(int* start, int* end);
    void interpolation(int* array, int size);

public:
    // sort algorithms
    void Heap(int* start, int* end);
    void Heap(int* array, int size);
    void Merge(int* start, int* end);
    void Merge(int* array, int size);
    void Quick(int* start, int* end);
    void Quick3Way(int* start, int* end);
    void Quick(int* array, int size);
    void Quick3Way(int* array, int size);
    void Interpolation(int* start, int* end);
    void Interpolation(int* array, int size);

    // safe sort algorithms
    bool Quicks(int* start, int* end);
    bool Quicks(int* array, int size);

    int maxFunctionsRunning();

signals:
    void startComparison(int* a, int* b);
    void finishComparison(int* a, int* b);
    void swapping(int* a, int* b);
    void changing(int* i, int value);
    void finish();
};

#endif // SORT_H
