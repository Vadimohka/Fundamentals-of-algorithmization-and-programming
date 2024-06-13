#ifndef GOODSINORDERS_H
#define GOODSINORDERS_H
#include <QMap>

class GoodsInOrders
{
private:
    QMap<int, int> m;

public:
    GoodsInOrders();
    void add(int code, int quantity);
    QMap<int, int> getM() const;
};

#endif // GOODSINORDERS_H
