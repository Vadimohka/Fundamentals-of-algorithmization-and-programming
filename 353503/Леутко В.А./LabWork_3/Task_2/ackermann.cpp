#include "ackermann.h"

Ackermann::Ackermann() {}

int Ackermann::calculate(int m, int n)
{
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return calculate(m - 1, 1);
    } else if (m > 0 && n > 0) {
        return calculate(m - 1, calculate(m, n - 1));
    }
}
