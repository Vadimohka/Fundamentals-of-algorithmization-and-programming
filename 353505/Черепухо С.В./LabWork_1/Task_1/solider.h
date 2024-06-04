#ifndef SOLIDER_H
#define SOLIDER_H

#include "movingrect.h"

class Solider : public movingRect
{
public:
    Solider();
    void salute();

    int hdy = 0, adh = 0, ady = 0;

    short counter = 0;

    bool st;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // SOLIDER_H
