#ifndef QUICKSORTING_H
#define QUICKSORTING_H
#include "abstractsorting.h"
class QuickSorting : public AbstractSorting
{
public:
    QuickSorting();

private:
    void static InSort(QVector<int>&, int, int, QHBoxLayout*);

public:

    void static sort(QVector<int>&, QHBoxLayout*);

};

#endif // QUICKSORTING_H
