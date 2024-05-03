#ifndef STAR5_H
#define STAR5_H

#include "figure.h"

class Star5 : public Figure
{
public:
    Star5();
    float Area() override;
    float Perimeter() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

};

#endif // STAR5_H
