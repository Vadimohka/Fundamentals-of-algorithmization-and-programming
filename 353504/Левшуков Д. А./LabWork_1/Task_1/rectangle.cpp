#include "rectangle.h"
#include <QPainter>


rectangle::rectangle()
{
    x=1;
    k=1;
}

void rectangle::DrawRec(QPainter *p)
{
    p->drawRect(x,y,w,h);
}

void rectangle::move(int k)
{
    x+=k;
    if(x<0||x+w>=1200)
        x-=k;
    //repaint();
}
