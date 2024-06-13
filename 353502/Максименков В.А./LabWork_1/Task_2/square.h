#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

class Square : public Shape
{
private:
    qreal halfSide = 50;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void resizeShape(QPointF now) override;
    qreal squareOfShape() override;
    qreal perimetrOfShape() override;

public:
    Square();
    ~Square() = default;
};

#endif // SQUARE_H
