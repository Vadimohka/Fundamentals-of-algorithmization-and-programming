#include "plane.h"
#include<QPushButton>
#include <QPainter>
#include <QTimer>
Plane::Plane() {
    dx=2;
    dy=1;
    nose<<QPoint(-20,60)<<QPoint(30,80)<<QPoint(-20,100);
    tail<<QPoint(-120,60)<<QPoint(-150,30)<<QPoint(-150,130)<<QPoint(-120,100);
    road=QRect(0,300,700,100);
    x=2;
    y=1;
    a=QRect(-110,70,15,15);
    b=QRect(-50,70,15,15);
    button=new QPushButton("start",this);
    button->setGeometry(300,300,80,20);
    timer=new QTimer(this);
    startPaint=false;
    mainPart.rect=QRect(-120,60,100,40);
    leftWing.rect=QRect(-80,10,20,50);
    rightWing.rect=QRect(-80,100,20,50);
    connect(button,SIGNAL(clicked()),this,SLOT(startEvent()));
    connect(timer,SIGNAL(timeout()),this,SLOT(beginAnimation()));
    setFixedSize(700,400);
}
void Plane::paintEvent(QPaintEvent*){
    QPainter* painter=new QPainter(this);
    painter->drawRect(road);
    painter->fillRect(road,QColorConstants::Svg::gray);
    painter->setBrush(QColorConstants::Svg::black);
    painter->setBrush(QColorConstants::Svg::white);
    painter->drawRect(100,340,70,20);
    painter->drawRect(210,340,70,20);
    painter->drawRect(320,340,70,20);
    painter->drawRect(430,340,70,20);
    painter->drawRect(540,340,70,20);
    if(startPaint==true){
        QPainter* painter=new QPainter(this);


        painter->setBrush(QColorConstants::Svg::black);
        painter->drawEllipse(a);
        painter->drawEllipse(b);

        painter->drawRect(mainPart.rect);
        painter->fillRect(mainPart.rect,QColorConstants::Svg::red);
        painter->drawRect(leftWing.rect);
        painter->fillRect(leftWing.rect,QColorConstants::Svg::red);
        painter->drawRect(rightWing.rect);
        painter->fillRect(rightWing.rect,QColorConstants::Svg::red);
        painter->setBrush(QColorConstants::Svg::red);
        painter->drawPolygon(tail);
        painter->drawPolygon(nose);
        timer->start(20);

        painter->end();
    }

}
void Plane::startEvent(){
    startPaint=true;
    update();
}
void Plane::beginAnimation(){
    mainPart.moveRect();
    leftWing.moveRect();
    rightWing.moveRect();
    a.translate(x,y);
    b.translate(x,y);
    tail.translate(dx,dy);
    nose.translate(dx,dy);
    if(mainPart.rect.bottom()>height()-150){
        y=2;
    }
    if(mainPart.rect.bottom()<=a.top()+7){
        y=0;
    }
    if(a.bottom()==road.top()){
        mainPart.stop(1,0);
        leftWing.stop(1,0);
        rightWing.stop(1,0);
        x=1;
        y=0;
        dx=1;
        dy=0;
    }
    if(mainPart.rect.right()>=width()-100){

        mainPart.stop(0,0);
        leftWing.stop(0,0);
        rightWing.stop(0,0);
        x=0;
        y=0;
        dx=0;
        dy=0;

    }

    update();
}
