#include "abstractsorting.h"

AbstractSorting::AbstractSorting() {}

void AbstractSorting::sort(QVector<int> *) {}

void AbstractSorting::swap(int &a, int &b)
{
    int tmp = b;
    b = a;
    a = tmp;
}
