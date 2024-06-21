#include "rectangle.h"

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect(getSP(), getEP());
    painter->drawPolygon(rect);

    setPerimeter(2 * qAbs(getEP().x() - getSP().x()) + 2 * qAbs(getEP().y() - getSP().y()));
    setArea(qAbs(getEP().x() - getSP().x()) * qAbs(getEP().y() - getSP().y()));

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
