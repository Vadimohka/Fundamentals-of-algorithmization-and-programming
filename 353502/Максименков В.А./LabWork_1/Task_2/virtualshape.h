#ifndef VIRTUALSHAPE_H
#define VIRTUALSHAPE_H
#include "shape.h"

class VirtualShape : public Shape
{
public:
    VirtualShape();
    ~VirtualShape() = default;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void resizeShape(QPointF now) override;
    qreal squareOfShape() override;
    qreal perimetrOfShape() override;
};

#endif // VIRTUALSHAPE_H
