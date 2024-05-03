#ifndef ROMB_H
#define ROMB_H

#include "figure.h"

class Romb : public Figure
{


public:
    explicit Romb(QPointF point);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // ROMB_H
