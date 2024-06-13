#include "mathematics.h"

Mathematics::Mathematics() {}

int Mathematics::inverse(int number)
{
    return _inverse(number, digitsCount(number));
}

int Mathematics::digitsCount(int number)
{
    if (number < 10) return 1;

    return 1 + digitsCount(number / 10);
}

int Mathematics::_inverse(int number, int digits)
{
    if (digits == 1) return number;

    return (number % 10 * (binPow(10, digits - 1)) + _inverse(number / 10, digits - 1));
}

int Mathematics::binPow(int a, int n)
{
    if (n == 0 || a == 1) return 1;

    int num = binPow(a, n / 2);

    if (n % 2 == 0) return num * num;

    return num * num * a;
}

