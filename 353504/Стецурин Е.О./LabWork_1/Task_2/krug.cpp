#include "krug.h"
#include <QPainter>

Krug::Krug(qreal x, qreal y, qreal diameter)
{
    group = new QGraphicsItemGroup(this);

    QPixmap backgroundImage("/home/hxppy/Pictures/sv.jpg");

    QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem(x - diameter / 2, y - diameter / 2, diameter, diameter);

    QBrush imageBrush(backgroundImage);
    ellipse->setBrush(imageBrush);

    group->addToGroup(ellipse);

    QPolygon rhombus;
    rhombus << QPoint(2, 0) << QPoint(0, 2) << QPoint(-2, 0) << QPoint(0, -2);
    QGraphicsPolygonItem* rhombusItem = new QGraphicsPolygonItem(rhombus);
    rhombusItem->setBrush(Qt::red);
    group->addToGroup(rhombusItem);

    group->setFlag(QGraphicsItem::ItemIsMovable);
}

void KrugDraw::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QImage image("/home/hxppy/Pictures/sv.jpg");
    QBrush brush(image);

    painter->setPen(QPen(Qt::black, 3));
    painter->setBrush(brush);

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

    painter->drawEllipse(rect);

    emit coordinatesChanged(3.1415*min*min/4,min*3.1415);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

