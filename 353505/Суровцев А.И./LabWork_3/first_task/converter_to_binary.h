#ifndef CONVERTER_TO_BINARY_H
#define CONVERTER_TO_BINARY_H

#include <QString>

class Converter_to_binary
{
public:
    Converter_to_binary();
    QString solve(long double n);
private:
    QString intToBin(long double n);
    //QString strToBin(QString &str);
    QString intToFract(long double frac, QString res = "");
    int goToOneComma(QString left, QString right);
    QString _exponenta(int exp);
    QString retMantisa(QString left, QString right);
    QString divideByTwo(const QString& numStr);
};
#endif // CONVERTER_TO_BINARY_H
