#include "customeshape.h"

CustomeShape :: CustomeShape(){}

void CustomeShape :: paint(QPainter* painter, const QStyleOptionGraphicsItem* , QWidget* )
{
    painter->setBrush ( Qt :: black );
    painter->setRenderHint(QPainter::Antialiasing);

    for (int i = 0; i < points.size();++i) {
        painter->drawEllipse( points[i] , Scale , Scale );
    }

}

void CustomeShape :: pullPoint(const QPointF& pos)
{

    points.push_back(pos - QPointF( x() , y() ) );

}
