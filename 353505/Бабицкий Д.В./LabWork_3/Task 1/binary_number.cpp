#include "binary_number.h"

Binary_number::Binary_number() {}

QString Binary_number::convert_to_binary(long double number) {
    if (number == 0) {
        return "0";
    }
    if (number == 1) {
        return "1";
    }
    QString binary;
    long long integer_part = (long long) number;
    binary = binary + QString::number(integer_part,2);
    int accuracy = 10;   //точность
    if (accuracy > 0) {
        binary = binary + ".";
        long double fraction_part = number - integer_part;
        long double number_of_digits = 0; //кол-во цифр
        while (fraction_part > 0 && number_of_digits < accuracy) {
            fraction_part = fraction_part * 2;
            long long b = fraction_part;
            binary = binary + QString::number(b);
            fraction_part = fraction_part - b;
            number_of_digits++;
        }
    }
    return binary;
}
