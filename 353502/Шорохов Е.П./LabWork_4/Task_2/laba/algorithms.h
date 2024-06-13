#ifndef ALGORITHMS_H
#define ALGORITHMS_H
//I am booored
#include <cstdint>

class Algorithms
{
public:
    Algorithms();
    static int64_t BinSearch(int64_t *arr, int64_t size, int64_t val);
    static int64_t BinPower(int64_t value, int64_t power, int64_t modulo);
};

#endif // ALGORITHMS_H
