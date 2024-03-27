#include "product.h"

Product::Product(QString code, QString name, double price, int quantity)
    : code(code), name(name), price(price), quantity(quantity) {}

QString Product::getCode() const {
    return code;
}

QString Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantity;
}
