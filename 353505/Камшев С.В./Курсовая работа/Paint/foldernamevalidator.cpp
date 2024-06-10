#include "foldernamevalidator.h"

FolderNameValidator::FolderNameValidator() {}

QValidator::State FolderNameValidator::validate(QString &input, int &pos) const
{
    if (input.size() == 0) return QValidator::Invalid;
    for (int i = 0; i < input.size(); ++i){
        if (!input[i].isDigit() && !input[i].isLetter()) return QValidator::Invalid;
    }
    return QValidator::Acceptable;
}
