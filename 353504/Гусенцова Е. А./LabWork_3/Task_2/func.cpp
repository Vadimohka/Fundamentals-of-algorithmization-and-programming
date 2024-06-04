#include "func.h"

float func::recurs(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    if (n == 0)
    {
        return recurs(m - 1, 1);
    }

    return recurs(m - 1, recurs(m, n - 1));
}
