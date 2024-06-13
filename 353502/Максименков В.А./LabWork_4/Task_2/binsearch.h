#ifndef BINSEARCH_H
#define BINSEARCH_H

#include <QVector>

class Binsearch
{
public:
    Binsearch();

    static int BinSearch(const QVector<int>& v, int number);
};

#endif // BINSEARCH_H
