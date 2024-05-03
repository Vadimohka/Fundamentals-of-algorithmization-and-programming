#include "interpoliationsort.h"
#include <QDebug>
InterpoliationSort::InterpoliationSort() {}



void InterpoliationSort::swap(int &i, int &j)
{
    int sw = i;
    i = j;
    j = sw;
}

void InterpoliationSort::interpolationSort(QVector<int> &arr, QVector <QVector<int>>& motionVector)
{
    int n = 0;
    long long size = arr.size();

    long long start = 0, end = size, location = 0, slot = 0, i = 0, j = 0, min = 0, max = 0;
    QVector<QVector<long long>> bucket(size);
    QVector<long long> process;
    process.append(size);

    while (!process.isEmpty())
    {
        location = process.last();
        process.removeLast();
        start = end - location;
        max = arr[start];
        min = arr[start];
        for (i = start + 1; i < end; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
            else if (arr[i] < min)
            {
                min = arr[i];
            }
            n++;
        }
        if (min == max)
        {
            end = end - location;
        }
        else
        {
            for (i = start; i < end; ++i)
            {
                slot = static_cast<long long>(std::floor(((arr[i] - min) / static_cast<double>(max - min)) * (location - 1)));
                bucket[slot].append(arr[i]);
                n++;
            }
            for (i = 0; i < location; ++i)
            {
                if (!bucket[i].isEmpty())
                {
                    for (j = 0; j < bucket[i].size(); j++)
                    {
                        arr[start] = bucket[i][j];
                        motionVector.append(arr);
                        start++;
                        n++;
                    }
                    process.append(bucket[i].size());
                }
            }
            for (i = 0; i < size; ++i)
            {
                bucket[i].clear();

            }

        }
    }
    qDebug() << n;

}








