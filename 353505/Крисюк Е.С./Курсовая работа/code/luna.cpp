#include "luna.h"

Luna::Luna()
{

}

QString Luna::GetNumber(QString str){

    int luna_number = 10 - Number(str) % 10;

    QString result = QString::number(luna_number);

    return result;

}

bool Luna::Is_Normal(QString str){
    return Number(str) % 10 == 0;
}

int Luna::Number(QString str){
    str.remove(' ');

    int result = 0;

    int temp;
    QChar temp_char;

    for(int i = 0; i < str.length(); ++i){

        temp_char = str[i];
        temp = temp_char.digitValue();

        if(i % 2 == 0){

            temp *= 2;

            if(temp > 9){
                temp -= 9;
            }

        }

        result += temp;
    }
    return result;
}
