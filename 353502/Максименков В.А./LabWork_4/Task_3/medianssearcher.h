#ifndef MEDIANSSEARCHER_H
#define MEDIANSSEARCHER_H

#include <QVector>
#include <QDebug>

class MediansSearcher
{
private:
    QVector<int> v;
    QVector<int> triples;

public:
    MediansSearcher(QVector<int>& v);
    QVector<double> crateMedians();
    int findMedian();
    void sort();


};

#endif // MEDIANSSEARCHER_H
