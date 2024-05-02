#include "mediantriples.h"

MedianTriples::MedianTriples() {}

QVector<long long> MedianTriples::get_median_triples(const QVector<long long> &a)
{
    QVector<long long> b;
    long long n = a.size();
    long long start = 0;

    while (start < n)
    {
        QVector<long long> triple;
        for (long long i = start; i < std::min(start + 3, n); ++i)
        {
            triple.push_back(a[i]);
        }
        start += 3;

        if (triple.size() == 3)
        {
            std::sort(triple.begin(), triple.end());
            b.push_back(triple[1]);
            auto it = std::find(triple.begin(), triple.end(), triple[1]);
            int index = std::distance(triple.begin(), it);
            arr_of_index.push_back(index + start - 3);
        }
        else if (triple.size() == 2)
        {
            long long avg = (triple[0] + triple[1]) / 2;
            b.push_back(avg);
            arr_of_double_index.push_back(start - 3);
            arr_of_double_index.push_back(start - 2);
        }
        else if (triple.size() == 1)
        {
            b.push_back(triple[0]);
            arr_of_double_index.push_back(start - 3);
        }
    }

    return b;
}

QVector<long long> MedianTriples::get_arr_of_index()
{
    return arr_of_index;
}

QVector<long long> MedianTriples::get_arr_of_double_index()
{
    return arr_of_double_index;
}
