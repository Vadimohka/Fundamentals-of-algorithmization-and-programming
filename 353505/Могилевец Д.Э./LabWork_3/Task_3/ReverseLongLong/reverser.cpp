#include "reverser.h"

Reverser::Reverser() {}

long long Reverser::Reverse(long long num)
{
    if (num == 0) return 0;
    int tenpow = 1, numcp = num;
    while (numcp != 0) {
        numcp /= 10;
        tenpow *= 10;
    }
    tenpow /= 10;
    return tenpow * (num % 10) + Reverse(num / 10);
}
