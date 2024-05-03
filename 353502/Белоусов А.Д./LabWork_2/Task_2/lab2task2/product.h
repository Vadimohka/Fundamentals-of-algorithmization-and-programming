#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include "convertibleinstance.h"
#include "group.h"

class Product : public ConvertibleInstance
{
private:
    Group* group{new Group};
    int64_t* code{new int64_t};
    QString* name{new QString};
    double* price{new double};
    int64_t* quantity{new int64_t};
public:
    Product();
    ~Product() override = default;
    Product(QString name, int64_t code, Group group, double price, int64_t quantity);
    Group* GetGroup();
    QString* GetName();
    int64_t* GetCode();
    int64_t* GetQuantity();
    double* GetPrice();
    void SetGroup(Group* group);
    void SetName(QString* name);
    void SetCode(int64_t* code);
    void SetQuantity(int64_t* quantity);
    void SetPrice(double* price);

    QString* ToQString() override;
    void FromQStringToInstance(QString* object) override;
};

#endif // PRODUCT_H
