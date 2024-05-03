#include "binarynumbersystem.h"
#include <QDebug>

BinaryNumberSystem::BinaryNumberSystem() {}

QString BinaryNumberSystem::intToBinary(long double number)
{
    if(number == 1)
    {
        return "1";
    }
    if(number == 0)
    {
        return "0";
    }
    return (intToBinary(floor(number / 2)) + QString::number(fmod(number, 2)));
}

QString BinaryNumberSystem::doubleToBinary(long double number, int iteration)
{
    if(iteration == 53)
    {
        return "";
    }

    if(number == 1)
    {
        return "10";
    }
    else
    {
        if((long long)(number) == 1)
        {
            number--;
            return ("1" + doubleToBinary(number * 2, iteration + 1));
        }
        else
        {
            return ("0" + doubleToBinary(number * 2, iteration + 1));
        }
    }
}

QString BinaryNumberSystem::toBinary(long double number)
{
    bool isNegative = false;

    QString resultBinNum;

    if(number < 0)
    {
        isNegative = true;
        number = -number;
    }

    QString integerPart = intToBinary(floor(number));

    long double doublePartInDouble = number - (long long)(number);

    QString doublePart = doubleToBinary(2 * doublePartInDouble, 1);

    int exponent = 0;

    while(integerPart.size() > 0 && integerPart[0] == '0')
    {
        integerPart.removeAt(0);
    }

    if(integerPart.size() > 0 && integerPart[0] == '1') exponent = integerPart.size() - 1;
    else
    {
        for(int i = 0; i < doublePart.size(); i++)
        {
            if(doublePart[i] == '1')
            {
                exponent = -(i + 1);
                break;
            }
        }
    }


    QString mantissa = integerPart + doublePart;

    while(mantissa.size() > 0 && mantissa[0] == '0')
    {
        mantissa.removeAt(0);
    }

    mantissa.removeAt(0);

    while(mantissa.size() > 52)
    {
        mantissa.removeAt(mantissa.size() - 1);
    }
    while(mantissa.size() < 52)
    {
        mantissa += "0";
    }

    QString exp = intToBinary(exponent + 1023);

    while(exp.size() < 11)
    {
        exp = "0" + exp;
    }

    if(isNegative)
    {
        resultBinNum = "1";
    }
    else
    {
        resultBinNum = "0";
    }

    resultBinNum += exp + mantissa;

    return resultBinNum;
}
