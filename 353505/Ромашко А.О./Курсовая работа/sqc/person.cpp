#include "person.h"

Person::Person() {}


QRectF Person::boundingRect() const
{

}

void Person::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //QGraphicsItem::paint(painter,option,widget);
}

void Person::getCoordinate(int x, int y, int w, int h)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
}
