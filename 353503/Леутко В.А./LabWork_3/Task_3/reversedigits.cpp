#include "reversedigits.h"

ReverseDigits::ReverseDigits() {}

int ReverseDigits::reverse(int n)
{
    return reverseRecursive(n, 0);
}

int ReverseDigits::reverseRecursive(int n, int reversed)
{
    if (n == 0) {
        return reversed;
    } else {
        int lastDigit = n % 10;
        int newReversed = reversed * 10 + lastDigit;
        int remainingDigits = n / 10;
        return reverseRecursive(remainingDigits, newReversed);
    }
}

