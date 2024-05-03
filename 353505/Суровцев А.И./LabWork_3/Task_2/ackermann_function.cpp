#include "ackermann_function.h"

Ackermann_function::Ackermann_function() {}

int Ackermann_function::solve(int m, int n)
{
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return solve(m - 1, 1);
    } else if (m > 0 && n > 0) {
        return solve(m - 1, solve(m, n - 1));
    }
}
