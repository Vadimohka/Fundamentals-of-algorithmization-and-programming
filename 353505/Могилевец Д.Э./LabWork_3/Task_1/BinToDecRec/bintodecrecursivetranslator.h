#ifndef BINTODECRECURSIVETRANSLATOR_H
#define BINTODECRECURSIVETRANSLATOR_H

#include <QString>

class BinToDecRecursiveTranslator
{
public:
    BinToDecRecursiveTranslator();

    QString TranslateToIEEE754(long double);
    QString TranslateToDotBin(long double);
private:
    QString intPartToBin(long double);
    QString fracPartToBin(long double, QString);
};

#endif // BINTODECRECURSIVETRANSLATOR_H
