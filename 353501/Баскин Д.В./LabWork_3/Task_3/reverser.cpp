#include "reverser.h"

unsigned long long Reverser::Reverse(unsigned long long value, unsigned long long reversed)
{
    if (value != 0)
    {
        unsigned long long digit = value % 10;
        return Reverse(value / 10, reversed * 10 + digit);
    }
    return reversed;
}
