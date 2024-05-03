#include "background.h"

Background::Background() {

}

void Background::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::cyan);
    painter->drawRect(-10000, -10000, 100000, 100000);

    painter->setBrush(Qt::green);
    painter->drawRect(-50000, 300, 100000, 100000);

    painter->setBrush(Qt::yellow);
    painter->drawEllipse(-700, -500, 250, 250);
}
