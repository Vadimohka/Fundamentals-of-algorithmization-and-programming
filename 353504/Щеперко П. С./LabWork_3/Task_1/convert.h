#ifndef CONVERT_H
#define CONVERT_H

#include <QtTypes>
#include <QString>
#include "bigint.h"

class Convert
{

public:
    static QString ConvertIntToBinary(QString  intPart, QString &binaryFraction);
    static QString ConvertFractionToBinary(QString  decimalFraction, QString &binaryFraction);
    static QString ConvertDoubleToBinary(QString realNumber);

private:
    static void Reverse(QString &str);
};

#endif // CONVERT_H
