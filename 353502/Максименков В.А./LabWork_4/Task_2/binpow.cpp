#include "binpow.h"

Binpow::Binpow() {}


long long Binpow::BinPow(long long number, long long power, long long modul)
{
    if (number == -1) return (power % 2 == 0 ? 1LL : -1LL);
    if (number == 0) return 0LL;
    if (number == 1 || power == 0) return 1LL;

    long long temp = BinPow(number, power/2, modul) % modul;

    if (power % 2 == 1)
    {
        return ((number % modul) * ((temp * temp) % modul)) % modul;
    }
    else
    {
        return (temp * temp) % modul;
    }

    /*if (power == 0) return 1;
    long long z = BinPow(number % modul, power / 2, modul) % modul;
    if (power % 2 == 0)
        return (z * z) % modul;
    else
        return ((number % modul) * ((z * z) % modul)) % modul;*/
}
