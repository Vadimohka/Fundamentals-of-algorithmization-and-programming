#include "newshape.h"

NewShape :: NewShape(){}

void NewShape :: paint(QPainter* painter, const QStyleOptionGraphicsItem* , QWidget* )
{
    painter->setBrush ( Qt :: red );
    painter->setRenderHint(QPainter::Antialiasing);

    for (int i = 0; i < points.size();++i) {
        painter->drawEllipse( points[i] , scale , scale );
    }

}

void NewShape :: pullPoint(const QPointF& pos)
{

    points.push_back(pos - QPointF( x() , y() ) );

}
