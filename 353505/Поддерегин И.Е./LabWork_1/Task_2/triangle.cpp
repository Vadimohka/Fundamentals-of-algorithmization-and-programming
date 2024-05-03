#include "triangle.h"
#include <QPainter>

Triangle::Triangle(QPointF point, QObject *parent)
    : Shape(point, parent)
{
    Q_UNUSED(point);
}

Triangle::~Triangle()
{

}

qreal Triangle::square()
{
    return abs(A.x() - C.x()) * abs(B.y() - A.y()) / 2;
}

qreal Triangle::perimeter()
{
    return QLineF(A, B).length() + QLineF(B, C).length() + QLineF(C, A).length();
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setTransformOriginPoint(centerPoint());

    painter->setPen(QPen(Qt::black, 2));

    QPolygonF polygon;

    A = startPoint();
    B = QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : - 1)*
                                       abs((endPoint().x() - startPoint().x())/2), endPoint().y());
    C = QPointF(endPoint().x(), startPoint().y());

    polygon << A << B << C;

    painter->drawPolygon(polygon);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
