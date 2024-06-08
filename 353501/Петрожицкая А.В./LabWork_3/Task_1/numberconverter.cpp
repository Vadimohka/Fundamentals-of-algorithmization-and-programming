#include "numberconverter.h"

QString NumberConverter::decimalToBinary(double number, long long precision)
{
    if (precision == 0)
        return QString();

    long long wholePart = static_cast<long long>(number);
    double fractionalPart = number - wholePart;

    QString binary = QString::number(wholePart, 2);

    if (fractionalPart > 0)
    {
        binary.append('.');
        while (fractionalPart > 0 && precision > 0)
        {
            fractionalPart *= 2;
            long long bit = static_cast<long long>(fractionalPart);
            binary.append(QString::number(bit));
            fractionalPart -= bit;
            precision--;
        }
    }

    return binary;
}
