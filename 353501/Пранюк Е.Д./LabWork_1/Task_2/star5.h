#ifndef STAR5_H
#define STAR5_H

#include "figure.h"

class Star5 : public Figure
{
public:
    Star5();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    float perimeter();
    float area() override;
};

#endif // STAR5_H
