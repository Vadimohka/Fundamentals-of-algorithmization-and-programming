#include "Ackerman.h"

unsigned long long Ackerman::func(long long m,long long n){
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return func(m - 1, 1);
    } 
    return func(m - 1, func(m, n - 1));
}

