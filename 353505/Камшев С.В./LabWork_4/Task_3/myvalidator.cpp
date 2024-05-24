#include "myvalidator.h"

MyValidator::MyValidator() {}

QValidator::State MyValidator::validate(QString &input, int &pos) const
{
    if (input.size() > 0){
        if (input.contains(',')){
            QStringList list = input.split(',');
            if(list[list.size() - 1] == "")list.pop_back();
            for (auto &i : list){
                if (i[0] != '0'){
                    for (auto &j: i){
                        if (!j.isDigit()) return QValidator::Invalid;
                    }
                    if (i.toInt() > 1000) return QValidator::Invalid;
                }
                else return QValidator::Invalid;
            }
            return QValidator::Acceptable;
        }
        else{
            if (input[0] != '0'){
                for (auto &j: input){
                    if (!j.isDigit()) return QValidator::Invalid;
                }
                if (input.toInt() > 1000) return QValidator::Invalid;
                return QValidator::Acceptable;
            }
            else return QValidator::Invalid;
        }
    }
    return QValidator::Acceptable;
}
