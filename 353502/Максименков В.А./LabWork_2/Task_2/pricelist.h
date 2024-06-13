#ifndef PRICELIST_H
#define PRICELIST_H
#include <QVector>
#include <QDebug>

class PriceList
{
private:
    int number = 0;
    QVector<int> code;
    QVector<double> price;
    QVector<QString> name;

public:
    PriceList();
    void add(int code, double price, QString name);
    void correct(int row,int code, double price, const QString& name);
    void del(int row);
    QVector<int> getCode() const;
    int getNumber() const;
    QVector<double> getPrice() const;
    QVector<QString> getName() const;
    void codeSort();
    void priceSort();
};

#endif // PRICELIST_H
