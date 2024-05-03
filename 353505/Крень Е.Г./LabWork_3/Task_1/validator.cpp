#include "validator.h"

Validator::Validator() {}

QValidator::State Validator::validate(QString inputData){
    QString beforePoint;
    QString behindPoint;
    QString beforeE;
    QString behindE;

    if(inputData.count('.') > 1 || inputData.count('e')>1)return QValidator::Invalid;

    if(inputData.contains('.')){

        beforePoint = inputData.split('.')[0];
        behindPoint = inputData.split('.')[1];

        if(!(beforePoint[0].isDigit()||beforePoint[0]=='+'||beforePoint[0]=='-'))return QValidator::Invalid;
        for(int i=1; i<beforePoint.size(); ++i){
            if(!(beforePoint[i].isDigit())) return QValidator::Invalid;
        }
        if(behindPoint.contains('e')){
            beforeE = behindPoint.split('e')[0];
            behindE = behindPoint.split('e')[1];
            if(!(behindE[0].isDigit()||behindE[0]=='+'||behindE[0]=='-'))return QValidator::Invalid;
            for(int i=1; i<behindE.size(); ++i){
                if(!(behindE[i].isDigit())) return QValidator::Invalid;
            }
        }else{
            beforeE = behindPoint;
        }
        for(int i=0; i<beforeE.size(); ++i){
            if(!(beforeE[i].isDigit())) return QValidator::Invalid;
        }
    }

    return QValidator::Acceptable;
}
