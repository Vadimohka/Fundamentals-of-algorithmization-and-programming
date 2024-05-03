#include "rocket.h"
#include "qpainter.h"

Rocket::Rocket()
{
    QPen pen(Qt::white);
    pen.setWidth(2);
    //frame
    line1 = new QGraphicsLineItem(50,30,-50,30, this);
    line1->setPen(pen);
    line2 = new QGraphicsLineItem(50,30,50,-120, this);
    line2->setPen(pen);
    line3 = new QGraphicsLineItem(50,-120,-50,-120, this);
    line3->setPen(pen);
    line4 = new QGraphicsLineItem(-50,30,-50,-120, this);
    line4->setPen(pen);
    //nouse
    line5 = new QGraphicsLineItem(-50,-120, 0,-150, this);
    line5->setPen(pen);
    line6 = new QGraphicsLineItem(0,-150,50,-120, this);
    line6->setPen(pen);
    //left wihg
    line7 = new QGraphicsLineItem(-50,30,-80,30, this);
    line7->setPen(pen);
    line8 = new QGraphicsLineItem(-80,30,-50,0, this);
    line8->setPen(pen);
    //right wing
    line9 = new QGraphicsLineItem(50,30,80,30, this);
    line9->setPen(pen);
    line10 = new QGraphicsLineItem(80,30,50,0, this);
    line10->setPen(pen);
    //window
    window = new QGraphicsEllipseItem(-24, -90, 50, 50, this);
    window->setPen(pen);
    //nozzle
    line11 = new QGraphicsLineItem(20,30,30,40, this);
    line11->setPen(pen);
    line12 = new QGraphicsLineItem(-20,30,-30,40, this);
    line12->setPen(pen);
    line13 = new QGraphicsLineItem(30,40,-30,40, this);
    line13->setPen(pen);



}

Rocket::~Rocket()
{

}

void Rocket::Start()
{
    MoveLine::Start();
    //fire
    if(fireline1 == nullptr){
        QPen pen(Qt::red);
        pen.setWidth(2);
        fireline1 = new QGraphicsLineItem(25,42,15,60, this);
        fireline1->setPen(pen);
        fireline2 = new QGraphicsLineItem(15,60,8,53, this);
        fireline2->setPen(pen);
        fireline3 = new QGraphicsLineItem(8,53,0,65, this);
        fireline3->setPen(pen);
        fireline4 = new QGraphicsLineItem(0,65,-8,54, this);
        fireline4->setPen(pen);
        fireline5 = new QGraphicsLineItem(-8,54,-15, 62, this);
        fireline5->setPen(pen);
        fireline6 = new QGraphicsLineItem(-15,62,-28,42, this);
        fireline6->setPen(pen);
    }
}

void Rocket::Restart()
{
    MoveLine::Restart();
    if(fireline1 != nullptr){
        delete fireline1;
        fireline1 = nullptr;
        delete fireline2;
        fireline2 = nullptr;
        delete fireline3;
        fireline3 = nullptr;
        delete fireline4;
        fireline4 = nullptr;
        delete fireline5;
        fireline5 = nullptr;
        delete fireline6;
        fireline6 = nullptr;
    }
}

void Rocket::Conditional()
{
    if(timer->isActive()){
        Restart();
    }
    else{
        Start();
    }
}
