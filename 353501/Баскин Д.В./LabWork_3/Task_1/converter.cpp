#include "converter.h"

QString Converter::IntToBin(long double value)
{
    if (std::floor(value) == 0.L)
    {
        return "";
    }
    return IntToBin(value / 2) + QString::number((int)fmodl(value, 2.L));
}

QString Converter::RealToBin(long double value)
{
    value *= 2;

    if (value >= 1)
    {
        return "1" + RealToBin(value - 1.0L);
    }
    else if (value != 0)
    {
        return "0" + RealToBin(value);
    }
    else
    {
        return "";
    }
}

QString Converter::ToBin(long double value)
{
    bool sign = value < 0;
    if (sign)
    {
        value *= -1;
    }

    long double Int = std::floor(value);
    long double Real = value - Int;

    QString res = QString(sign ? "-" : "") + (Int ? IntToBin(Int) : "0") + (Real ? "." : "") + RealToBin(Real);
    if (res.size() > 65)
    {
        res.resize(65);
        res.push_back("...");
    }
    return res;
}

QString Converter::ToIEEE(long double value)
{
    bool sign = value < 0;
    value = std::abs(value);

    long double Int = std::floor(value);
    long double Real = value - Int;
    QString IntStr = IntToBin(Int);
    QString RealStr = RealToBin(Real);

    int shift = IntStr.indexOf('1');
    if (shift != -1)
    {
        shift = IntStr.size() - shift - 1;
    }
    else
    {
        shift = RealStr.indexOf('1');
        if (shift != -1)
        {
            shift = -shift - 1;
        }
        else
        {
            shift = 0;
        }
    }

    QString exponent = IntToBin(shift + 1023);
    QString mantisse = IntStr.remove(0, 1) + RealStr;
    for (int i = mantisse.size() - 1; i < 52; ++i)
    {
        mantisse.push_back("0");
    }

    for (int i = exponent.size() - 1; i < 11; ++i)
    {
        exponent.push_front("0");
    }

    QString exp = exponent.right(11);
    QString mant = mantisse.left(52);

    QString res = QString(sign ? '1' : '0') + " | " + exp + " | " + mant;
    return res;
}
