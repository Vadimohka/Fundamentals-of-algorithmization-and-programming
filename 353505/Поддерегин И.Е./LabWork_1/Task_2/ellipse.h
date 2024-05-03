#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"

class Ellipse : public Shape
{
public:
    Ellipse(QPointF point, QObject *parent = nullptr);
    ~Ellipse();

    qreal square() override;
    qreal perimeter() override;

    void setRadiusA(qreal a) override;
    void setRadiusB(qreal b) override;

    void changeRadiuses(qreal a, qreal b);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    qreal m_radiusA;
    qreal m_radiusB;
};

#endif // ELLIPSE_H
