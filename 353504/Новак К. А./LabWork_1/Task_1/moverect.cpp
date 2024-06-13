#include "moverect.h"

void moverect::set(int new_x, int new_y, int new_width, int new_height) {
    x=new_x;
    y=new_y;
    width=new_width;
    height=new_height;
}

int moverect::gety() {
    return y;
}

void moverect::moveup()
{
    y--;
}

void moverect::movedown()
{
    y++;
}
