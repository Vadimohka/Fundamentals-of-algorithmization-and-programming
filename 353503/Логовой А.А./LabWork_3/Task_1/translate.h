#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <QString>
#include <magicnumber.h>

void signNum(double &number, QString &string);

void fracSecond(double frac, QString &string, int precision  = EIGHT);

void intSecond(double number, QString& string);

#endif // TRANSLATE_H
