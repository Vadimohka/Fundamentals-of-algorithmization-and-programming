#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <QVector>

class binary_search
{
public:
    binary_search();
    QVector<long long>& get_result(QVector<long long> &arr, long long target);
private:
    long long binarySearch(const QVector<long long>& arr, long long target);
    QVector<long long> search_result;
};

#endif // BINARY_SEARCH_H
