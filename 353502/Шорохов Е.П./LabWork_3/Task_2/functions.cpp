#include "functions.h"
//I am booored
Functions::Functions() = default;

int64_t Functions::Ackermann(int64_t firstVal, int64_t secondVal)
{
    if (firstVal == 0)
    {
        return secondVal+1;
    }
    else if (firstVal > 0 && secondVal == 0)
    {
        return Ackermann(firstVal-1, 1);
    }

    return Ackermann(firstVal - 1, Ackermann(firstVal, secondVal - 1));
}
