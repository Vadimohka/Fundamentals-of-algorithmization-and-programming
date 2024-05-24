#include "binpow.h"

Binpow::Binpow()
{

}

ll Binpow::binpow(ll digit, ll power, ll mod)
{
    digit %= mod;
    ll res = 1;
    while (power > 0) {
        if (power & 1) {
            res = (res * digit) % mod;
        }
        digit = (digit * digit) % mod;
        power >>= 1;
    }
    return res;
}
