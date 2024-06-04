#include "reverse.h"

short Reverse::NumOfDigits(long long num)
{
    if (qAbs(num) < 10) {
        return 1;
    }
    return 1 + Reverse::NumOfDigits(qAbs(num) / 10);
}

long long Reverse::ReverseNum(long long num)
{
    static short i = 0;
    short numOfDigits = NumOfDigits(num) - 1;
    if (num == 0) {
        i = 0;
        return 0;
    }
    return static_cast<long long>(static_cast<long long>(num / pow(10, numOfDigits)) * pow(10, i++))
           + Reverse::ReverseNum(num % static_cast<long long>(pow(10, numOfDigits)));
}