#include "decimaltobinary.h"

DecimalToBinary::DecimalToBinary(QObject *parent) : QObject(parent) {}

QString DecimalToBinary::convert(const QString& decimal) {
    // Переводим строку в число
    double num = decimal.toDouble();
    if (num == 0) {
        return "0";
    }
    // Выделяем целую и дробную части
    int intPart = static_cast<int>(num);
    double fractionalPart = num - intPart;
    // QString stringFractionalPart = QString::number(fractionalPart);
    // int count = stringFractionalPart.length()-1;
    // if (count >= 1){
    //     for (int i = 1; i < count; i++){
    //         fractionalPart*=10;
    //     }
    // }
    // Преобразуем целую и дробную части в двоичные строки

    QString binaryIntPart = convertIntegerPart(intPart, fractionalPart);
    QString binaryFractionalPart="";
    if(fractionalPart != 0){
        binaryFractionalPart = convertFractionalPart(fractionalPart, 64); 
    }

    QString result = binaryIntPart;
    if (!binaryFractionalPart.isEmpty()) {
        result += '.' + binaryFractionalPart;
    }

    return result;
}

QString DecimalToBinary::convertIntegerPart(int intPart, int fractionalPart) {
    if (intPart == 0 && fractionalPart != 0) {
        return "0";
    }
    
    // Рекурсивно конвертируем целую часть
    QString binary;
    if (intPart > 0) {
        binary = convertIntegerPart(intPart / 2, fractionalPart) + QString::number(intPart % 2);
    }
    return binary;
}

QString DecimalToBinary::convertFractionalPart(double fractionalPart, int maxFractionalDigits) {
    // Останавливаем рекурсию, когда дробная часть становится нулевой
    if (maxFractionalDigits == 0) {
        return "";
    }

    // Умножаем на 2 и обрабатываем следующий бит
    fractionalPart *= 2;
    if (fractionalPart >= 1) {
        // Если текущий бит равен 1, добавляем его к результату и рекурсивно вызываем функцию для следующего бита
        return '1' + convertFractionalPart(fractionalPart - 1, maxFractionalDigits - 1);
    } else {
        // Если текущий бит равен 0, просто рекурсивно вызываем функцию для следующего бита
        return '0' + convertFractionalPart(fractionalPart, maxFractionalDigits - 1);
    }
}



