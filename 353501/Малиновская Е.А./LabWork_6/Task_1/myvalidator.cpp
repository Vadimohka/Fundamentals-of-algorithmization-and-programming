#include "myvalidator.h"

MyValidator::MyValidator() {}

QValidator::State MyValidator::validate(QString &input, int &pos) const
{
    if (input.size() > 15) return QValidator::Invalid;
    if (input.size() > 0){
        if (input[0] == ' ') return QValidator::Invalid;
        if (input[pos - 1].isDigit() || input[pos - 1].toLatin1() != NULL) return QValidator::Acceptable;
    }

    return QValidator::Invalid;
}
