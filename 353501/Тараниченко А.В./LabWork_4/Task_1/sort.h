#ifndef SORT_H
#define SORT_H

#include <QObject>
#include <vector>

class Sort : public QObject {
    Q_OBJECT
public:
    explicit Sort(QObject *parent = nullptr);

    void quickSort(std::vector<int> &array, int left, int right);
    void heapSort(std::vector<int> &arr);
    void heapify(std::vector<int> &arr, int n, int i);
    void mergeSort(std::vector<int> &arr, int l, int r);
    void merge(std::vector<int> &arr, int l, int m, int r);
    int binarySearch(const std::vector<int> &arr, int digit);
};

#endif // SORT_H
