#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <QVector>

class BinarySearch
{
public:
    BinarySearch(QVector<int>, int);
    int binarySearch(int, int);
private:
    QVector<int> vector;
    int element;
};

#endif // BINARYSEARCH_H
