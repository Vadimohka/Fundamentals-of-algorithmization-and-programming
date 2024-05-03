#include "circle.h"

Circle::Circle() {
    circle = new QGraphicsEllipseItem;

}

void Circle::advance(int phase)
{
    if(phase!=0){
        int posx = pos().x();
        if(posx+xspeed>=800)
            posx=-200;
        setPos(posx + xspeed,0);
    }
}

