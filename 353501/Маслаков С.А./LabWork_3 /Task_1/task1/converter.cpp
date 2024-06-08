#include "converter.h"
#include <QDebug>

Converter::Converter() {}

QPair<QString, QString> Converter::getinteg_and_fact(QString x)
{
    long double a = std::stold(x.toStdString());
    auto integ = std::floor(a);
    auto fact = a - integ;
    return {toBinary_integ(integ),toBinary_fact(fact)};
}

QString Converter::toBinary_integ(long double a)
{
    long double c = std::floor(a);
    if(c == 0.) return "";
    else{
        int b = std::fmod(c, 2);
        return  toBinary_integ(a / 2) + QString::number(b);
    }
}
QString Converter::toBinary_fact(long double num) {
    QString frac{};
    while(num != 0.0L && frac.size() < 1000){
        num *= 2;
        if(num > 1){
            frac += "1";
            num -= 1.0L;
        } else {
            frac += "0";
        }
    }
    return frac;
}

QString Converter::toBinaryIEE754(QString num)
{
    bool negative = num.toDouble() < 0;
    QString sign = negative?"1":"0";

    QPair<QString, QString> int_fact = getinteg_and_fact(num);
    QString binaryIntegral = int_fact.first;
    QString binaryFractional = int_fact.second;

    QString binaryRepresentation = binaryIntegral + binaryFractional;
    auto shift = binaryIntegral.indexOf('1');
    if (shift == -1)
    {
        shift = binaryFractional.indexOf('1');
        if (shift != -1)
        {
            shift = 0;
        } else {
            shift = -shift;
        }
    }
    else
    {
        shift = binaryIntegral.size() - shift - 1;
    }
    int exponent = shift + 1023;

    QString tmp = toBinary_integ(exponent).rightJustified(11, '0');
    QString binaryExponent = tmp.mid( tmp.size()-11, 11 );
    binaryRepresentation = binaryRepresentation.mid(1);
    binaryRepresentation = binaryRepresentation.leftJustified(52,'0');

    QString binaryIEEE754 = sign + "| " + binaryExponent + "| " + binaryRepresentation;

    return binaryIEEE754;
}
