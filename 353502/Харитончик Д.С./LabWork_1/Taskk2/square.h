#ifndef SQUARE_H
#define SQUARE_H
#include "figures.h"

class Square : public Figure
{
private:
    qreal halfSide = 50;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    qreal squareOfFigure() override;
    qreal perimetrOfFigure() override;
    void resize(qreal changeSize) override;

public:
    Square();
    ~Square() = default;
};

#endif // SQUARE_H
