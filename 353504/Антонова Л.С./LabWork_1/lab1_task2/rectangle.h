#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle : public Figure{
public:
    Rectangle(Figure *parent = nullptr);

    void draw(QPainter *painter) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void findSquare() override;
    void findPerimetr() override;
};

#endif // RECTANGLE_H
