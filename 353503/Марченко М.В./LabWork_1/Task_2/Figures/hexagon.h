#ifndef HEXAGON_H
#define HEXAGON_H

#include <QObject>
#include <QGraphicsItem>
#include "Figures/figure.h"

class Hexagon : public Figure
{
    Q_OBJECT

public:
    explicit Hexagon(QPointF point, QObject *parent = 0);
    ~Hexagon();
    long double GetArea();
    long double GetPerimeter();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // HEXAGON_H
