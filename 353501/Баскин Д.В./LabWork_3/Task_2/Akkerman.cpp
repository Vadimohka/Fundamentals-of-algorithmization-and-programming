#include <Akkerman.h>

unsigned long long Akkerman::Evaluate(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    if (n == 0)
    {
        return Evaluate(m - 1, 1);
    }

    return Evaluate(m - 1, Evaluate(m, n - 1));
}
