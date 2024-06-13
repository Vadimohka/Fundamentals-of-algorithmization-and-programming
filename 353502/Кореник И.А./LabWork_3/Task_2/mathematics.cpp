#include "mathematics.h"

Mathematics::Mathematics() {}

long long Mathematics::Ackerman(int m, int n)
{
    if (m == 0) return n + 1;
    if (n == 0) return Ackerman(m - 1, 1);
    return (Ackerman(m - 1, Ackerman(m, n - 1)));
}
