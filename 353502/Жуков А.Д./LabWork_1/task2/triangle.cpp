#include "triangle.h"

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygonF tr;
    QPointF
        point1 = QPointF(getSP().x() + (getEP().x() > getSP().x() ? + 1 : - 1) * abs((getEP().x() - getSP().x())/2), getSP().y()),
        point2 = QPointF(getSP().x(), getEP().y()),
        point3 = QPointF(getEP().x(), getEP().y());

    tr << point1
       << point2
       << point3;

    painter->drawPolygon(tr);

    setPerimeter(qAbs(point2.x() - point3.x()) +
                 sqrt(pow(point2.x() - point1.x(), 2) + pow(point2.y() - point1.y(), 2)) +
                 sqrt(pow(point3.x() - point1.x(), 2) + pow(point3.y() - point1.y(), 2)));
    setArea(qAbs(point3.x() - point2.x())/2 * qAbs(point2.y() - point1.y()));

    Q_UNUSED(widget);
    Q_UNUSED(option);
}
