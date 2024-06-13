//
// Created by acryoz on 4/14/24.
//

#include "../headers/binpow.h"

long long binPowMod(int base, int power, int mod) {
    long long ans = 1;
    while (power > 0) {
        if (power & 1 != 0) {
            ans = (ans % mod * base % mod) % mod;
        }
        base = (base % mod * base % mod) % mod;
        power >>= 1;
    }
    return ans;
}