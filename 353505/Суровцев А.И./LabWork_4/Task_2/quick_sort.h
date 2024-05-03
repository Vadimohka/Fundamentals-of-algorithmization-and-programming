#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <QVector>

class quick_sort {
public:
    quick_sort();
    QVector<QVector<long long>>& get_result(QVector<long long>& arr);
    qint64 get_time_of_sort();
private:
    void sort(QVector<long long>& arr);
    void quickSort(QVector<long long>& arr, long long low, long long high);
    long long partition(QVector<long long>& arr, long long low, long long high);
    QVector<QVector<long long>> sort_result;
    qint64 time_of_sort = -1;
};

#endif // QUICK_SORT_H
