#ifndef DECTOBIN_H
#define DECTOBIN_H

#endif // DECTOBIN_H
#include <QString>

QString convertInteger(int num)
{
    if (num == 0)
    {
        return "0";
    }
    if (num == 1)
    {
        return "1";
    }
    return convertInteger(num / 2) + QString::number(num % 2);
}

QString convertFraction(double frac)
{
    frac = fabs(frac);
    if (frac >= 1.0)
    {
        return "";
    }
    double two_frac = 2.0 * frac;
    int digit = static_cast<int>(two_frac);
    return QString::number(digit) + convertFraction(two_frac - digit);
}

QString translate(double num)
{
    int integerPart = static_cast<int>(num);
    double fractionalPart = num - integerPart;

    QString integerBinary = convertInteger(integerPart);
    QString fractionalBinary = convertFraction(fractionalPart);

    return integerBinary + "." + fractionalBinary;
}
