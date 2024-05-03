#ifndef HEXAGON_H
#define HEXAGON_H


#include "figure.h"

class Hexagon :  public Figure
{

public:
    explicit Hexagon(QPointF point);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // HEXAGON_H
