#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"

class Hexagon : public Figure
{
public:
    Hexagon();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
   // void paintEvent(QPaintEvent* event);
    float perimeter();
    float area() override;
};

#endif // HEXAGON_H
