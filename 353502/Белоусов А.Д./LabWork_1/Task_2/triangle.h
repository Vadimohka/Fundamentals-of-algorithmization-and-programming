#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class triangle : public figure
{
public:
    triangle();
    ~triangle() override;
    double getSquare() override;
    double getPerimeter() override;
    void setFigure(QPointF* points) override;
    bool isPointInside(QPointF point) override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
};

#endif // TRIANGLE_H
