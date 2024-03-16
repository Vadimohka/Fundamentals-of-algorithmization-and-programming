#include "circle.h"

Circle :: Circle(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent): QGraphicsEllipseItem(x,  y,  width,  height, parent)
{}

void Circle :: move( int angle ){

    setX( angle - 200 );

}

