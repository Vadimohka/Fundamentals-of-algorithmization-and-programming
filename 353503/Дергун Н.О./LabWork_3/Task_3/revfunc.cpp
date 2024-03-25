#include "revfunc.h"

static QPair<int, int> findDigitNumber(QPair<int, int> inPair)
{
    int number = inPair.first;
    int size = inPair.second;

    if (number == 0) { return inPair; }

    number /= NUMBER_SYSTEM_BASIS;
    ++size;

    return findDigitNumber(QPair<int, int&>(number, size));
}

static void reverseFunc(QPair<int&, int> inPair)
{
    int& number = inPair.first;
    int revPos = inPair.second;
    int size = findDigitNumber(QPair<int, int>(number, 0)).second;

    if (revPos >= size / 2) { return; }

    int leftDigit = (number / static_cast<int>(qPow(NUMBER_SYSTEM_BASIS, size - 1 - revPos))) % NUMBER_SYSTEM_BASIS;
    int rightDigit = (number / static_cast<int>(qPow(NUMBER_SYSTEM_BASIS, revPos))) % NUMBER_SYSTEM_BASIS;
    int dif = leftDigit - rightDigit;
    number -= dif * static_cast<int>(qPow(NUMBER_SYSTEM_BASIS, size - 1 - revPos));
    number += dif * static_cast<int>(qPow(NUMBER_SYSTEM_BASIS, revPos));

    reverseFunc(QPair<int&, int>(number, ++revPos));
}

int reverseFunc(int number)
{
    reverseFunc(QPair<int&, int>(number, 0));
    return number;
}
