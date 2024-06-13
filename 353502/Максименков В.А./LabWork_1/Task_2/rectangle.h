#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape
{
private:
    qreal halfSide1 = 30;
    qreal halfSide2 = 40;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void resizeShape(QPointF now) override;
    qreal squareOfShape() override;
    qreal perimetrOfShape() override;

    void reinterpret(qreal parametr1, qreal parametr2) override;

public:
    Rectangle();
    ~Rectangle() = default;
};

#endif // RECTANGLE_H
