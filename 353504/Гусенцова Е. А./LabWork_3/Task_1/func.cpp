#include "func.h"

QString convertToBinary(double num, QString& binaryString, int precision) {
    // Convert the string to a double
    QString numStr;
    num = numStr.toDouble();

    bool isNegative = num < 0;
    num = std::fabs(num);

    int intPart = static_cast<int>(num);
    while (intPart > 0) {
        binaryString.prepend(QString::number(intPart % 2));
        intPart /= 2;
    }

    binaryString.append('.');

    double fracPart = num - static_cast<int>(num);
    while (precision > 0) {
        fracPart *= 2;
        binaryString.append(QString::number(static_cast<int>(fracPart)));
        fracPart -= static_cast<int>(fracPart);
        precision--;
    }

    if (isNegative) {
        binaryString.prepend('-');
    }

    return binaryString;
}
