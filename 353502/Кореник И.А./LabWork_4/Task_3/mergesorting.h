#ifndef MERGESORTING_H
#define MERGESORTING_H
#include "abstractsorting.h"
#include <QCoreApplication>
#include <QThread>
class MergeSorting : public AbstractSorting
{
public:
    MergeSorting();

    void static sort(QVector<int>&, QHBoxLayout*);
    //void static SortAnimation(QVector<int>&, QVector<QVector<int>>& listOfBeings);
private:
    void static merge(QVector<int>&, int, int, int, QHBoxLayout*);
    void static mergeSort(QVector<int>&, int, int, QHBoxLayout*);
    //void static mergeSortForAnimation(QVector<int>&, int, int, QVector<QVector<int>>& listOfBeings);

};

#endif // MERGESORTING_H
