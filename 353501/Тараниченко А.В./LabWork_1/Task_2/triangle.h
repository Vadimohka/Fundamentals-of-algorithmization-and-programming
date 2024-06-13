#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape
{
    Q_OBJECT
public:
    explicit Triangle(QPointF point, QObject *parent = nullptr);
    ~Triangle();

    qreal square() override;
    qreal perimeter() override;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QPointF A, B, C;
};

#endif // TRIANGLE_H

