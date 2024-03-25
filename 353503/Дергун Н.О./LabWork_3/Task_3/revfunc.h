#ifndef REVFUNC_H
#define REVFUNC_H

#include <QPair>
#include <QtMath>

const int NUMBER_SYSTEM_BASIS = 10;

static QPair<int, int> findDigitNumber(QPair<int, int> inPair);
static void reverseFunc(QPair<int&, int> inPair);
int reverseFunc(int number);

#endif // REVFUNC_H
