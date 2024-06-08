#include "validator.h"

QValidator::State My_validator::validate(QString &input, int &pos) const
{
    int start = 0;
    if (!input.isEmpty() && input[0] == '-') {
        start = 1;
    }

    if (input.length() > 15) {
        return Invalid;
    }
    for (int i = start; i < input.length(); i++) {
        if (input[i] < '1' || input[i] > '9') {
            return Invalid;
        }
    }

    return Acceptable;
}
