#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Ellipse : public Figure
{
Q_OBJECT

public:
    explicit Ellipse(QPointF point, QObject *parent = 0);
    ~Ellipse();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double area();
    double perimeter();
};

#endif // ELLIPSE_H
