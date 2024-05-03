#include "binary_power.h"

binary_power::binary_power() {}

long long binary_power::get_result(long long digit, long long powder, long long mod)
{
    return binpow(digit, powder, mod);
}

long long binary_power::binpow(long long digit, long long powder, long long mod)
{
    long long result = 1;
    while (powder > 0)
    {
        if (powder & 1)
            result = (1LL * result * digit) % mod;
        digit = (1LL * digit * digit) % mod;
        powder >>= 1;
    }
    return result;
}
