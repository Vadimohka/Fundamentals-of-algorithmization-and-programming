#include "recursively_invert.h"

Recursively_invert::Recursively_invert() {}

int Recursively_invert::invert(int &number, int reversed_number)
{
    if (number == 0)
        return reversed_number;
    else if (containsZero(number)) return -1;
    else {
        int last_digit = number % 10;
        reversed_number = reversed_number * 10 + last_digit;
        number = number / 10;
        return invert(number, reversed_number);
    }
}

bool Recursively_invert::containsZero(int n)
{
    while (n != 0) {
        int last_digit = n % 10;
        if (last_digit == 0)
            return true;
        n = n / 10;
    }
    return false;
}
