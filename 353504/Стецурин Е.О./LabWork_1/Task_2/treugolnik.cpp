#include "treugolnik.h"
#include <QPainter>

Treugolnik::Treugolnik(int x, QGraphicsPolygonItem* parent) : Figure(parent)
{
    QPolygon triangle;
    triangle << QPoint(-x/2, 0.2887*x)
             << QPoint(x/2, 0.2887*x)
             << QPoint(0, -x*0.577);
    setPolygon(triangle);
    setBrush(Qt::green);
    setFlag(QGraphicsItem::ItemIsMovable);

    QPolygon rhombus;
    rhombus << QPoint(2,0) << QPoint(0,2) << QPoint(-2,0)<< QPoint(0,-2);
    QGraphicsPolygonItem *rhombusItem = new QGraphicsPolygonItem(rhombus, this);
    rhombusItem->setBrush(Qt::red);
    rhombusItem->setFlag(QGraphicsItem::ItemIsMovable);
}

void TreugolnikDraw::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 3));
    painter->setBrush(QBrush(Qt::blue));

    QPolygonF polygon;

    polygon << QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : - 1)*
                                              abs((endPoint().x() - startPoint().x())/2), startPoint().y())
            << QPointF((endPoint().x() > startPoint().x()) ? endPoint().x() : startPoint().x(), endPoint().y())
            << QPointF((endPoint().x() > startPoint().x()) ? startPoint().x() : endPoint().x(), endPoint().y());

    painter->drawPolygon(polygon);


    int min =qAbs(endPoint().x()-startPoint().x()), max = qAbs(endPoint().y()-startPoint().y());

    emit coordinatesChanged(min*max/2,(int)(min+sqrt(min*min/4+max*max)*2));

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

