#include "eyes.h"

Eyes::Eyes(QRectF eye_ball , QColor color) :
    MovingEllips(nullptr,eye_ball,color)
{}

void Eyes::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setPen(get_color());
    painter->setBrush(get_color());

    painter->drawEllipse(get_x(),get_y() + (isOpen ? 0 : get_width()/2),get_width(),isOpen ? get_height() : 0);    //eyeball
}

void Eyes::slotBlink()
{
    isOpen = !isOpen;
    update();
}

void Eyes::action_transform()
{
    slotBlink();
    update();
}


