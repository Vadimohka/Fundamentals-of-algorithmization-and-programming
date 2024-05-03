#ifndef STAR6_H
#define STAR6_H

#include "figure.h"

class Star6 : public Figure
{
public:
    Star6();
void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
float perimeter();
float area() override;
};

#endif // STAR6_H
