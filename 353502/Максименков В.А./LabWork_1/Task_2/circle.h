#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

class Circle : public Shape
{
private:
    QPointF center = QPointF(0, 0);
    qreal radius = 50;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void resizeShape(QPointF now) override;
    qreal squareOfShape() override;
    qreal perimetrOfShape() override;

public:
    Circle();
    ~Circle() = default;
};

#endif // CIRCLE_H
