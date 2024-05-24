#include "Converter.h"


QString Converter::IntToBinary(long long value){
    if(value < 0){
        return "-" + IntToBinary(-value);
    }
    else{
        if(value == 0){
            return "";
        }
        else{
            return IntToBinary(value / 2) + QString::number(value % 2);
        }
    }
}

Converter::IEEE754 Converter::ToIEEE754(float value){
    IEEE754 ret;

    if(value < 0){
        ret.sign = 1;
    }

    if(*(unsigned int*)&value & 0b01000000000000000000000000000000U) ret.exponent[0] = 1;
    if(*(unsigned int*)&value & 0b00100000000000000000000000000000U) ret.exponent[1] = 1;
    if(*(unsigned int*)&value & 0b00010000000000000000000000000000U) ret.exponent[2] = 1;
    if(*(unsigned int*)&value & 0b00001000000000000000000000000000U) ret.exponent[3] = 1;
    if(*(unsigned int*)&value & 0b00000100000000000000000000000000U) ret.exponent[4] = 1;
    if(*(unsigned int*)&value & 0b00000010000000000000000000000000U) ret.exponent[5] = 1;
    if(*(unsigned int*)&value & 0b00000001000000000000000000000000U) ret.exponent[6] = 1;
    if(*(unsigned int*)&value & 0b00000000100000000000000000000000U) ret.exponent[7] = 1;

    if(*(unsigned int*)&value & 0b00000000010000000000000000000000U) ret.mantisse[0] = 1;
    if(*(unsigned int*)&value & 0b00000000001000000000000000000000U) ret.mantisse[1] = 1;
    if(*(unsigned int*)&value & 0b00000000000100000000000000000000U) ret.mantisse[2] = 1;
    if(*(unsigned int*)&value & 0b00000000000010000000000000000000U) ret.mantisse[3] = 1;
    if(*(unsigned int*)&value & 0b00000000000001000000000000000000U) ret.mantisse[4] = 1;
    if(*(unsigned int*)&value & 0b00000000000000100000000000000000U) ret.mantisse[5] = 1;
    if(*(unsigned int*)&value & 0b00000000000000010000000000000000U) ret.mantisse[6] = 1;
    if(*(unsigned int*)&value & 0b00000000000000001000000000000000U) ret.mantisse[7] = 1;
    if(*(unsigned int*)&value & 0b00000000000000000100000000000000U) ret.mantisse[8] = 1;
    if(*(unsigned int*)&value & 0b00000000000000000010000000000000U) ret.mantisse[9] = 1;
    if(*(unsigned int*)&value & 0b00000000000000000001000000000000U) ret.mantisse[10] = 1;
    if(*(unsigned int*)&value & 0b00000000000000000000100000000000U) ret.mantisse[11] = 1;
    if(*(unsigned int*)&value & 0b00000000000000000000010000000000U) ret.mantisse[12] = 1;
    if(*(unsigned int*)&value & 0b00000000000000000000001000000000U) ret.mantisse[13] = 1;
    if(*(unsigned int*)&value & 0b00000000000000000000000100000000U) ret.mantisse[14] = 1;
    if(*(unsigned int*)&value & 0b00000000000000000000000010000000U) ret.mantisse[15] = 1;
    if(*(unsigned int*)&value & 0b00000000000000000000000001000000U) ret.mantisse[16] = 1;
    if(*(unsigned int*)&value & 0b00000000000000000000000000100000U) ret.mantisse[17] = 1;
    if(*(unsigned int*)&value & 0b00000000000000000000000000010000U) ret.mantisse[18] = 1;
    if(*(unsigned int*)&value & 0b00000000000000000000000000001000U) ret.mantisse[19] = 1;
    if(*(unsigned int*)&value & 0b00000000000000000000000000000100U) ret.mantisse[20] = 1;
    if(*(unsigned int*)&value & 0b00000000000000000000000000000010U) ret.mantisse[21] = 1;
    if(*(unsigned int*)&value & 0b00000000000000000000000000000001U) ret.mantisse[22] = 1;

    return ret;
}
