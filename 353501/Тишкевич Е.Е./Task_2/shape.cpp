#include "shape.h"

Shape::Shape() {}

QRectF Shape::boundingRect() const
{
    return QRectF(-500,-500,1000,1000);
}


float Shape::getScale()
{
    return scale;
}

