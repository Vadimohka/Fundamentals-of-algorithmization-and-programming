#ifndef ORDER_H
#define ORDER_H
#include <QString>
class Order
{
public:
    Order(int _num, int _table, QString _dish, int _count);

    Order(QString);

    //void change(int _table, QString _dish, int _num);
    int num;

    int table;

    QString dish;

    int count;
};

#endif // ORDER_H
