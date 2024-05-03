#ifndef MEDIANTRIPLES_H
#define MEDIANTRIPLES_H

#include <QVector>

class MedianTriples
{
public:
    MedianTriples();
    QVector<long long> get_median_triples(const QVector<long long> &a);
    QVector<long long> get_arr_of_index();
    QVector<long long> get_arr_of_double_index();
private:
    QVector<long long> arr_of_index;
    QVector<long long> arr_of_double_index;
};

#endif // MEDIANTRIPLES_H
