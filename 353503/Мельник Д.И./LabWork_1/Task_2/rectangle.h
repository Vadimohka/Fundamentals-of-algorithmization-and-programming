#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Rectangle : public Figure
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
