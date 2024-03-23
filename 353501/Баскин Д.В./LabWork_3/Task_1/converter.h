#ifndef CONVERTER_H
#define CONVERTER_H

#include <QString>
#include <cmath>

class Converter
{
public:
    static QString IntToBin(long double);
    static QString RealToBin(long double);
    static QString ToBin(long double);
    static QString ToIEEE(long double);
};

#endif // CONVERTER_H
