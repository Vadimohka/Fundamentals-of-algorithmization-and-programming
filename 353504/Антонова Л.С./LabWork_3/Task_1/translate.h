#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <QString>

class Translate{
public:
    Translate();

    QString TranslateToBin(long double numb);

    QString TranslateIntPart(long long intPart);
    QString TranslateFracPart(long double fracPart, int limit);
};

#endif // TRANSLATE_H
