#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"

class Circle : public Figure
{
public:
    Circle();
void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
       // void paintEvent(QPaintEvent* event);
    float perimeter();
float area() override;
};

#endif // CIRCLE_H
