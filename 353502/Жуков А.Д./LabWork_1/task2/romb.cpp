#include "romb.h"

void Romb1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygonF pol;
    QPointF
        point1 = QPointF(getSP().x() + (getEP().x() > getSP().x() ? + 1 : - 1)*abs((getEP().x() - getSP().x())/2), getSP().y()),
        point2 = QPointF(getEP().x(), getSP().y() + (getEP().y() > getSP().y() ? + 1 : - 1)*abs((getEP().y() - getSP().y())/2)),
        point3 = QPointF(getSP().x() + (getEP().x() > getSP().x() ? + 1 : - 1)*abs((getEP().x() - getSP().x())/2), getEP().y()),
        point4 = QPointF(getSP().x(), getSP().y() + (getEP().y() > getSP().y() ? + 1 : - 1)*abs((getEP().y() - getSP().y())/2));


    pol << point1
        << point2
        << point3
        << point4;

    painter->drawPolygon(pol);

    setPerimeter(sqrt(pow(point2.x() - point1.x(), 2) + pow(point2.y() - point1.y(), 2)) +
                 sqrt(pow(point3.x() - point2.x(), 2) + pow(point3.y() - point2.y(), 2)) +
                 sqrt(pow(point4.x() - point3.x(), 2) + pow(point4.y() - point3.y(), 2)) +
                 sqrt(pow(point1.x() - point4.x(), 2) + pow(point1.y() - point4.y(), 2)));

    setArea(qAbs(getSP().x() - getEP().x()) * qAbs(getSP().y() - getEP().y())/2);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
