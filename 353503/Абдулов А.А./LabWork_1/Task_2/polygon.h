#ifndef POLYGON_H
#define POLYGON_H

#include "figure.h"

class Polygon: public Figure{
public:
    Polygon();
    float area() override;
    float perimeter() override;
    void setPoints(QMouseEvent *me) override;
    void draw(QPainter *,float scale);
    float scale=1;
    QPoint centerOfWidget;
};

#endif // POLYGON_H

