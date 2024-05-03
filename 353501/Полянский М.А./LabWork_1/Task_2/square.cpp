#include "square.h"

Square::Square(qreal side, QGraphicsItem *parent)
    : Shape(parent), side(side)
{
    
    calculate_points();
}

void Square::calculate_points()
{
    points.clear();

    qreal halfSide = side / 2;

    QPointF topLeft(-halfSide, -halfSide);
    QPointF topRight(halfSide, -halfSide);
    QPointF bottomRight(halfSide, halfSide);
    QPointF bottomLeft(-halfSide, halfSide);

    points << topLeft << topRight << bottomRight << bottomLeft;
    setCenter(QPointF(centX, centY));
    
}
void Square::resSide(qreal newside){
    side = newside;
    calculate_points();
    update();
}

qreal Square::area(){
    return side * side;
}
qreal Square::perimeter(){
    return side * 4;
}

