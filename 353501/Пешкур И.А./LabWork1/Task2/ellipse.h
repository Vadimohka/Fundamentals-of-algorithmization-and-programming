#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "figure.h"

class Ellipse : public Figure
{
public:

    Ellipse();
    float Area() override;
    float Perimeter() override;

protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

};

#endif // ELLIPSE_H
