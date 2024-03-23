#include "circle.h"

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    center = {centerX + moveX, centerY + moveY};

    if(wasCenterDisconnected == true){
        painter->translate(center);
        painter->rotate(angle);
        painter->translate(-center);
    }


    painter->setBrush(Qt::red);
    if(!wasCenterDisconnected){
        painter->drawEllipse(center, radiusX * scale, radiusY * scale);
    }
    else{
        painter->drawEllipse(shiftCenter, radiusX * scale, radiusY * scale);
    }

    painter->setBrush(Qt::white);
    painter->drawEllipse(center, 2, 2);

}

double Circle::findSquare(){
    return M_PI * pow(radiusX * scale, 2);
}

double Circle::findPerimeter(){
    return M_PI * radiusX * scale * 2;
}
