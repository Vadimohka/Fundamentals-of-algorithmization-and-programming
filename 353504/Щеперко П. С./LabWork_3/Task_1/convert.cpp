#include "convert.h"

void Convert::Reverse(QString &str)
{
    std::string buffer = str.toStdString();
    std::reverse(buffer.begin(), buffer.end());
    str = QString::fromStdString(buffer);
}

QString Convert::ConvertIntToBinary(QString intPart, QString &binaryForm)
{
    if (intPart == "1" || intPart == "0") {
        QPair<QString, QString> quotientAndRemain = BigInt::DivisionBy2(intPart);
        binaryForm.push_back(quotientAndRemain.second);
        return 0;
    }
    for (int i = 0; intPart.at(i) == '0' && i < intPart.size(); ++i) {
        intPart.remove(i,1);
        --i;
    }
    QPair<QString, QString> quotientAndRemain = BigInt::DivisionBy2(intPart);
    binaryForm.push_back(quotientAndRemain.second);
    return ConvertIntToBinary(quotientAndRemain.first, binaryForm);
}

QString Convert::ConvertFractionToBinary(QString decimalFraction, QString &binaryFraction)
{
    if (binaryFraction.size() >= 1023)
        return 0;
    if(decimalFraction == "0.")
        return 0;
    QPair<QString, QString> multAndRemain = BigInt::MultipicationBy2(decimalFraction);
    binaryFraction.push_back(multAndRemain.second);
    return ConvertFractionToBinary(multAndRemain.first, binaryFraction);
}

QString Convert::ConvertDoubleToBinary(QString realNumber)
{
    QString IEEE754 = "";
    if (realNumber.contains('-')) {
        IEEE754 += "1";
        realNumber.remove(0, 1);
    } else {
        IEEE754 += "0";
    }
    QString intPart;
    QString decimalFraction;

    std::string stdRealNum = realNumber.toStdString();
    qint16 pointPos = stdRealNum.find(".");
    if (realNumber.indexOf('.') != -1) {
        intPart = realNumber.sliced(0, pointPos);
        decimalFraction = realNumber.sliced(pointPos + 1);
    } else {
        intPart = realNumber;
        decimalFraction = "0";
    }
    QString binaryForm = "";
    Convert::ConvertIntToBinary(intPart, binaryForm);
    Reverse(binaryForm);
    binaryForm.push_back('.');
    decimalFraction.insert(0, "0.");
    Convert::ConvertFractionToBinary(decimalFraction, binaryForm);
    qint32 intExponent = 0;
    if (binaryForm.indexOf('1') == -1) {
        IEEE754 += "000000000000000000000000000000000000000000000000000000000000000";
        return IEEE754;
    }
    if (binaryForm.at(0) == '0') {
        intExponent = binaryForm.indexOf('1') - binaryForm.indexOf('.');
        binaryForm.remove(1, 1);
        binaryForm.insert(intExponent + 1, '.');
        intExponent = 1023 - intExponent;
    } else {
        intExponent = binaryForm.indexOf('.') - 1;
        pointPos = binaryForm.indexOf('.');
        binaryForm.remove(pointPos, 1);
        binaryForm.insert(pointPos - intExponent, '.');
        intExponent += 1023;
    }
    if (intExponent >= 2048 || intExponent < 0) {
        IEEE754 += "111111111110000000000000000000000000000000000000000000000000000";
        return IEEE754;
    }
    for (int i = 0; binaryForm.at(i) == '0' && i < binaryForm.size(); ++i) {
        binaryForm.remove(i,1);
        --i;
    }
    if (binaryForm.size() < 54) {
        std::string stdBinaryForm = binaryForm.toStdString();
        stdBinaryForm.insert(stdBinaryForm.size(), 54 - stdBinaryForm.size(), '0');
        binaryForm = QString::fromStdString(stdBinaryForm);
    } else if (binaryForm.at(54) == '1') {
        binaryForm.resize(54);
        Reverse(binaryForm);
        for (int i = 0; i < binaryForm.size(); ++i) {
            if (binaryForm.at(i) == '1') {
                binaryForm.replace(i, 1, "0");
            } else if (binaryForm.at(i) == '.') {
                ++intExponent;
                break;
            } else {
                binaryForm.replace(i, 1, "1");
                break;
            }
        }
        Reverse(binaryForm);
    } else {
        binaryForm.resize(54);
    }
    QString decimalExponent = QString::number(intExponent);
    binaryForm.remove(0, 2);
    QString exponent;
    ConvertIntToBinary(decimalExponent, exponent);
    Reverse(exponent);
    if (exponent.size() < 11) {
        std::string stdExponent = exponent.toStdString();
        stdExponent.insert(0, 11 - stdExponent.size(), '0');
        exponent = QString::fromStdString(stdExponent);
    }
    IEEE754 += exponent;
    IEEE754 += binaryForm;
    return IEEE754;
}


