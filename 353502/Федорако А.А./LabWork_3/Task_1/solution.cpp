#include "solution.h"

Solution::Solution()
{

}

QString Solution::binaryRepresentation(double number) {
    long integerPartNumber = (long long)number;
    QString valueIntegerBinaryRepresentation = integerBinaryRepresentation(integerPartNumber);
    QString valueFractionalBinaryRepresentation = fractionalBinaryRepresentation(number - (double)integerPartNumber);
    if(valueFractionalBinaryRepresentation != "") {
        return valueIntegerBinaryRepresentation + '.' + valueFractionalBinaryRepresentation;
    }
    return valueIntegerBinaryRepresentation;
}

QString Solution::fractionalBinaryRepresentation(double fraction) {
    if(1.0 - fraction < 0.000001 || fraction < 0.000001 || numberOperationsFractionalBinaryRepresentation == 64) {
        return "";
    }
    else if(fraction * 2 - 1.0 > 0.0000001) {
        numberOperationsFractionalBinaryRepresentation++;
        return ((QString)"1" + fractionalBinaryRepresentation(2 * fraction - 1.0));
    }
    else {
        numberOperationsFractionalBinaryRepresentation++;
        return ((QString)"0" + fractionalBinaryRepresentation(2 * fraction));
    }
}

QString Solution::integerBinaryRepresentation(int number) {
    if(number == 0) return "";
    else if(number % 2 == 0) return QString("1") + integerBinaryRepresentation(number / 2);
    else return (QString)"0" + integerBinaryRepresentation(number / 2);
}
