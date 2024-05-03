#ifndef CONVERTER_H
#define CONVERTER_H

#include <QString>
#include <cmath>

class Converter
{
public:
    static QString IntToBin(long double val);
    static QString RealToBin(long double val);
    static QString ToBin(long double val);
    static QString ToIEEE(long double val);
};

#endif // CONVERTER_H
