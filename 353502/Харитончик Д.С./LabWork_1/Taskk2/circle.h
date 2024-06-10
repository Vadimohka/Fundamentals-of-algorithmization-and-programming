#ifndef CIRCLE_H
#define CIRCLE_H
#include "figures.h"

class Circle : public Figure
{
private:
    QPointF center = QPointF(0, 0);
    qreal radius = 50;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    qreal squareOfFigure() override;
    qreal perimetrOfFigure() override;
    void resize(qreal changeSize) override;

public:
    Circle();
    ~Circle() = default;
};

#endif // CIRCLE_H
