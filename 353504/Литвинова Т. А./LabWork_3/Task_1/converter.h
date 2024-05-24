#ifndef CONVERTER_H
#define CONVERTER_H

#include <QString>

class Converter
{
public:
    QString decimalToBinary(double number);
    QString decimalToBinary(int number);

private:
    QString decimalPartToBinary(double decimalPart);
};

#endif // CONVERTER_H
