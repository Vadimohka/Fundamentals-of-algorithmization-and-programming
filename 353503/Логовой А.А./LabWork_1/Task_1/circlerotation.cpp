#include "circlerotation.h"

CircleRotation::CircleRotation() : CircleMoving(), angle_rotation(0) {
    is_push_button = false;
}

void CircleRotation::rotation(QPainter* painter, QGraphicsScene* scene){
    if(is_push_button)
        change_angle = 1;
    else
        change_angle =0;

    painter->rotate(angle_rotation);
    angle_rotation += change_angle;
    update();
}


void CircleRotation::paint(QPainter *painter,  const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(Qt::red);
    painter->save();
    painter->translate(50,50);

    rotation(painter,scene);
    painter->translate(-50,-50);
    painter->drawEllipse(circle_);
    painter->setBrush(Qt::black);
    painter->drawLine(0,50,100,50);
    painter->drawLine(50,0,50,100);
    painter->drawLine(15,15,85,85);
    painter->drawLine(85,15,15,85);
    painter->restore();
}


void CircleRotation::pushOn()
{
    is_push_button = !is_push_button;
}
