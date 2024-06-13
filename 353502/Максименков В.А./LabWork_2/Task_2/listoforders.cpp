#include "listoforders.h"

QVector<QDate> ListOfOrders::getDate() const
{
    return date;
}

QVector<QString> ListOfOrders::getName() const
{
    return name;
}

QVector<GoodsInOrders> ListOfOrders::getGoods() const
{
    return goods;
}

int ListOfOrders::getNumber() const
{
    return number;
}

ListOfOrders::ListOfOrders() {}


void ListOfOrders::add(const QDate& date, const QString& name, const GoodsInOrders& goods)
{
    this->date.push_back(date);
    this->name.push_back(name);
    this->goods.push_back(goods);
    ++number;
}


void ListOfOrders::correct(int row, const QDate &date, const QString &name)
{
    this->date[row-1] = date;
    this->name[row-1] = name;
}


void ListOfOrders::del(int row)
{
    date.removeAt(row-1);
    name.removeAt(row-1);
    goods.removeAt(row-1);
    --number;
}
