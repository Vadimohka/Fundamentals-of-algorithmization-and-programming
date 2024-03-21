#include "circle.h"

void Circle::paint (QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    QPointF rotationCenter;
    rotationCenter = (QPointF(0 + X, 0 + Y));
    if(!centerConnected) {
        rotationCenter = (QPointF(0 + rotateCenterX, 0 + rotateCenterY));
    }
    center = {0 + X,0 + Y};
    painter->translate(rotationCenter);
    painter->rotate(rotateAngle);
    painter->translate(-rotationCenter);
    painter->drawEllipse(center,radius * size,radius * size);
    painter->drawEllipse(rotationCenter,1,1);
}
qreal Circle::calculateArea(){
    return M_PI * (radius * radius);
}
qreal Circle::calculatePerimeter(){
    return 2 * M_PI * radius;
}
