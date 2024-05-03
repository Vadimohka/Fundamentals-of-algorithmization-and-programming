#include "point_pov.h"

void point_pov::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter -> drawEllipse(2, 3, 10, 10);
}
