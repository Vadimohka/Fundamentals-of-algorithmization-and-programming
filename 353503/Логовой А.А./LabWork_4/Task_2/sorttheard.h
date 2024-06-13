#ifndef SORTTHREAD_H
#define SORTTHREAD_H

#include <QThread>

class SortThread : public QThread
{
    Q_OBJECT

public:
    enum SortingAlgorithm {
        QuickSort,
        MergeSort,
        HeapSort,
        InterpolationSort,
    };

    void setSortingAlgorithm(SortingAlgorithm algorithm);

    SortThread(int* array, int size, QObject *parent = nullptr);

    void run() override;

signals:
    void arrayUpdated(int* array, int size);

private:
    int* m_array;
    int m_size;
    SortingAlgorithm m_algorithm;
};

#endif // SORTTHREAD_H
