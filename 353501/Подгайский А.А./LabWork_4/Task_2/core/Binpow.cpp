#include "Binpow.h"

long Binpow::get(long base, long pow, long mod) {
    if(pow == 0)
        return 1;
    else if(pow % 2 == 0)
    {
        long half_power = get(base, pow/2, mod) % mod;
        return half_power*half_power % mod;
    }
    else {
        return base *get(base, pow-1, mod) % mod;
    }
}
