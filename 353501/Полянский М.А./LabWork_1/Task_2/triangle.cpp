#include "triangle.h"

Triangle::Triangle(qreal side1, qreal side2, qreal side3, QGraphicsItem *parent)
    : Shape(parent), side1(side1), side2(side2), side3(side3)
{
    centX = (0 + side1 + ((side3*side3 + side1*side1 - side2*side2) / (2.0 * side1))) / 3.0;
    centY = (0 + 0 + sqrt(side3*side3 - pow((side3*side3 + side1*side1 - side2*side2) / (2.0 * side1), 2))) / 3.0;

    
    calculate_points();
}

void Triangle::calculate_points()
{
    points.resize(3);
    pointsy.resize(3);
    pointsx.resize(3);
    pointsx[0] = 0;
    pointsy[0] = 0;
    pointsx[1] = side1;
    pointsy[1] = 0;
    pointsx[2] = (side3*side3 + side1*side1 - side2*side2) / (2.0 * side1);
    pointsy[2] = sqrt(side3*side3 - pow((side3*side3 + side1*side1 - side2*side2) / (2.0 * side1), 2));

    points[0] = QPointF(pointsx[0], pointsy[0]);
    points[1] = QPointF(pointsx[1], pointsy[1]);
    points[2] = QPointF(pointsx[2], pointsy[2]);
    

    setCenter(QPointF(centX, centY));
}

void Triangle::resizeTriangle1(qreal side){
    side1  = side;
    calculate_points();
    update();
}
void Triangle::resizeTriangle2(qreal side){
    side2 = side;
    calculate_points();
    update();
}
void Triangle::resizeTriangle3(qreal side){
    side3  = side;
    calculate_points();
    update();
}

qreal Triangle::area(){
    double p = (side1 + side2 + side3) / 2;
    return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}
qreal Triangle::perimeter(){
    return side1 + side2 + side3;
}