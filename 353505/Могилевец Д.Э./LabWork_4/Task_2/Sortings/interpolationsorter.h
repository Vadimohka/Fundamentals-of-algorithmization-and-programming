#ifndef INTERPOLATIONSORTER_H
#define INTERPOLATIONSORTER_H

#include <QVector>

class InterpolationSorter
{
public:
    InterpolationSorter();
    void static Sort(QVector<int>&);
    void static SortAnimation(QVector<int>&, QVector<QVector<int>>&);
};

#endif // INTERPOLATIONSORTER_H
