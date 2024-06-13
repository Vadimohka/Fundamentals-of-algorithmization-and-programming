#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QObject>
#include <QGraphicsItem>
#include "Figures/figure.h"

class Rectangle : public Figure
{
    Q_OBJECT

public:
    explicit Rectangle(QPointF point, QObject *parent = 0);
    ~Rectangle();
    long double GetArea();
    long double GetPerimeter();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // RECTANGLE_H
