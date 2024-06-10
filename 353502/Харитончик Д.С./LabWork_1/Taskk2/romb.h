#ifndef ROMB_H
#define ROMB_H
#include "figures.h"

class Romb : public Figure
{
private:
    qreal halfDiagonal1 = 30;
    qreal halfDiagonal2 = 50;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    qreal squareOfFigure() override;
    qreal perimetrOfFigure() override;

    void resize(qreal changeSize) override;

public:
    Romb();
    ~Romb() = default;
};

#endif // ROMB_H
