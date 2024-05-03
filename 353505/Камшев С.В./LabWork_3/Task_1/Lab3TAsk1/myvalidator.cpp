#include "myvalidator.h"

myValidator::myValidator() {}

QValidator::State myValidator::validate(QString &input, int &pos) const
{
    if (input.contains('.')){
        if (input.count('.') > 1) return QValidator::Invalid;
        QStringList toPointList = input.split('.');
        if (toPointList[0].size() > 0 && toPointList[0].size() <= 300){
            for (int i = 0; i < toPointList[0].size(); ++i){
                if (!toPointList[0][i].isDigit()) return QValidator::Invalid;
            }
        }
        else return QValidator::Invalid;

        if (toPointList[1].size() <= 200){
            for (int i = 0; i < toPointList[1].size(); ++i){
                if (!toPointList[1][i].isDigit()) return QValidator::Invalid;
            }
        }
        else return QValidator::Invalid;

        return QValidator::Acceptable;
    }
    else{
        if (input.size() <= 300){
            for (int i = 0; i < input.size(); ++i){
                if (!input[i].isDigit()) return QValidator::Invalid;
            }
            return QValidator::Acceptable;
        }
        else return QValidator::Invalid;
    }
}
