#include "polygon.h"

Polygon::Polygon(int& newAmount) {
    amount = newAmount;
}

qreal Polygon::findPerimeter()
{
    return amount * 95 * 2 * sin(M_PI / amount);
}

qreal Polygon::findSquare()
{
    return amount * 95 * 95 * sin(M_PI * 2 / amount) / 2;
}

void Polygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon pol;
    for(int i = 0; i < amount; i++){
        if(i % 2 == 0)
            pol << QPoint(cos(2 * M_PI * i / amount) * 95, sin(2 * M_PI * i / amount) * 95);
        else
            pol << QPoint(cos(2 * M_PI * i / amount) * 95, sin(2 * M_PI * i / amount) * 95);
    }
    painter -> drawPolygon(pol);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

Polygon::~Polygon(){

}
