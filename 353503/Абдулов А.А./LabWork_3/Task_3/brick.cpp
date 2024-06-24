#include "brick.h"

const int LENGTH = 20;

brick::brick(int num, QPoint centre) : QGraphicsRectItem(centre.x(), centre.y(), LENGTH * num, LENGTH){
    this->num=num;
    this->centre=centre;

    setRect(centre.x()-LENGTH * num / 2, centre.y()-LENGTH/2, LENGTH * num, LENGTH);

    QPen pen(Qt::white);
    setPen(pen);

}
