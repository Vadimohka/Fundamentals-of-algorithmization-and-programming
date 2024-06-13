#include "translator.h"

Translator::Translator() {}

QString Translator::_translate(int num)
{
    if (num == 0) { return ""; }
    return _translate(num / 2) + QString::number(num % 2);
}

QString Translator::Translate(double num)
{
    QString binNumber;
    int precision = 6;
    if (num < 0)
    {
        binNumber = "-";
    }
    num = qAbs(num);
    quint64 integerPart = num;
    float fractionalPart = num - integerPart;

    if(fractionalPart == 0){
        precision = 0;
    }

    if (integerPart > 0)
    {
        binNumber += _translate(integerPart);
    }
    else
    {
        binNumber += "0";
    }

    for (int i = 0; i < precision; ++i)
    {
        if (i == 0)
        {
            binNumber += ".";
        }

        fractionalPart *= 2;
        integerPart = fractionalPart;
        binNumber += QString::number(integerPart);
        fractionalPart -= integerPart;
    }

    return binNumber;
}
