#include "star6.h"

Star6::Star6() {}

void Star6 :: paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    painter->setRenderHint(QPainter::Antialiasing, true);
    QPoint points[13];

    for (int i = 0; i < 6; i++)
    {
        points[i * 2] = QPoint( int(0 - Radius1 * sin(2 * M_PI / 6 * i)) , int(0 - Radius1 * cos(2 * M_PI / 6 * i)) );
        points[i * 2 + 1] = QPoint( int(0 - (double) Radius2 / 2 * sin(2 * M_PI / 6 * i + M_PI / 6)) , int(0 - (double) Radius2 / 2 * cos(2 * M_PI / 6 * i + M_PI / 6)) );
    }

    points[12].rx() = points[0].rx();
    points[12].ry() = points[0].ry();

    for (int i = 0; i < 12 ; ++i )
    {
        painter->drawLine( points[i].rx() , points[i].ry() , points[i + 1].rx() , points[i + 1].ry() );
    }

}

float Star6 :: Area()
{
    return this->getScale() * this->getScale() * (M_PI * Radius1 * Radius1 + (M_PI * Radius2 * Radius2 - M_PI * Radius1 * Radius1) / 5);
}

float Star6 :: Perimeter()
{
    return Radius1 * 6 + Radius2 * 6 * this -> getScale();
}
