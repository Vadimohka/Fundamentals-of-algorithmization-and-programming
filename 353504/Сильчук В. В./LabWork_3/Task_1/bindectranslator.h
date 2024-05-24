#ifndef BINDECTRANSLATOR_H
#define BINDECTRANSLATOR_H

#include <QString>
#include <QtMath>


class Translator
{
    static auto _translateFDecTBin(quint64 decNumber) -> QString;

public:
    static auto TranslateFDecTBin(double decNumber, quint8 precision) -> QString;
};

#endif // BINDECTRANSLATOR_H
