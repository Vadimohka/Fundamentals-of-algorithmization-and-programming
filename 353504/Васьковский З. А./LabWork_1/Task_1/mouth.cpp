#include "mouth.h"

Mouth::Mouth(QRectF mouth,QColor color) :
    MovingEllips(nullptr,mouth,color)
{}
void Mouth::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QPen pen;
    pen.setWidth(4);
    pen.setColor(QColor(234, 137, 148));
    painter->setBrush(get_color());
    painter->setPen(pen);
    if(was_click)
        painter->drawEllipse(get_x(),get_y()+get_height()/1.5,get_width(),0);
    else
        painter->drawEllipse(get_x(),get_y(),get_width(),get_height());
}

void Mouth::action_transform()
{
    slotTransform();
    update();
}

void Mouth::slotTransform()
{
    was_click =! was_click;
}
