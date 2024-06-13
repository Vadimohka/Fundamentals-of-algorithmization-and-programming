#include "algorithms.h"

//I am booored
Algorithms::Algorithms() = default;

int64_t Algorithms::Hanoi(size_t from, size_t to, size_t count)
{
    if (count == 0)
    {
        return 0;
    }

    size_t free = 3 - from - to;

    size_t answer = Hanoi(from, free, count - 1);
    std::cout << "From " << from << " to " << to << std::endl;
    answer += Hanoi(free, to, count - 1);
    return answer + 1;
}
