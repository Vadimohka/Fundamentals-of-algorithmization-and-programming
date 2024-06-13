#include "algorithms.h"

//I am booored
Algorithms::Algorithms() = default;

int64_t Algorithms::BinSearch(int64_t *arr, int64_t size, int64_t val)
{
    int64_t left = 0, right = size - 1;

    while (left < right)
    {
        int64_t middle = (left + right + 1) / 2;

        if (arr[middle] > val)
        {
            right = middle - 1;
        }
        else
        {
            left = middle;
        }
    }

    if (arr[left] == val)
    {
        return left;
    }

    return -1;
}

int64_t Algorithms::BinPower(int64_t value, int64_t power, int64_t modulo)
{
    if (power == 0)
    {
        return 1;
    }

    if (power % 2 == 1)
    {
        return value * BinPower(value, power - 1, modulo) % modulo;
    }

    int64_t val = BinPower(value, power / 2, modulo);

    return val * val % modulo;
}

