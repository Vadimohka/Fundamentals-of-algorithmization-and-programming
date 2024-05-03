#ifndef STAR8_H
#define STAR8_H

#include "figure.h"

class Star8 : public Figure
{
public:
    Star8();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    float perimeter();
    float area() override;
};

#endif // STAR8_H
