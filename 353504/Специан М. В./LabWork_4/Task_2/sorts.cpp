#include "sorts.h"

void Sorts::interpolationSort(SVector& ref, int first, int last)
{
    if (last - first <= 1)
    {
        return;
    }
    int size = last - first;
    Vector<int> indexs(size);
    SVector temp;
    for (int i = first; i < last; ++i)
    {
        temp.push_back(ref[i]);
    }
    Vector<bucket> buckets;

    int min = temp[0], max = temp[0];
    for (int i = 0; i < size; i++)
    {
        if (temp[i] < min)
        {
            min = temp[i];
        }
        else if (temp[i] > max)
        {
            max = temp[i];
        }
    }

    if (max - min != 0)
    {
        for (int i = 0; i < size; ++i)
        {
            int interpolation = (size - 1) * (temp[i] - min) / (max - min);
            indexs[i] = interpolation;

            if (buckets.size() <= interpolation)
            {
                buckets.resize(interpolation + 1);
            }
            ++buckets[interpolation].size;
        }

        int bIndex = 0;
        for (int i = 0; i < buckets.size(); ++i)
        {
            buckets[i].first = bIndex;
            bIndex += buckets[i].size;
        }

        for (int i = 0; i < size; ++i)
        {
            int bIndex = indexs[i];
            int index = buckets[bIndex].first + buckets[bIndex].current;
            ref.emitSignal(first + index, temp[i]);
            ++buckets[bIndex].current;
        }

        for (int i = 0; i < buckets.size(); ++i)
        {
            interpolationSort(ref, first + buckets[i].first, first + buckets[i].first + buckets[i].size);
        }
    }
}

int Sorts::binsearch(Vector<int>& vec, int digit)
{
    int left = 0, right = vec.size() - 1;
    while (right > left)
    {
        int mid = (left + right) / 2;
        if (vec[mid] > digit)
        {
            right = mid - 1;
        }
        else if (vec[mid] < digit)
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    if (vec[left] == digit)
    {
        return left;
    }
    else
    {
        return -1;
    }
}

int Sorts::binpow(int digit, int power, int mod)
{
    if (power == 0)
    {
        return 1;
    }

    if (power % 2)
    {
        return (binpow(digit, power - 1, mod) * digit) % mod;
    }
    else
    {
        long res = binpow(digit, power / 2, mod);
        return (res * res) % mod;
    }
}
