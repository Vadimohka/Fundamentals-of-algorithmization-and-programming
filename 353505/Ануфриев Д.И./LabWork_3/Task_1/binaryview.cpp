#include "binaryview.h"
#include "qdebug.h"

BinaryView::BinaryView() {}

QString BinaryView::toIntBinary(long double number)
{
    if(number == 1) return "1";
    if(number == 0) return "0";
    QString binaryNumber = "";

    qDebug() << fmod(number, 2);

    // return (toIntBinary(number / 2) + QString::number(number % 2));
    return (toIntBinary(floor(number / 2)) + QString::number(fmod(number, 2)));



}

QString BinaryView::toDoublePartBinary(long double number, int iteration)
{
    if(iteration == 53) return "";
    if(number == 1) return "10";
    else
    {
        if((long long)(number) == 1)
        {
            number--;
            return ("1" + toDoublePartBinary(number * 2, iteration + 1));
        }
        else return ("0" + toDoublePartBinary(number * 2, iteration + 1));
    }
}

QString BinaryView::toBinary(long double number)
{
    bool isInteger = false;
    bool isNegative = false;

    QString resultBinNum;

    if(number < 0)
    {
        isNegative = true;
        number = -number;
    }

    // if((long long)(number) == number) isInteger = true;

    // if(isInteger)
    // {
    //     resultBinNum = toIntBinary(number);

    //     if(isNegative)
    //     {
    //         resultBinNum = "1," + resultBinNum;
    //     }
    //     else
    //     {
    //         resultBinNum = "0," + resultBinNum;
    //     }
    // }

    // else
    {
        QString integerPart = toIntBinary(floor(number));

        long double doublePartInDouble = number - (long long)(number);

        QString doublePart = toDoublePartBinary(2 * doublePartInDouble, 1);

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

        while(mantissa.size() > 52) mantissa.removeAt(mantissa.size() - 1);
        while(mantissa.size() < 52) mantissa += "0";

        QString exp = toIntBinary(exponent + 1023);

        while(exp.size() < 11) exp = "0" + exp;

        if(isNegative) resultBinNum = "1";
        else resultBinNum = "0";

        resultBinNum += exp + mantissa;
    }

    return resultBinNum;
}
