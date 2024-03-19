#include "zvezda.h"
#include <QPainter>

Zvezda5::Zvezda5(int radius1,int radius2, QGraphicsPolygonItem* parent): Figure(parent)
{

    QPolygon zv;
    setBrush(Qt::green);

        zv << QPoint(0, -radius1)
       << QPoint(radius2*sin(qDegreesToRadians(36)),-radius2*cos(qDegreesToRadians(36)))
       << QPoint(radius1*sin(qDegreesToRadians(72)),-radius1*cos(qDegreesToRadians(72)))
       << QPoint(radius2*cos(qDegreesToRadians(18)),radius2*sin(qDegreesToRadians(18)))
       << QPoint(radius1*cos(qDegreesToRadians(54)),radius1*sin(qDegreesToRadians(54)))
       << QPoint(0, radius2)
        << QPoint(-radius1*cos(qDegreesToRadians(54)),radius1*sin(qDegreesToRadians(54)))
        << QPoint(-radius2*cos(qDegreesToRadians(18)),radius2*sin(qDegreesToRadians(18)))
        << QPoint(-radius1*sin(qDegreesToRadians(72)),-radius1*cos(qDegreesToRadians(72)))
        << QPoint(-radius2*sin(qDegreesToRadians(36)),-radius2*cos(qDegreesToRadians(36)))
        ;
    setPolygon(zv);
    setFlag(QGraphicsItem::ItemIsMovable);

    QPolygon rhombus;
    rhombus << QPoint(2,0) << QPoint(0,2) << QPoint(-2,0)<< QPoint(0,-2);
    QGraphicsPolygonItem *rhombusItem = new QGraphicsPolygonItem(rhombus, this);
    rhombusItem->setBrush(Qt::red);
    rhombusItem->setFlag(QGraphicsItem::ItemIsMovable);
}

Zvezda6::Zvezda6(int radius1,int radius2, QGraphicsPolygonItem* parent): Figure(parent)
{

    QPolygon zv;
    setBrush(Qt::green);

    zv << QPoint(0, -radius1)
       << QPoint(radius2*sin(qDegreesToRadians(30)),-radius2*cos(qDegreesToRadians(30)))
       << QPoint(radius1*sin(qDegreesToRadians(60)),-radius1*cos(qDegreesToRadians(60)))
       << QPoint(radius2, 0)
       << QPoint(radius1*sin(qDegreesToRadians(60)),radius1*cos(qDegreesToRadians(60)))
       << QPoint(radius2*sin(qDegreesToRadians(30)),radius2*cos(qDegreesToRadians(30)))
       << QPoint(0, radius1)
       << QPoint(-radius2*sin(qDegreesToRadians(30)),radius2*cos(qDegreesToRadians(30)))
       << QPoint(-radius1*sin(qDegreesToRadians(60)),radius1*cos(qDegreesToRadians(60)))
        << QPoint(-radius2, 0)
       << QPoint(-radius1*sin(qDegreesToRadians(60)),-radius1*cos(qDegreesToRadians(60)))
       << QPoint(-radius2*sin(qDegreesToRadians(30)),-radius2*cos(qDegreesToRadians(30)))
        ;
    setPolygon(zv);
    setFlag(QGraphicsItem::ItemIsMovable);

    QPolygon rhombus;
    rhombus << QPoint(2,0) << QPoint(0,2) << QPoint(-2,0)<< QPoint(0,-2);
    QGraphicsPolygonItem *rhombusItem = new QGraphicsPolygonItem(rhombus, this);
    rhombusItem->setBrush(Qt::red);
    rhombusItem->setFlag(QGraphicsItem::ItemIsMovable);
}

