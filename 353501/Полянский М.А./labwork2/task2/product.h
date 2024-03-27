#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>

class Product {
public:
    Product(QString code, QString name, double price, int quantity);

    QString getCode() const;
    QString getName() const;
    double getPrice() const;
    int getQuantity() const;

private:
    QString code;
    QString name;
    double price;
    int quantity;
};

#endif // PRODUCT_H
