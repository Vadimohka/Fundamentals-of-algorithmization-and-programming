#include "rectangle.h"
#include "qpainter.h"


Rectangle::Rectangle()
{
    QPen pen(Qt::black);
    pen.setWidth(2);
    helper = new QGraphicsRectItem(20,20,200,150, this);
    helper ->setPen(pen);

    helper1 = new QGraphicsEllipseItem(20,170,50,50, this);
    helper1 ->setPen(pen);

    helper2 = new QGraphicsEllipseItem(170, 170, 50, 50, this);
    helper2 -> setPen(pen);



}

Rectangle:: ~Rectangle()
{

}

void Rectangle::Start()
{
    Wheel::Start();
}

void Rectangle::Restart()
{
    Wheel::Restart();
}

