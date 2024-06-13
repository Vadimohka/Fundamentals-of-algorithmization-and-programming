#include "rectangle.h"

Rectangle::Rectangle(QWidget *parent)
    : QWidget{parent}
{
    this->setParent(parent);
    x1 = 200, y1 = 200;
    x2 = 200, y2 = 300;
    x3 = 400, y3 = 300;
    x4 = 400; y4 = 200;
    x5 = x1, y5 = y1;
    x6 = x2, y6 = y2;
    x7 = x3, y7 = y3;
    x8 = x4, y8 = y4;
    a=x3-x2,b=y4-y3;
    phi=0;
}

void Rectangle::paintEvent(QPaintEvent *event)
{
    QPoint p1(x5,y5);
    QPoint p2(x6,y6);
    QPoint p3(x7,y7);
    QPoint p4(x8,y8);
    QPolygon pol;
    pol << p1 << p2 << p3 <<p4;
    QPainter paint(this);
    paint.begin(this);
    QPen pen(Qt::blue);
    paint.setPen(pen);
    paint.setBrush(Qt::blue);
    paint.drawPolygon(pol);
    paint.drawLine(x5,y5,x6,y6);
    paint.drawLine(x6,y6,x7,y7);
    paint.drawLine(x7,y7,x8,y8);
    paint.drawLine(x8,y8,x5,y5);
    paint.end();
}

void Rectangle::moveUp()
{

    if(phi<3.14/6){
        phi+=0.05;
        y7=y3-(x3-x2)*sin(phi);
        x7=x2+(x3-x2)*cos(phi);
        y8=y2+sqrt(pow(y4-y3,2)+pow(x3-x2,2))*sin(-phi+atan((double)b/a));
        x8=x2+sqrt(pow(y4-y3,2)+pow(x3-x2,2))*cos(-phi+atan((double)b/a));
        x5=x2+b*sin(phi);
        y5=y2+b*cos(-phi);
        this->repaint();
    }

}

void Rectangle::moveDown()
{
    if(phi>0.01){
        phi-=0.05;
        y7=y3-(x3-x2)*sin(phi);
        x7=x2+(x3-x2)*cos(phi);
        y8=y2+sqrt(pow(y4-y3,2)+pow(x3-x2,2))*sin(-phi+atan((double)b/a));
        x8=x2+sqrt(pow(y4-y3,2)+pow(x3-x2,2))*cos(-phi+atan((double)b/a));
        x5=x2+b*sin(phi);
        y5=y2+b*cos(-phi);
        this->repaint();
    }

}
void Rectangle::moveLeft()
{
    if(this->x()>-145)
    this->move(this->x()-10,this->y());
}
void Rectangle::moveRight()
{
    if(this->x()<325)
    this->move(this->x()+10,this->y());
}





