#include "custom.h"

Custom::Custom() {}

void Custom::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QColorConstants::Svg::pink);
    painter->setPen(QPen(QColorConstants::Svg::pink, Figure::k));
    for(int i = 0; i < points.size() - 1; i++) {
        painter->drawEllipse(points[i].x(), points[i].y(), 10, 10);
    }
}
