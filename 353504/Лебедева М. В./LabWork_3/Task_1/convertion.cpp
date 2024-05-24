#include "convertion.h"

QString Convertion::IntegerToBin(long double value)
{
    if (std::floor(value) == 0.L)
    {
        return "";
    }
    return IntegerToBin(value / 2) + QString::number((int)fmodl(value, 2.L));
}

QString Convertion::FractionalToBin(long double value)
{
    value *= 2;

    if (value >= 1)
    {
        return "1" + FractionalToBin(value - 1.0L);
    }
    else if (value != 0)
    {
        return "0" + FractionalToBin(value);
    }
    else
    {
        return "";
    }
}

QString Convertion::ToBin(long double value)
{
    bool sign = false;

    if(value<0) {
        sign = true;
    }

    if (sign)
    {
        value *= -1;
    }

    long double IntegerPart = std::floor(value);
    long double FructionPart = value - IntegerPart;

    QString res = QString(sign ? "-" : "") + (IntegerPart!=0 ? IntegerToBin(IntegerPart) : "0") + (FructionPart!=0 ? "." : "") + FractionalToBin(FructionPart);
    if (res.size() > 50)
    {
        res.resize(50);
        res.push_back("...");
    }
    return res;
}

QString Convertion::ToIEEE(long double value)
{//1 бит знак, 11 бит экпонента, 52 мантисса
    //11^2=2048, 0...1023...2047
    bool sign = false;

    if(value<0) {
        sign = true;
    }

    value = std::abs(value);

    long double IntegerPart = std::floor(value);
    long double FructionPart = value - IntegerPart;

    QString IntegerStr = IntegerToBin(IntegerPart);
    QString FructionStr = FractionalToBin(FructionPart);

    int shift = IntegerStr.indexOf('1');//10,001//0,00110
    if (shift != -1)
    {
        shift = IntegerStr.size() - shift - 1;
    }
    else
    {
        shift = FructionStr.indexOf('1');
        if (shift != -1)
        {
            shift = -shift - 1;
        }
        else
        {
            shift = 0;
        }
    }

    QString exponent = IntegerToBin(shift + 1023);
    QString mantisse = IntegerStr.remove(0, 1) + FructionStr;
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
