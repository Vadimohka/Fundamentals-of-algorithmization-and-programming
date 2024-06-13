#include "goodsinorders.h"

QMap<int, int> GoodsInOrders::getM() const
{
    return m;
}

GoodsInOrders::GoodsInOrders() {}

void GoodsInOrders::add(int code, int quantity)
{
    m[code] = quantity;
}


