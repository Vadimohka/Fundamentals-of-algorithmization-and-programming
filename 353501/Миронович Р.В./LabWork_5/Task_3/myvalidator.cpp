#include "myvalidator.h"

MyValidator::MyValidator() {}

QValidator::State MyValidator::validate(QString &input, int &pos) const
{
    if (input.size() > 32) return QValidator::Invalid;
    for (auto& i: input){
        if (i != '1' && i != '0') return QValidator::Invalid;
    }
    return QValidator::Acceptable;
}
