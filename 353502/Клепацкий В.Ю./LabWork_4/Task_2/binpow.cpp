#include "binpow.h"

Binpow::Binpow() {}

long long Binpow::binpow(long long digit, long long powder, long long mod)
{
    digit %= mod;
    long long res = 1;
    while (powder) {
        if (powder & 1) {
            res = (res * digit) % mod;
        }
        digit = (digit * digit) % mod;
        powder >>= 1;
    }
    return res;
}
