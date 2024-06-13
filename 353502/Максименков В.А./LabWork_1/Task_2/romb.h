#ifndef ROMB_H
#define ROMB_H
#include "shape.h"

class Romb : public Shape
{
private:
    qreal halfDiagonal1 = 30;
    qreal halfDiagonal2 = 50;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void resizeShape(QPointF now) override;
    qreal squareOfShape() override;
    qreal perimetrOfShape() override;

    void reinterpret(qreal parametr1, qreal parametr2) override;

public:
    Romb();
    ~Romb() = default;
};

#endif // ROMB_H
