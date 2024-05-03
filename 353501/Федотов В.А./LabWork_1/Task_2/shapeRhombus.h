#ifndef SHAPERHOMBUS_H
#define SHAPERHOMBUS_H

#include "shape.h"

class ShapeRhombus : public Shape
{
public:
    ShapeRhombus();

    // void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    qreal h1, h2;

    void calculatePoints() override;
    void clear() override;
};

#endif // SHAPERHOMBUS_H
