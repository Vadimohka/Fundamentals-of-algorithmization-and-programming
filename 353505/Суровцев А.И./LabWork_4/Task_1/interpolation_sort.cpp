#include "interpolation_sort.h"

interpolation_sort::interpolation_sort() {}

QVector<QVector<long long> > &interpolation_sort::get_result(QVector<long long> &arr)
{
    sort_result.push_back(arr);
    clock_t t0 = clock();
    sort(arr);
    size_t t = clock() - t0;
    time_of_sort = (double)t / CLOCKS_PER_SEC * 100000.0;
    sort_result.push_back(arr);
    return sort_result;
}

qint64 interpolation_sort::get_time_of_sort()
{
    return time_of_sort;
}

void interpolation_sort::sort(QVector<long long> &arr)
{
    long long size = arr.size();
    if (size <= 0)
    {
        return;
    }
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
            }
            for (i = 0; i < location; ++i)
            {
                if (!bucket[i].isEmpty())
                {
                    for (j = 0; j < bucket[i].size(); j++)
                    {
                        arr[start] = bucket[i][j];
                        start++;
                    }
                    sort_result.push_back(arr);
                    process.append(bucket[i].size());
                }
            }
            for (i = 0; i < size; ++i)
            {
                bucket[i].clear();
            }
        }
    }
}

