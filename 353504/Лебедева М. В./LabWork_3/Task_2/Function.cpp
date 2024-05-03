#include "Function.h"

Function::Function() {}

long long Function::Calculate(long long m, long long n)
{
    if (m == 0) return n + 1;
    if (m > 0 && n == 0) return Calculate(m - 1, 1);
    else return Calculate(m - 1, Calculate(m, n - 1));
}
