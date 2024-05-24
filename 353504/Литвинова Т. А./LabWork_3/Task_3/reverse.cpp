#include "reverse.h"

int Reverse::reverseNumber(int num, int rev)
{
    if(num == 0)
        return rev;
    else
    {
        int digit = num % 10;
        return reverseNumber(num / 10, rev * 10 + digit);
    }
}
