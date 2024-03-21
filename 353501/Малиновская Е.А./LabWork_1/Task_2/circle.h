#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <QPainter>

class Circle : public Shape
{
    Q_OBJECT

public:
    QPointF center;
    void paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    qreal calculateArea() override;
    qreal calculatePerimeter() override;
};

#endif // CIRCLE_H
