#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>

class Product
{
public:
    Product(QString group = "", QString code = "", QString name = "", QString model = "", double cst = 0, int cnt = 0);
    void SetGroup(QString to);
    void SetCode(QString to);
    void SetName(QString to);
    void SetModel(QString to);
    void SetCost(double to);
    void SetCount(int to);
    QString GetGroup() const;
    QString GetCode() const;
    QString GetName() const;
    QString GetModel() const;
    double GetCost() const;
    int GetCount() const;
private:
    QString group;
    QString code;
    QString name;
    QString model;
    double cost;
    int count;
};

#endif // PRODUCT_H
