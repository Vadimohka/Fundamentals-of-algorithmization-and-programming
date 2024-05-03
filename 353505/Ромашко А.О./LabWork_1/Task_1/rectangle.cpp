#include "rectangle.h"

Rectangle::Rectangle():QGraphicsRectItem()
{
    rect = new QGraphicsRectItem;
    QColor color = QColor(200,200,100);
    setBrush(color);
    setRect(10,400,200,100);
}

void Rectangle::advance(int phase)
{
    if(phase!=0){
        int posx = pos().x();
        if(posx+xspeed>=800)
              posx=-200;
       setPos(posx + xspeed,0);
    }
}

