#include "convert.h"

QString Converter::IntToBin(long double val){
    if(std::floor(val) == 0.L) return "";
    return IntToBin(std::floor(val/2)) + QString::number(static_cast<int>(std::fmod(val, 2.L)));

}

QString Converter::RealToBin(long double val){
    val *=2;

    if(val >= 1) return "1" + RealToBin(val-1.0L);
    else if (val != 0) return "0" + RealToBin(val);
    else return "";

}


QString Converter::ToBin(long double val)
{
    bool sign = val < 0;
    if (sign)
    {
        val *= -1;
    }

    long double Int = std::floor(val);
    long double Real = val - Int;

    QString res = QString(sign ? "-" : "") + (Int != 0 ? IntToBin(Int) : "0") + (Real != 0 ? "." : "") + RealToBin(Real);
    if (res.size() > 65)
    {
        res.resize(65);
        res.push_back("...");
    }
    return res;
}
QString Converter::ToIEEE(long double val)
{
    bool sign = val < 0;
    val = std::abs(val);

    long double Int = std::floor(val);
    long double Real = val - Int;
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
