#include "Rectangle.h"

Rectangle:: Rectangle(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent): QGraphicsRectItem(x,  y,  width,  height, parent){

}

void Rectangle::move(){
int newY = y() - 25;
int minY = -50;
int maxY = 50;
    if (newY >= minY && newY <= maxY) {
        setY(newY);
    }
}
void Rectangle::move_up()
{
    int newY = y() + 50;
    int minY = -50;
    int maxY = 50;
    if (newY >= minY && newY <= maxY) {
        setY(newY);
    }
}
