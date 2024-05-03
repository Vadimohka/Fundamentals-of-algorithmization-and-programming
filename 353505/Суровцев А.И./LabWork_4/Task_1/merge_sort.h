#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <QVector>

class merge_sort {
public:
    merge_sort();
    QVector<QVector<long long>>& get_result(QVector<long long> &arr);
    qint64 get_time_of_sort();
private:
    void sort(QVector<long long>& arr);
    void mergeSort(QVector<long long>& arr, long long left, long long right);
    void merge(QVector<long long>& arr, long long left, long long middle, long long right);
    QVector<QVector<long long>> sort_result;
    qint64 time_of_sort = -1;
};

#endif // MERGE_SORT_H
