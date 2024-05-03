#include <iostream>
#include "binaryConverter.h"

QString BinaryConverter::getSign() { return sign; }
QString BinaryConverter::getExponent() { return exponent; }
QString BinaryConverter::getMantissa() { return mantissa; }
QString BinaryConverter::getBinary() { return s_Value; }

BinaryConverter::BinaryConverter(double val){
    DoubleBits db;
    db.value = val;

    sign = QString::number(db.raw.sign);
    exponent = getBinaryString(db.raw.exponent, 11);
    mantissa = getBinaryString(db.raw.mantissa, 52);

    s_Value = sign + exponent + mantissa;
}

QString BinaryConverter::getBinaryString(unsigned long long n, int bits) {
    if (bits == 0) {
        return "";
    } else {
        return getBinaryString(n >> 1, bits - 1) + QString::number(n & 1);
    }
}
