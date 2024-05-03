#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(qreal width, qreal height, QGraphicsItem *parent = nullptr);


protected:
    void calculate_points();
    void resizeRectW(qreal newwidth) override;
    void resizeRectH(qreal newHieght) override;
    qreal area() override;
    qreal perimeter() override;

private:
    qreal width;
    qreal height;
    
};

#endif // RECTANGLE_H
