#ifndef CONVERTER_H
#define CONVERTER_H
#include "QtCore/qstring.h"
#include <QPair>
class Converter
{
public:
    Converter();
    QPair<QString,QString> static getinteg_and_fact(QString);
    QString static toBinary_integ(long double);
    QString static toBinary_fact(long double);
    static QString toBinaryIEE754(QString);
};

#endif // CONVERTER_H
