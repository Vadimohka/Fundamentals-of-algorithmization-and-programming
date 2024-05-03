#include "ackermann.h"
#include <exception>
#include <stdexcept>

unsigned long long Ackermann::calculate(long long m, long long n) {
    if ((m > 4)||(m == 4 && n > 1 ) || (m == 3 && n > 10) || (m == 2 && n > 10000) || (m == 1 && n > 170000) || (m == 0 && n > 250000)) {
        throw "";
    }

    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return calculate(m - 1, 1);
    }
    return calculate(m - 1, calculate(m, n - 1));
}
