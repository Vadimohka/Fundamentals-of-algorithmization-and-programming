#include "mathematics.h"
#include <QDebug>
Mathematics::Mathematics() {}

QString Mathematics::decToBin(double dec)
{
    if (dec < 0) return "-" + decToBin(-dec);


    int number = dec;
    double tail = dec - number;

    return intToBin(number) + tailToBin(tail);
}

QString Mathematics::intToBin(int number)
{
    if (number == 0) return "";

    return intToBin(number / 2) + QString::number(number % 2);
}

QString Mathematics::tailToBin(double tail)
{
    if (abs(tail) < 1e-5) return "";

    return "." + _tailToBin(tail, QString::number(tail).size() * 3);
}

QString Mathematics::_tailToBin(double tail, int digits)
{
    if (abs(tail) < 1e-7 || digits == 0) return "";

    if (2 * tail >= 1) return "1" + _tailToBin(2 * tail - 1, digits - 1);
    return "0" + _tailToBin(2 * tail, digits - 1);
}
