#include "triangle.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>

Triangle::Triangle(QPointF point, QObject *parent) :
    Figure(point,parent) {}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen = QPen(Qt::white, 2);
    painter->setPen(pen);

    QPolygonF trpol;

    trpol << QPointF(startPoint().x(), startPoint().y())
            << QPointF(startPoint().x() - (endPoint().x() - startPoint().x()), endPoint().y())
            << QPointF(endPoint().x(), endPoint().y());

    painter->drawPolygon(trpol);

    Q_UNUSED(widget)
    //Q_UNUSED(option)
}
