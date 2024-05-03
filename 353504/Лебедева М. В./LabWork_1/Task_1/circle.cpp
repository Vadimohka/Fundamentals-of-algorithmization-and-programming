#include "circle.h"

Circle::Circle()
{

}

void Circle::left()
{
    setPos(x()-20,y());
}

void Circle::right()
{
    setPos(x()+20,y());
}
