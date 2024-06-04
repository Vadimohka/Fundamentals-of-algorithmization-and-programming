#include "unoreverse.h"

UnoReverse::UnoReverse() {}
long long UnoReverse::rev(long long n, long long a) {

    if (n == 0) {
        return a;
    } else {
        return rev(n / 10, 10 * a + n % 10);
    }
}
