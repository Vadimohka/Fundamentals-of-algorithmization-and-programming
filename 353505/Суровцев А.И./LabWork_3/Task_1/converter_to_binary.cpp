#include "converter_to_binary.h"

Converter_to_binary::Converter_to_binary() {}

QString Converter_to_binary::intToBin(long double left_number)
{
    if (left_number == 0.5) return "0";
    left_number /= 2;
    int plus = left_number - floor(left_number)  > 0.3;
    return left_number == 0 ? "" : intToBin(floor(left_number)) + QString::number(plus);
}

/*QString Converter_to_binary::strToBin(const QString &str)
{
    return n == 0 ? "" : strToBin(divideByTwo(str)) + QString::number(n % 2);
}*/

QString Converter_to_binary::intToFract(long double frac, QString res)
{
    if (!res.isEmpty() && res.size() > 1000){
        return res;
    }
    QString new_res = res + QString::number((int)(2 * frac));
    return intToFract(2 * frac - (int)(2 * frac), new_res);
}

int Converter_to_binary::goToOneComma(QString left, QString right)
{
    int ind = -1;
    for (int i = 0; i < left.size(); ++i) {
        if (left[i] == '1') {
            ind = i;
            break;
        }
    }
    if (ind != -1) return (left.size() - 1 - ind);
    for (int i = 0; i < right.size(); ++i) {
        if (right[i] == '1') {
            ind  = i;
            break;
        }
    }
    return (-ind - 1);
}

QString Converter_to_binary::_exponenta(int exp)
{
    int temp = 1023 + exp;
    QString res = intToBin(temp);
    if (res.size() < 11) {
        while(res.size() < 11) {
            res = "0" + res;
        }
    }
    return res;
}

QString Converter_to_binary::solve(long double n)
{
    QString znak = (n >= 0 ? "0" : "1");
    if (n == 0) {
        QString zero_res = "";
        for (int i = 0; i < 64; ++i) {
            zero_res += "0";
        }
        return zero_res;
    }
    else if (n < 0) n *= -1;
    long double temp = floor(n);
    long double frac = n - floor(n);
    QString left = intToBin(temp);
    QString right = intToFract(frac, "");
    int res = goToOneComma(left, right);
    QString exponenta = _exponenta(res);
    QString mantisa = retMantisa(left, right);
    return znak + exponenta + mantisa;
}

QString Converter_to_binary::retMantisa(QString left, QString right)
{
    int ind = -1;
    for (int i = 0; i < left.size(); ++i) {
        if (left[i] == '1') {
            ind = i;
            break;
        }
    }
    if (ind != -1) {
        QString result_string = "";
        for (int i = ind + 1; i < left.size(); ++i) {
            result_string += left[i];
        }
        for (int i = 0; i < right.size(); ++i) {
            result_string += right[i];
        }
        while (result_string.size() < 52) {
            result_string += "0";
        }
        while (result_string.size() > 52){
            result_string.erase(result_string.end() - 1);
        }
        return result_string;
    }
    for (int i = 0; i < right.size(); ++i) {
        if (right[i] == '1') {
            ind  = i;
            break;
        }
    }
    if (ind != -1) {
        QString result_string = "";
        for (int i = ind + 1; i < right.size(); ++i) {
            result_string += right[i];
        }
        while (result_string.size() < 52) {
            result_string += "0";
        }
        while (result_string.size() > 52){
            result_string.erase(result_string.end() - 1);
        }
        return result_string;
    }
}

QString Converter_to_binary::divideByTwo(const QString &numStr)
{
    QString result;
    int carry = 0;
    for (QChar digit : numStr) {
        int currentDigit = digit.digitValue();
        int quotient = (carry * 10 + currentDigit) / 2;
        result.append(QString::number(quotient));
        carry = (carry * 10 + currentDigit) % 2;
    }
    result = result.trimmed();
    if (result.isEmpty()) {
        result = "0";
    }
    return result;
}

