#ifndef LISTOFORDERS_H
#define LISTOFORDERS_H
#include "goodsinorders.h"
#include <QVector>
#include <QDate>

class ListOfOrders
{
private:
    int number = 0;
    QVector<QDate> date;
    QVector<QString> name;

public:
    ListOfOrders();
    void add(const QDate &date, const QString &name, const GoodsInOrders &goods);
    void correct(int row, const QDate &date, const QString &name);
    void del(int row);
    QVector<QDate> getDate() const;
    QVector<QString> getName() const;
    QVector<GoodsInOrders> goods;
    QVector<GoodsInOrders> getGoods() const;
    int getNumber() const;
};

#endif // LISTOFORDERS_H
