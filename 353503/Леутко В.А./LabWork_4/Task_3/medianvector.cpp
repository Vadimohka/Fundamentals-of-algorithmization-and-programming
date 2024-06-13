#include "medianvector.h"

MedianVector::MedianVector() {}

double MedianVector::calculateMedian(const QVector<int>& triplet)
{
    QVector<int> sortedTriplet = triplet;
    std::sort(sortedTriplet.begin(), sortedTriplet.end());

    int size = sortedTriplet.size();
    int middleIndex = size / 2;

    if (size % 2 == 0) {
        return (sortedTriplet[middleIndex - 1] + sortedTriplet[middleIndex]) / 2.0;
    } else {
        return sortedTriplet[middleIndex];
    }
}

QVector<double> MedianVector::buildMedianVector(const QVector<int>& arr)
{
    QVector<double> medianVector;

    int size = arr.size();
    int i = 0;

    while (i < size) {
        QVector<int> triplet;

        for (int j = 0; j < 3 && i < size; ++j) {
            triplet.push_back(arr[i]);
            ++i;
        }

        double median = calculateMedian(triplet);

        medianVector.push_back(median);

        triplet.clear();
    }

    return medianVector;
}
