#include "star8.h"

Star8::Star8() {}

void Star8 :: paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    painter->setRenderHint(QPainter::Antialiasing, true);
    QPoint points[17];

    for (int i = 0; i < 8; i++)
    {
        points[i * 2] = QPoint( int(0 - Radius1 * sin(2 * M_PI / 8 * i)) , int(0 - Radius1 * cos(2 * M_PI / 8 * i)) );
        points[i * 2 + 1] = QPoint( int(0 - (double) Radius2 / 2 * sin(2 * M_PI / 8 * i + M_PI / 8)) , int(0 - (double) Radius2 / 2 * cos(2 * M_PI / 8 * i + M_PI / 8)) );
    }

    points[16].rx() = points[0].rx();
    points[16].ry() = points[0].ry();

    for (int i = 0; i < 16 ; ++i )
    {
        painter->drawLine( points[i].rx() , points[i].ry() , points[i + 1].rx() , points[i + 1].ry() );
    }

}

float Star8 :: Area()
{
    return this->getScale() * this->getScale() * (M_PI * Radius1 * Radius1 + (M_PI * Radius2 * Radius2 - M_PI * Radius1 * Radius1) / 4);
}

float Star8 :: Perimeter()
{
    return Radius1 * 8 + Radius2 * 8 * this -> getScale();
}
