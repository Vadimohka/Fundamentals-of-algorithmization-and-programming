#include "ackermann.h"

Ackermann::Ackermann() {}

int Ackermann::func(int m, int n)
{
    if (m == 0 && stop < 100000)
    {
        return n + 1;
    }
    else if (n == 0 && m > 0)
    {
        return func(m - 1, 1);
    }
    else
    {
        return func(m - 1, func(m, n - 1));
    }
}
