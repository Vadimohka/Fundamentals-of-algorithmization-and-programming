#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QObject>
#include <QGraphicsItem>

#include "basicfigure.h"

class Rectangle : public BasicFigure
{
    Q_OBJECT
public:
    explicit Rectangle(QPointF point, QObject *parent = 0);
    ~Rectangle();

private:
    double area();
    double perimeter();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // RECTANGLE_H
