#ifndef CONVERTION_H
#define CONVERTION_H

#include <QString>
#include <cmath>

class Convertion
{
public:
    static QString IntegerToBin(long double);
    static QString FractionalToBin(long double);
    static QString ToBin(long double);
    static QString ToIEEE(long double);
};

#endif // CONVERTION_H
