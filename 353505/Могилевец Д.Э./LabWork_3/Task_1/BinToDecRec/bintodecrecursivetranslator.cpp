#include "bintodecrecursivetranslator.h"

BinToDecRecursiveTranslator::BinToDecRecursiveTranslator() {}

QString BinToDecRecursiveTranslator::TranslateToIEEE754(long double in)
{
    if (in == 0) return QString(80, '0');
    QString sign = in >= 0 ? "0" : "1";
    in = std::abs(in);
    QString intPartBin = intPartToBin(in);
    QString fracPartBin = fracPartToBin(in - floor(in), "");

    long long exp = 0;
    QString exponent;

    if (intPartBin == "0") {
        exp = -fracPartBin.indexOf('1') + 1023;
        exponent = intPartToBin(exp);
    }
    else {
        exp = intPartBin.size() + 1023;
        exponent = intPartToBin(exp);
    }

    QString badMantissa = intPartBin + fracPartBin;
    QString mantissa = "";
    bool was1 = false;
    for (auto c : badMantissa) {
        if (was1) mantissa += c;
        if (c == '1') was1 = true;
    }
    mantissa += QString(80, '0');

    return (sign + '.' + exponent + '.' + mantissa).first(64);
}

QString BinToDecRecursiveTranslator::TranslateToDotBin(long double in)
{
    if (in < 0) {
        in *= -1;
        return '-' + intPartToBin(in) + '.' + fracPartToBin(in - floor(in), "");
    }
    return intPartToBin(in) + '.' + fracPartToBin(in - floor(in), "");
}

QString BinToDecRecursiveTranslator::intPartToBin(long double intPart)
{
    if (intPart == 0.5) return "0";
    intPart /= 2;
    int plus = intPart - floor(intPart)  > 0.3;
    return intPart == 0 ? "" : intPartToBin(floor(intPart)) + QString::number(plus);
}

QString BinToDecRecursiveTranslator::fracPartToBin(long double fracPart, QString prevRes = "")
{
    if (!prevRes.isEmpty() && prevRes.size() > 3000) return prevRes;
    QString newPrevRes = prevRes + QString::number((int)(2 * fracPart));
    return fracPartToBin(2 * fracPart - floor(2 * fracPart), newPrevRes);
}
