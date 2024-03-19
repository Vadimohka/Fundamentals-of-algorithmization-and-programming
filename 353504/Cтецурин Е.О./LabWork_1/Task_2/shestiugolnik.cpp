#include "shestiugolnik.h"
#include <QPainter>

Shestiugolnik::Shestiugolnik(int x, QGraphicsPolygonItem* parent): Figure(parent)
{

    QPolygonF hex;
    setBrush(Qt::green);

    hex << QPoint(-x, 0)
        << QPoint(-x/2, -0.866*x)
        << QPoint(x/2, -0.866*x)
        << QPoint(x, 0)
        << QPoint(x/2, 0.866*x)
        << QPoint(-x/2, 0.866*x);
    setPolygon(hex);
    setFlag(QGraphicsItem::ItemIsMovable);

    QPolygon rhombus;
    rhombus << QPoint(2,0) << QPoint(0,2) << QPoint(-2,0)<< QPoint(0,-2);
    QGraphicsPolygonItem *rhombusItem = new QGraphicsPolygonItem(rhombus, this);
    rhombusItem->setBrush(Qt::red);
    rhombusItem->setFlag(QGraphicsItem::ItemIsMovable);
}

HexDraw::HexDraw(QPointF point, QGraphicsObject *parent) :
    FigureDraw(point,parent)
{
    Q_UNUSED(point)
}

HexDraw::~HexDraw()
{

}

void HexDraw::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 3));
    painter->setBrush(QBrush(Qt::blue));

    QPolygonF polygon;

    polygon << QPointF((startPoint().x()+endPoint().x())/2, startPoint().y())
            << QPointF(endPoint().x(), startPoint().y()+(endPoint().y()-startPoint().y())/3)
            << QPointF(endPoint().x(), startPoint().y()+2*(endPoint().y()-startPoint().y())/3)
            << QPointF((startPoint().x()+endPoint().x())/2, endPoint().y())
            << QPointF(startPoint().x(), startPoint().y()+2*(endPoint().y()-startPoint().y())/3)
            << QPointF(startPoint().x(), startPoint().y()+(endPoint().y()-startPoint().y())/3);

    painter->drawPolygon(polygon);

    int min =qAbs(endPoint().x()-startPoint().x()), max = qAbs(endPoint().y()-startPoint().y());

    emit coordinatesChanged(min*max*2/3,max*2/3+min*2);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}
