#ifndef CONVERTER_H
#define CONVERTER_H

#include <QString>

class Converter
{
public:
    struct IEEE754{
        char sign = 0;
        char exponent[8]{};
        char mantisse[23]{};

        QString GetSigh(){
            return QString::number(sign);
        }
        QString GetExp(){
            QString ret = "";
            for(int i =0; i < 8; i++){
                ret += QString::number(exponent[i]);
            }
            return ret;
        }
        QString GetMantisse(){
            QString ret = "";
            for(int i =0; i < 23; i++){
                ret += QString::number(mantisse[i]);
            }
            return ret;
        }
    };

public:
    Converter() = delete;

    static QString IntToBinary(long long value);
    static IEEE754 ToIEEE754(float value);
};


#endif // CONVERTER_H
