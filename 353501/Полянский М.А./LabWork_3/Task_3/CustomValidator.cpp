#include "CustomValidator.h"

CustomValidator::CustomValidator(QObject *parent) : QValidator(parent) {}

QValidator::State CustomValidator::validate(QString &input, int &pos) const {
    Q_UNUSED(pos);
    
    if (input.isEmpty() || input.contains('0'))
        return Invalid;
    else {
        bool ok;
        input.toLongLong(&ok);
        if (ok)
            return Acceptable;
        else
            return Invalid;
    }
}
