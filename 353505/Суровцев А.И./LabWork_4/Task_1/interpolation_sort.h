#ifndef INTERPOLATION_SORT_H
#define INTERPOLATION_SORT_H

#include <QVector>

class interpolation_sort
{
public:
    interpolation_sort();
    QVector<QVector<long long>>& get_result(QVector<long long> &arr);
    qint64 get_time_of_sort();
private:
    void sort(QVector<long long>& arr);
    QVector<QVector<long long>> sort_result;
    qint64 time_of_sort = -1;
};

#endif // INTERPOLATION_SORT_H
