#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>

class Product{
private:
    QString group;
    QString code;
    QString name;
    QString model;
    double cost;
    int count;

public:
    Product();
    Product(QString group, QString code, QString name, QString model, double cost, int count)
        : group(group), code(code), name(name), model(model), cost(cost), count(count) {}
    Product(const QString& line);
    QString ToString();

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
};

#endif // PRODUCT_H
