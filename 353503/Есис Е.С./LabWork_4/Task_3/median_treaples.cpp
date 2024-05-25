#include "median_treaples.h"

median_treaples::median_treaples() {}

QVector<long long> median_treaples::getMedianTriples(const QVector<long long> &a)
{
    QVector<long long> b;
    long long n = a.size();
    long long start = 0;

    while (start < n) {
        QVector<long long> triple;
        for (long long i = start; i < ((start + 3 < n) ? start + 3 : n); i++) {
            triple.push_back(a[i]);
        }
        start += 3;

        if (triple.size() == 3) {
            std::sort(triple.begin(), triple.end());
            b.push_back(triple[1]);
        } else if (triple.size() == 2) {
            long long avg = (triple[0] + triple[1]) / 2;
            b.push_back(avg);
        } else if (triple.size() == 1) {
            b.push_back(triple[0]);
        }
    }
    return b;
}
