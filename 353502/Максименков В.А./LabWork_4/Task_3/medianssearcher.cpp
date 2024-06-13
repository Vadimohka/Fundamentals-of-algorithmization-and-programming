#include "medianssearcher.h"


MediansSearcher::MediansSearcher(QVector<int> &v): v(v) {}


QVector<double> MediansSearcher::crateMedians()
{
    QVector<double> ans;
    triples = QVector<int>();

    for (int i = 0; i < v.size(); ++i)
    {
        triples.push_back(v[i]);
        if (i % 3 == 2)
        {
            ans.push_back(findMedian());
            triples.clear();
        }
    }

    if (triples.size() == 1) ans.push_back(triples[0]);
    if (triples.size() == 2) ans.push_back((triples[0] + triples[1]) / 2.0);
    triples.clear();

    return ans;
}


int MediansSearcher::findMedian()
{
    sort();
    return triples[1];
}


void MediansSearcher::sort()
{
    for (int i = 0; i < triples.size(); ++i)
    {
        for (int j = i + 1; j < triples.size(); ++j)
        {
            if (triples[j] < triples[i]) std::swap(triples[i], triples[j]);
        }
    }
}
