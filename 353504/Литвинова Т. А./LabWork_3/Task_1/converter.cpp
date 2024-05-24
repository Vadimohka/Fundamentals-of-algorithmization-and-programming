#include "converter.h"

QString Converter::decimalToBinary(int number)
{
    QString binaryIntegerPart = QString::number(number, 2);
    return binaryIntegerPart;
}

QString Converter::decimalToBinary(double number)
{
    int integerPart = int(number);
    double decimalPart = number - integerPart;

    QString binaryIntegerPart = QString::number(integerPart, 2);
    QString binaryDecimalPart = decimalPartToBinary(decimalPart);

    return binaryIntegerPart + "." + binaryDecimalPart;
}

QString Converter::decimalPartToBinary(double decimalPart)
{
    QString binaryDecimalPart;
    while (decimalPart != 0.0)
    {
        decimalPart *= 2;
        int bit = int(decimalPart);
        decimalPart -= bit;
        binaryDecimalPart.append(QString::number(bit));
    }
    return binaryDecimalPart;
    
}
