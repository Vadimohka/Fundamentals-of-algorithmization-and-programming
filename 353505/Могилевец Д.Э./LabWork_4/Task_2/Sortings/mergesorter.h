#ifndef MERGESORTER_H
#define MERGESORTER_H

#include <QVector>

class MergeSorter
{

public:
    MergeSorter();
    void static Sort(QVector<int>&);
    void static SortAnimation(QVector<int>&, QVector<QVector<int>>& listOfBeings);
private:
    void static merge(QVector<int>&, int, int, int);
    void static mergeSort(QVector<int>&, int, int);
    void static mergeSortForAnimation(QVector<int>&, int, int, QVector<QVector<int>>& listOfBeings);
};

#endif // MERGESORTER_H
