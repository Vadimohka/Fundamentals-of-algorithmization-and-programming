#include "binary.h"

QString Binary::IntToBin(long double value)
{
    if (std::floor(value) == 0.L)
    {
        return "";
    }
    return IntToBin(value / 2) + QString::number((int)fmodl(value, 2.L));
}

QString Binary::RealToBin(long double value)
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

QString Binary::ToBin(long double value)
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


