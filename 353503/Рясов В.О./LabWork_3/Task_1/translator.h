#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QString>

class Translator
{
    static QString _translate(int num);
public:
    Translator();
    static QString Translate(double num);
};

#endif // TRANSLATOR_H
