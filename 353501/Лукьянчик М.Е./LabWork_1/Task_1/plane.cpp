#include "plane.h"
#include<QPushButton>
#include <QPainter>
#include <QTimer>
Plane::Plane()
{
    road=QRect(0,250,700,400);
    backroad=QRect(0,175,700,250);
    sign=QRect(650,50,700,350);
    flag=QRect(500,50,150,100);
    sky=QRect(0,0,700,400);
    x=4;
    y=1;
    a=QRect(10,110,15,15);
    b=QRect(100,110,15,15);
    button=new QPushButton("Play",this);
    button->setGeometry(0,350,60,50);
    timer=new QTimer(this);
    startPaint=false;
    mainPart.rect=QRect(0,100,150,40);
    leftWing.rect=QRect(60,70,20,30);
    rightWing.rect=QRect(60,120,20,50);
    connect(button,SIGNAL(clicked()),this,SLOT(startEvent()));
    connect(button,SIGNAL(clicked()),this,SLOT(delbutton()));
    connect(timer,SIGNAL(timeout()),this,SLOT(beginAnimation()));
    setFixedSize(700,400);
}
void Plane::paintEvent(QPaintEvent*)
{
    if(startPaint==true)
    {
        QPainter* painter=new QPainter(this);
        painter->drawRect(sky);
        painter->fillRect(sky,QColorConstants::Svg::darkturquoise);
        painter->drawRect(backroad);
        painter->fillRect(backroad,QColorConstants::Svg::darkgray);
        painter->drawRect(road);
        painter->fillRect(road,QColorConstants::Svg::gray);
        painter->drawRect(flag);
        painter->fillRect(flag,QColorConstants::Svg::red);
        painter->setBrush(QColorConstants::Svg::black);
        painter->drawEllipse(a);
        painter->drawEllipse(b);
        painter->setBrush(QColorConstants::Svg::cyan);
        painter->drawRect(mainPart.rect);
        painter->drawRect(leftWing.rect);
        painter->drawRect(rightWing.rect);
        painter->drawRect(sign);
        painter->fillRect(sign,QColorConstants::Svg::black);

        timer->start(24);
        painter->end();
    }

}
void Plane::delbutton()
{
    button->deleteLater();
}
void Plane::startEvent()
{
    startPaint=true;
    update();
}
void Plane::beginAnimation()
{
    mainPart.moveplane();
    leftWing.moveplane();
    rightWing.moveplane();
    a.translate(x,y);
    b.translate(x,y);

    if(mainPart.rect.bottom()>height()-180)
    {
        y=3;
    }
    if(mainPart.rect.bottom()<=a.top()+7)
    {
        y=0;
    }
    if(mainPart.rect.bottom()+10==road.top())
    {
        mainPart.straight();
        leftWing.straight();
        rightWing.straight();
        x=2;
        y=0;
    }
    if(mainPart.rect.right()-160==sign.left())
    {
        mainPart.stop();
        leftWing.stop();
        rightWing.stop();
        x=0;
        y=0;
    }

    update();
}
