#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figures.h"

class Rectangle : public Figure
{
private:
    qreal halfSide1 = 30;
    qreal halfSide2 = 40;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    qreal squareOfFigure() override;
    qreal perimetrOfFigure() override;

    void resize(qreal changeSize) override;

public:
    Rectangle();
    ~Rectangle() = default;
};

#endif // RECTANGLE_H
