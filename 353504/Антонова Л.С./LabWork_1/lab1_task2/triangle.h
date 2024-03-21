#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle : public Figure {
public:
    Triangle(Figure *parent = nullptr);

    void draw(QPainter *painter) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void findSquare();
    void findPerimetr();
};


#endif // TRIANGLE_H
