#include "ellipse.h"

Ellipse::Ellipse(){}

void Ellipse :: paint( QPainter *painter , const QStyleOptionGraphicsItem * , QWidget * )
{

    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawEllipse( -Radius / 2 - Radius / 4 , -Radius / 2 , Radius + Radius / 2 , Radius );

}

float Ellipse :: Area()
{

    return this -> getScale() * this -> getScale() * M_PI * Radius * Radius / 2;

}

float Ellipse :: Perimeter()
{

    return this -> getScale() * ( M_PI * Radius * Radius / 2 + Radius / 2 ) / ( Radius * 3 / 2 ) * 4;

}
