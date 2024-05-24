#include "translate.h"

Translate::Translate() {}

QString Translate::TranslateToBin(long double numb){
    QString ans = "";
    bool minus = 0;
    if (numb < 0) {
        numb *= -1;
        minus = 1;
    }

    ans += TranslateIntPart(static_cast<long long>(numb));
    ans += '.';
    ans += TranslateFracPart(numb - static_cast<long long>(numb), 50);

    if(minus){
        return '-' + ans;
    }
    return ans;
}

QString Translate::TranslateIntPart(long long intPart){
    if(intPart == 0) return "0";
    if(intPart == 1) return "1";
    return TranslateIntPart(intPart / 2) + QString::number(intPart % 2);
}

QString Translate::TranslateFracPart(long double fracPart, int limit){
    if(fracPart == 0 || limit == 0) return "";
    fracPart *= 2;
    int bit = static_cast<int>(fracPart);
    return QString::number(bit) + TranslateFracPart(fracPart - bit, limit - 1);
}
