#include <QPainter>
#include "rectangle.h"

Rectangle::Rectangle(QPointF point, QObject *parent)
    : Parallelogram(point, parent)
{
    Q_UNUSED(point);
}

Rectangle::~Rectangle()
{

}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setTransformOriginPoint(centerPoint());

    painter->setPen(QPen(Qt::black, 2));

    QPolygonF polygon;

    A = startPoint();
    B = QPointF(startPoint().x(), endPoint().y());
    C = endPoint();
    D = QPointF(endPoint().x(), startPoint().y());

    polygon << A << B << C << D;

    painter->drawPolygon(polygon);
    painter->setPen(QPen(Qt::red, 2));
    painter->drawEllipse(startPoint(), 1, 1);
    painter->setPen(QPen(Qt::blue, 2));
    painter->drawEllipse(endPoint(), 1, 1);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
