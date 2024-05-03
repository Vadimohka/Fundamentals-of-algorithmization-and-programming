#ifndef HEXAGON_H
#define HEXAGON_H

#include <QObject>
#include <QGraphicsItem>

#include "basicfigure.h"

class Hexagon : public BasicFigure
{
    Q_OBJECT
public:
    explicit Hexagon(QPointF point, QObject *parent = 0);
    ~Hexagon();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double area();
    double perimeter();
};

#endif // HEXAGON_H
