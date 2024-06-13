#ifndef ABSTRACTSORTING_H
#define ABSTRACTSORTING_H

#include <QVector>
#include "sortinganimation.h"
class AbstractSorting
{
public:
    AbstractSorting();



    static void swap(int &a, int &b);
signals:
    void sort(QVector<int>*);

};

#endif // ABSTRACTSORTING_H
