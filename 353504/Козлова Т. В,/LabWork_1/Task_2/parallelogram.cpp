#include <QPainter>

#include "parallelogram.h"

Parallelogram::Parallelogram(QPointF point, QObject *parent)
    : Figure(point,parent)
{
    Q_UNUSED(point);
}

Parallelogram::~Parallelogram()
{

}


qreal Parallelogram::square()
{
    return abs(A.x() - D.x()) * abs(A.y() - C.y());
}

qreal Parallelogram::perimeter()
{
    return QLineF(A, B).length() + QLineF(B, C).length() + QLineF(C, D).length() + QLineF(D, A).length();
}


void Parallelogram::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setTransformOriginPoint(centerPoint());

    painter->setPen(QPen(Qt::black, 2));

    QPolygonF polygon;

    A = startPoint();
    B = QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : -1)*abs((endPoint().x() -
                                                                                        startPoint().x())/2), endPoint().y());
    C = endPoint();
    D = QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : -1)*abs((endPoint().x() -
                                                                                        startPoint().x())/2), startPoint().y());

    polygon << A << B << C << D;
    painter->drawPolygon(polygon);
    painter->setPen(QPen(Qt::red, 2));
    painter->drawEllipse(startPoint(), 1, 1);
    painter->setPen(QPen(Qt::blue, 2));
    painter->drawEllipse(endPoint(), 1, 1);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

