#include "hexagon.h"

Hexagon::Hexagon(){}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    painter -> setRenderHint(QPainter::Antialiasing, true);
    QPolygon polygon;
    polygon << QPoint( -Radius , 0 ) << QPoint( -Radius / 2 , Radius * sqrt( 3 ) / 2) << QPoint( Radius / 2, Radius * sqrt( 3 ) / 2) << QPoint( Radius , 0 ) << QPoint( Radius / 2 , -Radius * sqrt( 3 ) / 2 ) << QPoint( -Radius / 2 , -Radius * sqrt( 3 ) / 2 );
    painter -> drawPolygon( polygon );

}

float Hexagon::Area()
{

    return this -> getScale() * this -> getScale() * 3 * Radius * Radius * sqrt( 3 ) / 2;

}

float Hexagon::Perimeter()
{

    return 6 * Radius * this -> getScale();

}