Zvezda8::Zvezda8(int radius1,int radius2, QGraphicsPolygonItem* parent): Figure(parent)
{

    QPolygon zv;
    setBrush(Qt::green);

    zv << QPoint(0, -radius1)
       << QPoint(radius2*sin(qDegreesToRadians(22.5)),-radius2*cos(qDegreesToRadians(22.5)))
       << QPoint(radius1*sin(qDegreesToRadians(45)),-radius1*cos(qDegreesToRadians(45)))
       << QPoint(radius2*sin(qDegreesToRadians(67.5)),-radius2*cos(qDegreesToRadians(67.5)))
        << QPoint(radius1, 0)
        << QPoint(radius2*sin(qDegreesToRadians(67.5)),radius2*cos(qDegreesToRadians(67.5)))
        << QPoint(radius1*sin(qDegreesToRadians(45)),radius1*cos(qDegreesToRadians(45)))
        << QPoint(radius2*sin(qDegreesToRadians(22.5)),radius2*cos(qDegreesToRadians(22.5)))
        << QPoint(0, radius1)
       << QPoint(-radius2*sin(qDegreesToRadians(22.5)),radius2*cos(qDegreesToRadians(22.5)))
       << QPoint(-radius1*sin(qDegreesToRadians(45)),radius1*cos(qDegreesToRadians(45)))
       << QPoint(-radius2*sin(qDegreesToRadians(67.5)),radius2*cos(qDegreesToRadians(67.5)))
       << QPoint(-radius1, 0)
       << QPoint(-radius2*sin(qDegreesToRadians(67.5)),-radius2*cos(qDegreesToRadians(67.5)))
       << QPoint(-radius1*sin(qDegreesToRadians(45)),-radius1*cos(qDegreesToRadians(45)))
       << QPoint(-radius2*sin(qDegreesToRadians(22.5)),-radius2*cos(qDegreesToRadians(22.5)))
        ;
    setPolygon(zv);
    setFlag(QGraphicsItem::ItemIsMovable);

    QPolygon rhombus;
    rhombus << QPoint(2,0) << QPoint(0,2) << QPoint(-2,0)<< QPoint(0,-2);
    QGraphicsPolygonItem *rhombusItem = new QGraphicsPolygonItem(rhombus, this);
    rhombusItem->setBrush(Qt::red);
    rhombusItem->setFlag(QGraphicsItem::ItemIsMovable);
}

ZvezdaDraw::ZvezdaDraw(QPointF point, QGraphicsObject *parent) :
    FigureDraw(point,parent)
{
    Q_UNUSED(point)
}

ZvezdaDraw::~ZvezdaDraw()
{

}

void ZvezdaDraw::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 3));
    painter->setBrush(QBrush(Qt::blue));

    QPolygonF polygon;

    polygon << QPointF((startPoint().x()+endPoint().x())/2, startPoint().y())
            << QPointF(startPoint().x()+((endPoint().x()-startPoint().x()))/1.613, startPoint().y()+((endPoint().y()-startPoint().y()))/2.5)
            << QPointF(endPoint().x(),  startPoint().y()+((endPoint().y()-startPoint().y()))/2.5)
            << QPointF(startPoint().x()+((endPoint().x()-startPoint().x()))/1.428,startPoint().y()+((endPoint().y()-startPoint().y()))/1.5625)
            << QPointF(startPoint().x()+((endPoint().x()-startPoint().x()))/1.22,endPoint().y())
            << QPointF(startPoint().x()+((endPoint().x()-startPoint().x()))/2, startPoint().y()+((endPoint().y()-startPoint().y()))/1.282)
            << QPointF(startPoint().x()+((endPoint().x()-startPoint().x()))/5.5556,endPoint().y())
            << QPointF(startPoint().x()+((endPoint().x()-startPoint().x()))/3.125,startPoint().y()+((endPoint().y()-startPoint().y()))/1.5625)
            << QPointF(startPoint().x(), startPoint().y()+((endPoint().y()-startPoint().y()))/2.5)
            << QPointF(startPoint().x()+((endPoint().x()-startPoint().x()))/2.6316, startPoint().y()+((endPoint().y()-startPoint().y()))/2.5);


    painter->drawPolygon(polygon);

    int min =qAbs(endPoint().x()-startPoint().x()), max = qAbs(endPoint().y()-startPoint().y());

    emit coordinatesChanged(min*max/2.5,4*min+4*max);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}
