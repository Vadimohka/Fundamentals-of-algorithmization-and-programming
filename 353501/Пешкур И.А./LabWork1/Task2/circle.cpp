#include "circle.h"

Circle::Circle(){}

void Circle :: paint( QPainter *painter , const QStyleOptionGraphicsItem * , QWidget * )
{

    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawEllipse( -Radius / 2 , -Radius / 2 , Radius , Radius);

}

float Circle :: Area()
{

    return this -> getScale() * this -> getScale() * M_PI * Radius * Radius;

}

float Circle :: Perimeter()
{

    return this -> getScale() * 2 * M_PI * Radius;

}

