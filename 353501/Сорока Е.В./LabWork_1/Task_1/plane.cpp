#include "plane.h"
#include<QPushButton>
#include <QPainter>
#include <QTimer>
Plane::Plane() {
    road=QRect(0,300,700,400);
    x=2;
    y=1;
    dx=2;
    dy=1;
    a=QRect(10,110,15,15);
    b=QRect(70,110,15,15);
    sky=QRect(0,0,700,300);
    button=new QPushButton("start",this);
    button->setGeometry(100,300,80,20);
    timer=new QTimer(this);
    startPaint=false;
    mainPart.rect=QRect(0,100,150,40);
    leftWing.rect=QRect(40,85,20,15);
    rightWing.rect=QRect(40,140,20,15);
    tale << QPoint(-40,60) << QPoint(0,100) << QPoint(0,140) << QPoint(-40,140);
    nos << QPoint(150,100) << QPoint(170,115) << QPoint(170,125) << QPoint(150,140);
    connect(button,SIGNAL(clicked()),this,SLOT(startEvent()));
    connect(timer,SIGNAL(timeout()),this,SLOT(beginAnimation()));
    setFixedSize(700,400);
}
void Plane::paintEvent(QPaintEvent*){
    if(startPaint==true){
        QPainter* painter=new QPainter(this);
        painter->drawRect(sky);
        painter->fillRect(sky,QColorConstants::Svg::blue);
        painter->drawRect(road);
        painter->fillRect(road,QColorConstants::Svg::gray);
        painter->setBrush(QColorConstants::Svg::black);
        painter->drawEllipse(a);
        painter->drawEllipse(b);
        painter->drawRect(mainPart.rect);
        painter->fillRect(mainPart.rect,QColorConstants::Svg::white);
        painter->drawRect(leftWing.rect);
        painter->fillRect(leftWing.rect,QColorConstants::Svg::white);
        painter->drawRect(rightWing.rect);
        painter->fillRect(rightWing.rect,QColorConstants::Svg::white);
        painter->setBrush(QColorConstants::Svg::white);
        painter->drawPolygon(tale);
        painter->drawPolygon(nos);


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
    tale.translate(dx,dy);
    nos.translate(dx,dy);
    a.translate(x,y);
    b.translate(x,y);

    if(mainPart.rect.bottom()>height()-200){
        y=2;
    }
    if(mainPart.rect.bottom()<=a.top()+7){
        y=0;
    }
    if(a.bottom()==road.top()){
        mainPart.stop();
        leftWing.stop();
        rightWing.stop();
        x=0;
        y=0;
        dx=0;
        dy=0;
    }

    update();
}
