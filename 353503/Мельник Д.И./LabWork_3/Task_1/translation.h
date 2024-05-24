#ifndef TRANSLATION_H
#define TRANSLATION_H
#include <QString>

constexpr int DIGITS_IN_MANTISSA = 52;

class Translation
{
private:
    QString int_to_bin(int n);
    QString double_to_bin(double d, int mantiss = DIGITS_IN_MANTISSA);
public:
    Translation();
    QString TranslationToIEEE754(double value);
};

#endif // TRANSLATION_H
