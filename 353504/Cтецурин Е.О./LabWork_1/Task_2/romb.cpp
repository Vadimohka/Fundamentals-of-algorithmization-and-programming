#include "romb.h"
#include <QPainter>

Romb::Romb(int x, int y, QGraphicsPolygonItem* parent) : Figure(parent)
{
    QPolygonF romb;
    setBrush(Qt::green);

    romb << QPoint(0, -y/2)
         << QPoint(x/2, 0)
         << QPoint(0, y/2)
         << QPoint(-x/2, 0);
    setPolygon(romb);
    setFlag(QGraphicsItem::ItemIsMovable);

    QPolygon rhombus;
    rhombus << QPoint(2,0) << QPoint(0,2) << QPoint(-2,0)<< QPoint(0,-2);
    QGraphicsPolygonItem *rhombusItem = new QGraphicsPolygonItem(rhombus, this);
    rhombusItem->setBrush(Qt::red);
    rhombusItem->setFlag(QGraphicsItem::ItemIsMovable);
}

RombDraw::RombDraw(QPointF point, QGraphicsObject *parent) :
    FigureDraw(point,parent)
{
    Q_UNUSED(point)
}

RombDraw::~RombDraw()
{

}

void RombDraw::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 3));
    painter->setBrush(QBrush(Qt::blue));

    QPolygonF polygon;

    polygon << QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : - 1)*
                                              abs((endPoint().x() - startPoint().x())/2), startPoint().y())
            << QPointF(endPoint().x(), startPoint().y() + (endPoint().y() > startPoint().y() ? + 1 : - 1)*
                                                              abs((endPoint().y() - startPoint().y())/2))
            << QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : - 1)*
                                              abs((endPoint().x() - startPoint().x())/2), endPoint().y())
            << QPointF(startPoint().x(), startPoint().y() + (endPoint().y() > startPoint().y() ? + 1 : - 1)*
                                                                abs((endPoint().y() - startPoint().y())/2));

    painter->drawPolygon(polygon);

    int min =qAbs(endPoint().x()-startPoint().x()), max = qAbs(endPoint().y()-startPoint().y());

    emit coordinatesChanged(min*max/2,(int)(sqrt(min*min+max*max)*2));
    Q_UNUSED(option)
    Q_UNUSED(widget)
}
