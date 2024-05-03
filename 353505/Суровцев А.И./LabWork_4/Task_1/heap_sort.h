#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <QVector>

class heap_sort
{
public:
    heap_sort();
    QVector<QVector<long long>>& get_result(QVector<long long> &arr);
    qint64 get_time_of_sort();
private:
    void sort(QVector<long long>& arr);
    void heapify(QVector<long long>& arr, long long n, long long i);
    QVector<QVector<long long>> sort_result;
    qint64 time_of_sort = -1;
};

#endif // HEAP_SORT_H
