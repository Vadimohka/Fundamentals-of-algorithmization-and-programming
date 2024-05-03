#include "moveplane.h"

MovePlane::MovePlane(QWidget *parent)
    : QWidget{parent}
{
    dx=4;
    dy=1;
    rect= QRect();

}
void MovePlane::moveplane()
{
    rect.translate(dx,dy);

}
void MovePlane::stop()
{
    dx=0;
    dy=0;
}
void MovePlane::straight()
{
    dx=2;
    dy=0;
}
