#ifndef SHOES_H
#define SHOES_H
#include <QString>

struct Shoes{
    int amount;
    double price;
    char gender;
    bool inStock;
    static constexpr char materials[]= {'l', 's', 'v', 'c', 'r'};
    static constexpr int sizes[] = {36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47};
    static QString getMaterialsString() {
        QString materialsStr;
        for (char material : materials) {
            materialsStr += material;
            materialsStr += " ";
        }
        return materialsStr.trimmed();
    }

    static QString getSizesString() {
        QString sizesStr;
        for (int size : sizes) {
            sizesStr += QString::number(size);
            sizesStr += " ";
        }
        return sizesStr.trimmed();
    }
};

#endif // SHOES_H
