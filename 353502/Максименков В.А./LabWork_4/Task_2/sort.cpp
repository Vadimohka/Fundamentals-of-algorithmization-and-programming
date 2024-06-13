#include "sort.h"

Sort::Sort() {}


void Sort::Sorty(QVector<int> &v)
{
    int start = 0, size = v.size(), min = v[0], max = v[0];

    for (int i = 1; i < size; ++i)
    {
        if (v[i] < min)
        {
            min = v[i];
        }
        else if (v[i] > max)
        {
            max = v[i];
        }
    }

    if (min != max)
    {
        QVector<QVector<int>> bucket(size);
        int interpolation = 0;

        for (int i = 0; i < size; ++i)
        {
            interpolation = (int)(((double)(v[i] - min) / (max - min)) * (size - 1));
            bucket[interpolation].push_back(v[i]);
        }

        for (int i = 0; i < size; ++i)
        {
            if (bucket[i].size() > 1)
            {
                Sorty(bucket[i]);
            }

            for (size_t j = 0; j < bucket[i].size(); j++)
            {
                v[start++] = bucket[i][j];
            }
        }
    }
}


void Sort::SortAnimation(QVector<int> &v, QVector<QVector<int>> &listOfStates)
{
    int start = 0, size = v.size(), min = v[0], max = v[0];

    for (int i = 1; i < size; ++i)
    {
        if (v[i] < min)
        {
            min = v[i];
        }
        else if (v[i] > max)
        {
            max = v[i];
        }
    }

    if (min != max)
    {
        QVector<QVector<int>> bucket(size);
        int interpolation = 0;

        for (int i = 0; i < size; i++)
        {
            interpolation = static_cast<int>((static_cast<double>(v[i] - min) / (max - min)) * (size - 1));
            bucket[interpolation].push_back(v[i]);
        }

        for (int i = 0; i < size; ++i)
        {
            if (bucket[i].size() > 1)
            {
                listOfStates.append(v);
                Sorty(bucket[i]);
            }

            for (size_t j = 0; j < bucket[i].size(); j++)
            {
                v[start++] = bucket[i][j];
            }
        }
    }

    listOfStates.append(v);
}


































