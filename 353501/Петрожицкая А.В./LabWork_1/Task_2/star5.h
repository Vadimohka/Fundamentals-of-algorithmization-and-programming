#ifndef STAR5_H
#define STAR5_H

#include "figure.h"

class Star5 : public Figure
{
public:
    Star5();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    float perimeter();
    float area() override;
    float centerX();
    float centerY();
};

#endif // STAR5_H
