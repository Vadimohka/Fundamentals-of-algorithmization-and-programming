#ifndef MEDIANVECTOR_H
#define MEDIANVECTOR_H

#include <QVector>
#include <algorithm>

class MedianVector
{
public:
    MedianVector();
    QVector<double> buildMedianVector(const QVector<int>& arr);

private:
    double calculateMedian(const QVector<int>& triplet);
};

#endif // MEDIANVECTOR_H
