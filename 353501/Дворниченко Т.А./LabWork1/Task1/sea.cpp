#include "sea.h"

Sea::Sea(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent) : Rectangle(x,  y,  width,  height,  parent)
{

}
void Sea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{



    painter->setPen(Qt::blue);
    painter->setBrush(Qt::blue);

    // Задание координат и размеров прямоугольника
  // Высота

    // Рисование прямоугольника
    painter->drawRect(-300, 200, 1000, 1000);



}
