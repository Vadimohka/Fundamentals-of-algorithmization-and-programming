#include "SVector.h"


struct bucket{
    size_t start = 0;
    size_t sz = 0;
    size_t cur = 0;
};

class Sorter{

private:
    static std::pair<size_t, size_t> _findMinMax(SVector& vect, size_t beg, size_t end);
    static void _interpSort(SVector& vect, size_t beg, size_t end);

public:
    static void InterpSort(SVector& vect);
    //static void Terminate();
};
    