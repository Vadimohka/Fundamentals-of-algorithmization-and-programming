#include "binsearch.h"

Binsearch::Binsearch() {}


int Binsearch::BinSearch(const QVector<int> &v, int number)
{
    if (v[0] > number || v[v.size() - 1] < number) return -1;
    if (v[0] == number) return 0;

    int l = 0, r = v.size() - 1, mid;

    while (l + 1 < r)
    {
        mid = (l + r) / 2;
        if (v[mid] < number)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    return r;
}
