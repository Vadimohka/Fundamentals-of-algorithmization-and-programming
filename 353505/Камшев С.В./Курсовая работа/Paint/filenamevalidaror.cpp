#include "filenamevalidaror.h"

FileNameValidaror::FileNameValidaror() {}

QValidator::State FileNameValidaror::validate(QString &input, int &pos) const
{
    if (input.contains(".png")){
        if (input.count(".") != 1) return QValidator::Invalid;
        if (input.indexOf(".") != input.size() - 4) return QValidator::Invalid;
        if (input.size() <= 4) return QValidator::Invalid;
        QStringList list = input.split(".png");
        for (int i = 0; i < list[0].size(); ++i){
            if (!list[0][i].isDigit() && !list[0][i].isLetter()) return QValidator::Invalid;
        }
        return QValidator::Acceptable;
    }
    else return QValidator::Invalid;
}
