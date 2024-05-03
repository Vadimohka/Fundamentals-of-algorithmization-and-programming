#include "rectangle.h"

Rectangle::Rectangle() {}

void Rectangle::MoveUp(){
    ypos--;
}

void Rectangle::MoveDown(){
    ypos++;
}

int Rectangle::Checky()
{
    return ypos;
}
