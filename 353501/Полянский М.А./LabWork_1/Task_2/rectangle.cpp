#include "rectangle.h"

Rectangle::Rectangle(qreal width, qreal height, QGraphicsItem *parent)
    : Shape(parent), width(width), height(height)
{
    centX = 0;
    centY = 0;
    calculate_points();
    

}

void Rectangle::calculate_points()
{
    
    qreal halfWidth = width/2;
    qreal halfHeight = height/2;

    QPointF topLeft(-halfWidth, -halfHeight);
    QPointF topRight(halfWidth, -halfHeight);
    QPointF bottomRight(halfWidth, halfHeight);
    QPointF bottomLeft(-halfWidth, halfHeight);

    
    points.clear();
    points << topLeft << topRight << bottomRight << bottomLeft;

    setCenter(QPointF(centX, centY));
}

void Rectangle::resizeRectW(qreal newwidth){
    width = newwidth;
    calculate_points();
    update();
}
void Rectangle::resizeRectH(qreal newHieght){
    height = newHieght;
    calculate_points();
    update();
}

qreal Rectangle::area(){
    return height * width;
}
qreal Rectangle::perimeter(){
    return (height + width) * 2;
}