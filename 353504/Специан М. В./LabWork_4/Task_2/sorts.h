#ifndef SORTS_H
#define SORTS_H

#include <QGraphicsScene>
#include <cmath>
#include <QTime>
#include <QCoreApplication>
#include <svector.h>
#include <sortvisuals.h>

struct bucket
{
    int first = 0;
    int size = 0;
    int current = 0;
};

class Sorts
{
public:
    static void interpolationSort(SVector&, int, int);
    static int binsearch(Vector<int>&, int);
    static int  binpow(int, int, int);
};

#endif // SORTS_H
