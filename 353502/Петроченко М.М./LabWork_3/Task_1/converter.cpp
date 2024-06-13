#include "converter.h"
#include <cmath>

QString Converter::llToBin(int64_t num) {
    if (num == 0) {
        return "0";
    }
    if (num / 2 == 0) {
        return (num % 2 == 0) ? "0" : "1";
    }
    return llToBin(num / 2) + ((num % 2 == 0) ? "0" : "1");
}

QString Converter::ldToBin(long double num) {
    if (std::isinf(num)) {
        return "";
    }
    if (num < LD_PRECISION_FLOOR) {
        return "";
    }
    num *= 2;
    QString res = "0";
    if (num >= 1) {
        res = "1";
        --num;
    }
    if (num < LD_PRECISION_FLOOR) {
        return res;
    }
    return res + ldToBin(num);
}

QString Converter::toBin(long double num) {
    bool negative = num < 0;
    QString sign = "0";
    if (negative) {
        num *= -1;
        sign = "1";
    }

    int64_t integer_part = static_cast<int64_t>(num);
    long double fractional_part = num - integer_part;
    QString integer_string = llToBin(integer_part);
    QString fractional_string = ldToBin(fractional_part);
    int32_t index = integer_string.indexOf("1");
    QString exponent =
        llToBin((integer_string.length() - 1 - index) + USHRT_MAX);
    QString mantissa;
    for (size_t i = index; i < integer_string.length(); ++i) {
        mantissa.push_back(integer_string.at(i));
    }
    mantissa = mantissa.leftJustified(64, '0');
    mantissa.chop(mantissa.size() - 63);
    return sign + exponent + mantissa;
}