#ifndef STAR8_H
#define STAR8_H

#include "figure.h"

class Star8 : public Figure
{
public:
    Star8();
    float Area() override;
    float Perimeter() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

};

#endif // STAR8_H
