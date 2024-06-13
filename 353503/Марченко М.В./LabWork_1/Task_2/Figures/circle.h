#ifndef CIRCLE_H
#define CIRCLE_H

#include <QObject>
#include <QGraphicsItem>
#include "Figures/figure.h"

class Circle : public Figure
{
    Q_OBJECT

public:
    explicit Circle(QPointF point, QObject *parent = 0);
    ~Circle();
    long double GetArea();
    long double GetPerimeter();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // CIRCLE_H
