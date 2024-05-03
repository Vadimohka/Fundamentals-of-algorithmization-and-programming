#include "mykvadrat.h"
#include <QPainter>

MyKvadrat::MyKvadrat(int x, QGraphicsPolygonItem* parent): Figure(parent)
{
    QPolygonF kv;
    setBrush(Qt::green);

    kv << QPoint(-x/2, x/2)
        << QPoint(x/2, x/2)
        << QPoint(x/2, -x/2)
        << QPoint(-x/2, -x/2);
    setPolygon(kv);
    setFlag(QGraphicsItem::ItemIsMovable);

    QPolygon rhombus;
    rhombus << QPoint(2,0) << QPoint(0,2) << QPoint(-2,0)<< QPoint(0,-2);
    QGraphicsPolygonItem *rhombusItem = new QGraphicsPolygonItem(rhombus, this);
    rhombusItem->setBrush(Qt::red);
    rhombusItem->setFlag(QGraphicsItem::ItemIsMovable);
}

void KvadratDraw1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 3));
    painter->setBrush(QBrush(Qt::blue));

    int min =std::min(qAbs(endPoint().x()-startPoint().x()),qAbs(endPoint().y()-startPoint().y()));
    int x,y;
    if (startPoint().x() > endPoint().x()){
        x=startPoint().x()-min;
    } else {
        x=startPoint().x();
    }
    if (startPoint().y() > endPoint().y()){
        y=startPoint().y()-min;
    } else {
        y=startPoint().y();
    }
    QRectF rect (x,y,min, min);

    painter->drawRect(rect);
    emit coordinatesChanged(min*min,min*4);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}
