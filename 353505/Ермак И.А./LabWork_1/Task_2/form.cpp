#include "form.h"


form::form() : QGraphicsObject() {
    angle = 0;
}

int form::angleDecreas() {
    return --angle;
}

int form::angleIncreas() {
    return ++angle;
}

void form::MoveLeft()
{
    if(positionX <= -1050)
        positionX = 1000;
    else
        --positionX;
    update();
}

void form::MoveRight()
{
    if(positionX >= 1050)
        positionX = -1000;
    else
        ++positionX;
    update();
}

void form::MoveUp()
{
    if(positionY <= -1050)
        positionY = 1000;
    else
        --positionY;
    update();
}

void form::MoveDown()
{
    if(positionY >= 1050)
        positionY = -1000;
    else
        ++positionY;
    update();
}
