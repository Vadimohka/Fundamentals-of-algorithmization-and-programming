#include "rectangle.h"

rectangle::rectangle()
{

}

void rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    QPolygon polygon;
    polygon << QPoint(0- lenin, 0-stalin) << QPoint(200 + lenin,0-stalin) << QPoint(200 + lenin, 200 + stalin) << QPoint(0-lenin, 200 + stalin);
    painter->setBrush(Qt::red);
    painter->setPen(Qt::red);

    painter->drawPolygon(polygon);
}

float rectangle::area()
{
    return this->getScale() * this->getScale() * lenin * stalin;
}
void rectangle::updateSizeStorona(double arg1){

    lenin = arg1;

}
void rectangle::updateSizeStoronaW(double arg1){
    stalin = arg1;
}


float rectangle::perimeter()
{
    return (2 * getScale() * lenin + 2 * getScale() * stalin);
}
