// truck.cpp
#include "truck.h"
#include <QPainter>

Truck::Truck(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent)
    : myRectangle(x, y, width, height, parent),
      cabRect(x, y-50, height , width-40),
      bodyRect(x, y+75, width*2, height/2 ),
      //bodywork(x+100, y-75, width*1.5, height*1.5),
      wheel1(x + 270 , y + height , height-25 , height-25),
      wheel2(x +40, y +height, height-25, height-25) {
        /*bodywork.moveTo(x + 100, y - 75);
        bodywork.lineTo(x + 400, y - 75);
        bodywork.lineTo(x + 400, y + 75);
        bodywork.lineTo(x + 100, y + 75);
        bodywork.closeSubpath();*/
      }

QRectF Truck::boundingRect() const {
    return QRectF(0, 0, cabRect.width() + bodyRect.width(), qMax(cabRect.height(), bodyRect.height()));
}

void Truck::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::red);
    painter->drawRect(cabRect);
    painter->setBrush(Qt::black);
    painter->drawRect(bodyRect);
    painter->setBrush(Qt::gray);
    painter->drawEllipse(wheel1);
    painter->drawEllipse(wheel2);
    //painter->setBrush(Qt::yellow);
    //painter->drawPath(bodywork);
}


void Truck::rotateBodywork(QPainterPath& path, qreal angle) {
    
    QTransform transform;
    transform.rotate(angle);
    path = transform.map(path);
}

