#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"
#include <QPainter>

class hexagon : public figure
{
public:
    hexagon();
    ~hexagon();
    void initialization();
    int R,G,B,PenSize;
private:
    QVector<QPointF> hexagonPoints;
    double halfSideLength,apothem,angleRad;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // HEXAGON_H
