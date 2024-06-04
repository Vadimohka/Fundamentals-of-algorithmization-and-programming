#include "translation.h"

#include <QDebug>

Translation::Translation() = default;

QString Translation::int_to_bin(int n) {
    if (n == 0){
        return "0";
    }
    else{
        return int_to_bin(n / 2) + QString::number(n % 2);
    }
}

QString Translation::double_to_bin(double d, int mantiss) {
    if (mantiss == 0) {
        return "";
    }
    else{
        return QString::number(static_cast<int>(d * 2)) + double_to_bin(d * 2 - static_cast<int>(d * 2), mantiss - 1);
    }
}

QString Translation::TranslationToIEEE754(double value)
{
    int integer_part = static_cast<int>(value);
    double fractional_part = value - integer_part;

    QString answer = int_to_bin(integer_part) + "." + double_to_bin(fractional_part);
    qDebug() << answer;
    return answer;
}
