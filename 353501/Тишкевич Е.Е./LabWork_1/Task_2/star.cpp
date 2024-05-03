#include "star.h"

Star::Star() : Shape(), radA(45), radB(100), n(6) {}

void Star::setRadA(int radius) {
    radA = radius*scale;
    QGraphicsItem::update();
}

void Star::setRadB(int radius) {
    radB = radius*scale;
    QGraphicsItem::update();
}

void Star::setN(int edges) {
    n = edges;
    QGraphicsItem::update();
}

void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->setRenderHint(QPainter::Antialiasing);


    QPolygonF polygon;
    for (int i = 0; i < n * 2; ++i) {
        qreal radius = (i % 2 == 0) ? radA : radB;
        qreal angle = (M_PI / n) * i;
        polygon << QPointF(radius * cos(angle) + width()/ 2, radius *sin(angle) + height() / 2);
    }


    painter->drawPolygon(polygon);
    painter->setPen(QPen(Qt::red, 3));
    painter->drawPoint(x,y);
    painter->setPen(QPen(Qt::darkGreen, 3));
    painter->drawPoint(0,0);
    painter->setPen(Qt::black);
}

float Star::perim()
{
        return 2 * n * radA *radB* sin(M_PI / n)/100;
}

float Star::area()
{
        return n * radA * radB * sin(2 * M_PI / n) / 2/100;
}
