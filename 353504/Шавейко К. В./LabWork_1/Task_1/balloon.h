#ifndef CART_H
#define CART_H

#include "movingellipse.h"

class balloon : public movingellipse
{
    Q_OBJECT

public:
    balloon(QObject *parent = nullptr);
};

#endif // CART_H
