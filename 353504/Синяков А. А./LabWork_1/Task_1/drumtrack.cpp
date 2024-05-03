#include "drumtrack.h"

Drumtrack::Drumtrack(qreal x, qreal y, qreal width, qreal height, QObject *parent)
    : Rectangle(x, y, width, height, parent)
{

}

void Drumtrack::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


    Q_UNUSED(option);
    Q_UNUSED(widget);


    painter->setBrush(Qt::yellow);
    painter->drawPolygon({QPointF(0, -200) , QPointF(100, -200) , QPointF(200, -100) , QPointF(200, 0),QPointF(0, 0)});

    painter->setBrush(Qt::green);
    painter->drawRect(-300, 0, 500, 100);
    painter->setBrush(Qt::black);
    painter->drawEllipse(QRectF(-300, 50, 100, 100));
   painter->drawEllipse(QRectF(100, 50, 100, 100));


}

QRectF Drumtrack::boundingRect() const
{
 return QRectF(-100, -100, 200, 120); // Увеличили размеры границ самосвала
}
