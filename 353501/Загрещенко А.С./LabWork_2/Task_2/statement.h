#ifndef STATEMENT_H
#define STATEMENT_H

#include "QString"

class Statement
{
public:
    Statement(int count, int price, QString model, QString name, int code, QString group);
    int getCount() const;

    void setCount(int newCount);

    int getPrice() const;

    void setPrice(int newPrice);

    QString getModel() const;

    void setModel(const QString& newModel);

    QString getName() const;

    void setName(const QString& newName);

    int getCode() const;

    void setCode(int newCode);

    QString getGroup() const;

    void setGroup(const QString& newGroup);

private:
    int count;
    int price;
    QString model;
    QString name;
    int code;
    QString group;



};

#endif // STATEMENT_H
