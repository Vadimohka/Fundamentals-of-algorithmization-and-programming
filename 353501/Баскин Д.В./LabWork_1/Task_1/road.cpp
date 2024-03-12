#include "road.h"

Road::Road()
{

}

void Road::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::gray);
    painter->drawRect(-3000, 190, 6000, 300);
}
