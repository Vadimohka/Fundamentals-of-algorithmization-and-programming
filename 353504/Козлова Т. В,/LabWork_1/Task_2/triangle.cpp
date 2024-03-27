#include "triangle.h"
#include <QPainter>

Triangle::Triangle(QPointF point, QObject *parent)
    : Figure(point, parent)
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
    painter->setPen(QPen(Qt::red, 2));
    painter->drawEllipse(startPoint(), 1, 1);
    painter->setPen(QPen(Qt::blue, 2));
    painter->drawEllipse(endPoint(), 1, 1);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
