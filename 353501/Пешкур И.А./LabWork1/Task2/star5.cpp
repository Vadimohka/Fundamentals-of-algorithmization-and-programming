#include "star5.h"

Star5::Star5() {}

void Star5 :: paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    painter->setRenderHint(QPainter::Antialiasing, true);
    QPointF points[11];

    for (int i = 0; i < 5; i++)
    {
        points[i * 2] = QPointF( (double)(0 - Radius1 * sin(2 * M_PI / 5 * i)) , (double)(0 - Radius1 * cos(2 * M_PI / 5 * i)) );
        points[i * 2 + 1] = QPointF( (double)(0 - (double) Radius2 / 2 * sin(2 * M_PI / 5 * i + M_PI / 5)) , (double)(0 - (double) Radius2 / 2 * cos(2 * M_PI / 5 * i + M_PI / 5)) );
    }

    points[10].rx() = points[0].rx();
    points[10].ry() = points[0].ry();

    for (int i = 0; i < 10 ; ++i )
    {
        painter->drawLine( points[i].rx() , points[i].ry() , points[i + 1].rx() , points[i + 1].ry() );
    }

}

float Star5 :: Area()
{
    return this->getScale() * this->getScale() * (M_PI * Radius1 * Radius1 + (M_PI * Radius2 * Radius2 - M_PI * Radius1 * Radius1) / 3);
}

float Star5 :: Perimeter()
{
    return Radius1 * 5 + Radius2 * 5 * this -> getScale();
}


