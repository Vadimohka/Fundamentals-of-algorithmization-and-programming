#ifndef STAR6_H
#define STAR6_H

#include "figure.h"

class Star6 : public Figure
{
public:

    Star6();
    float Area() override;
    float Perimeter() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

};

#endif // STAR6_H
