#ifndef CIRCLE_H
#define CIRCLE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Circle : public Figure
{
    Q_OBJECT

public:
    explicit Circle(QPointF point, QObject *parent = 0);
    ~Circle();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double area();
    double perimeter();
};

#endif // CIRCLE_H
