#include "shapeCircle.h"

void ShapeCircle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    center = QPointF(0, 0);

    shift = QPointF(shiftX, shiftY);

    painter->setRenderHint(QPainter::Antialiasing);
    painter->translate(0, -300);

    shiftDetached = QPointF(lastShiftX, lastShiftY);

    painter->translate(shift);
    painter->rotate(rotation);
    painter->translate(-shift);

    if(detached){
        painter->drawEllipse(center + shiftDetached, radius1 * scale, radius1 * scale);
    } else {
        painter->drawEllipse(shift, radius1 * scale, radius1 * scale);
    }

    painter->drawEllipse(shift, 1, 1);
}

qreal ShapeCircle::area()
{
    return M_PI * (radius1 * scale) * (radius1 * scale);
}

qreal ShapeCircle::perimeter()
{
    return 2 * M_PI * (radius1 * scale);
}

void ShapeCircle::clear()
{
    shiftX = 0;
    shiftY = 0;
    rotation = 0;

    lastShiftX = 0;
    lastShiftY = 0;

    scale = 1;

    detached = false;
}
