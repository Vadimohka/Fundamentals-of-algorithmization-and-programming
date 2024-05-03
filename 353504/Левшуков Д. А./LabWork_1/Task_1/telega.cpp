#include "telega.h"
#include <QtWidgets>

telega::telega()
{
    x=1;
    update_spices();
    spice_angle=90.0;
}


void telega::update_spices()
{
    l1={{(qreal)x+(qreal)r/2,(qreal)y+h},{(qreal)x+r/2,(qreal)y+h+r}};
    l2={{(qreal)x+w-(qreal)r/2,(qreal)y+h},{(qreal)x+w-r/2,(qreal)y+h+r}};
    c1={(qreal)x+(qreal)r/2,(qreal)y+h+r/2};
    c2={(qreal)x+w-(qreal)r/2,(qreal)y+h+r/2};
}


void telega::draw(QPainter *p)
{
    DrawRec(p);
    drawWheels(p);
    drawRoad(p);
}


void telega::drawWheels(QPainter *p)
{
    p->drawEllipse(x,y+h,r,r);
    p->drawEllipse(x+w-r,y+h,r,r);
    //Spice (0;1)(2;3)

    //p->drawPoint(x+r/2,y+h+r/2);
    //p->drawPoint(x+w-r/2,y+h+r/2);
    qDebug()<<l1.first.x()<<" "<<l1.first.y();
    qDebug()<<l1.second.x()<<" "<<l1.second.y();
    p->drawLine(l1.first,l1.second);
    p->drawLine(l2.first,l2.second);
    //p->drawPoint(c1);
    //p->drawPoint(c2);

}

void telega::drawRoad(QPainter *p)
{
p->drawLine(0,h+r+y,1200,h+r+y);
}


void telega::drive(int n)
{
    if(x+n<0||x+w+n>=1200)
        return;
    qDebug()<<x<<" "<<n;
    move(n);
    update_spices();
    //Rotate
    spice_angle+=(qreal)(M_PI*(qreal)2.0*(qreal)r/(qreal)k*(qreal)360.0);
    spice_angle=fmod(spice_angle,360);

    l1.first={(c1.x()+qCos(spice_angle)*(l1.first.x()-c1.x())-qSin(spice_angle)*(l1.first.y()-c1.y())),c1.y()+qSin(spice_angle)*(l1.first.x()-c1.x())+qCos(spice_angle)*(l1.first.y()-c1.y())};
    l1.second={(c1.x()+qCos(spice_angle)*(l1.second.x()-c1.x())-qSin(spice_angle)*(l1.second.y()-c1.y())),c1.y()+qSin(spice_angle)*(l1.second.x()-c1.x())+qCos(spice_angle)*(l1.second.y()-c1.y())};
    l2.first={(c2.x()+qCos(spice_angle)*(l2.first.x()-c2.x())-qSin(spice_angle)*(l2.first.y()-c2.y())),c2.y()+qSin(spice_angle)*(l2.first.x()-c2.x())+qCos(spice_angle)*(l2.first.y()-c2.y())};
    l2.second={(c2.x()+qCos(spice_angle)*(l2.second.x()-c2.x())-qSin(spice_angle)*(l2.second.y()-c2.y())),c2.y()+qSin(spice_angle)*(l2.second.x()-c2.x())+qCos(spice_angle)*(l2.second.y()-c2.y())};
}

