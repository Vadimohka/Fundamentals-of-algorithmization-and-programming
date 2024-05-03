#include "convert.h"
#include <cmath>

QString Convert::decimalToBinary(long double n)
{
    long double intPart, fracPart;
    fracPart = modfl(n, &intPart);
    QString binaryIntPart;
    while (intPart > 0) {
        binaryIntPart.prepend(QString::number(int(intPart) % 2));
        intPart = floor(intPart / 2);
    }
    QString binaryFracPart;
    while (fracPart > 0) {
        fracPart *= 2;
        fracPart = modfl(fracPart, &intPart);
        binaryFracPart += QString::number(int(intPart));
    }
    return binaryIntPart + (binaryFracPart.isEmpty() ? "" : "." + binaryFracPart);
}
