#ifndef INTERPOLATIONSORTING_H
#define INTERPOLATIONSORTING_H
#include <abstractsorting.h>
class InterpolationSorting : public AbstractSorting
{
public:
    InterpolationSorting();
    void static sort(QVector<int>&, QHBoxLayout* visual = nullptr);

    //void static sortWithoutAnimation(QVector<int>&);
    //void static SortAnimation(QVector<int>&, QVector<QVector<int>>&);
};

#endif // INTERPOLATIONSORTING_H
