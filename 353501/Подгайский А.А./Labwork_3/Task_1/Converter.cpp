#include "Converter.h"
#include <QTextStream>
#include <QDebug>
#include <cmath>

QPair<QString, QString> Converter::getBinIntAndFrac(long double num) {
    auto integ = std::floor(num);
    auto frac = num - integ;

    QString integS = toSimpleBin(integ);
    QString fracS = fracToBin(frac);
    return {integS, fracS};
}

QString Converter::toSimpleBin(long double num) {
    if(std::floor(num) == 0.L){
        return "";
    } 
    return toSimpleBin(num / 2.L) + QString::number( (int)std::fmodl(num, 2.L) );
}

QString Converter::fracToBin(long double num) {
    QString frac{};

    while(num != 0.0L && frac.size() < 1000){
        num *= 2;
        if(num > 1){
            frac += "1";
            num -= 1.0L;
        } else {
            frac += "0";
        }
    }

    return frac;
}

QString Converter::toIEE754(long double num) {
    bool isNeg = num < 0;
    QString signS = isNeg ? "1" : "0";

    num = std::abs(num);

    auto intAndFrac = getBinIntAndFrac(num);

    auto posOf1 = findFirst1Pos(intAndFrac);
    QString expS = toSimpleBin(posOf1 + EXP_BIAS);

    QString padExpS;
    QTextStream ts(&padExpS);
    ts.setFieldAlignment(QTextStream::AlignRight);
    ts << qSetFieldWidth(EXP_LEN) << qSetPadChar('0') << expS;
    
    QString mantS;
    {
        QString mergedIntFrac = intAndFrac.first + intAndFrac.second;
        auto ind = mergedIntFrac.indexOf('1');
        mantS = ind == -1 ? "" : mergedIntFrac.sliced(ind+1);
    }
    QString padMantS;
    ts.setString(&padMantS);
    ts.setFieldAlignment(QTextStream::AlignLeft);
    ts << qSetFieldWidth(MANT_LEN) << qSetPadChar('0') << mantS.left(MANT_LEN);
    
    qDebug() << padMantS.size();
    qDebug() << padExpS.size();

    return signS + " | " + padExpS + " | " + padMantS;
}

int Converter::findFirst1Pos(const QPair<QString, QString>& int_frac) {
    auto integ = int_frac.first;
    auto frac = int_frac.second;

    int exp = integ.indexOf('1');
    if(exp != -1){
        return integ.size() - exp - 1;
    }
    exp = frac.indexOf('1');
    if(exp != -1){
        return -exp - 1;
    }
    return 0;

}
