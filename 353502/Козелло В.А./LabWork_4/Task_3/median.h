#ifndef MEDIAN_H
#define MEDIAN_H

#include <QDebug>
#include <QVector>

class Median
{
public:
    explicit Median(QVector<int>);
    QVector<double> findMedian();

private:
    QVector<int> arr;
};

#endif // MEDIAN_H
