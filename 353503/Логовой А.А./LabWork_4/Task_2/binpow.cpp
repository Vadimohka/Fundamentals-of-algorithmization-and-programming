#include<binpow.h>

int binpow(int digit, int power, int mod) {
    int result = 1;
    digit %= mod;
    while (power > 0) {
        if (power & 1)
            result = (result * digit) % mod;
        digit = (digit * digit) % mod;
        power >>= 1;
    }
    return result;
}
