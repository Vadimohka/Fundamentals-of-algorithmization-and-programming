#include "bindectranslator.h"


QString Translator::_translateFDecTBin(const quint64 decNumber)
{
    if (decNumber == 0) { return ""; }
    return _translateFDecTBin(decNumber / 2) + QString::number(decNumber % 2);
}

QString Translator::TranslateFDecTBin(double decNumber, quint8 precision)
{
    QString binNumber;
    if (decNumber < 0)
    {
        binNumber = "-";
    }
    decNumber = qAbs(decNumber);
    quint64 integerPart = decNumber;
    float fractionalPart = decNumber - integerPart;

    if (integerPart > 0)
    {
        binNumber += _translateFDecTBin(integerPart);
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
