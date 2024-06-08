#include "card.h"
#include <QPointF>
#include <random>
Card::Card() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> dist(0, 2);

    right =dist(rng);
    left = dist(rng);
    top = dist(rng);
    bottom = dist(rng);

}

void Card::Paint(QGraphicsScene* scene,int n, int turnNumber)
{

    if(turnNumber==0){
     rect=new QGraphicsRectItem(QRectF(0,0,50,50));
        rect->setPos(startPosX,startPosY);
    rect->setBrush(QBrush(Qt::green));
    scene->addItem(rect);
    if(left==1){
         leftRect=new QGraphicsRectItem(startPosX,startPosY+20,30,10);
        leftRect->setBrush(QBrush(Qt::black));
        scene->addItem(leftRect);

    }
    if(right==1){
         rightRect=new QGraphicsRectItem(startPosX+20,startPosY+20,30,10);
        rightRect->setBrush(QBrush(Qt::black));
        scene->addItem(rightRect);

    }
    if(top==1){
          topRect=new QGraphicsRectItem(startPosX+20,startPosY,10,25);
        topRect->setBrush(QBrush(Qt::black));
        scene->addItem(topRect);

    }
    if(bottom==1){
       bottomRect=new QGraphicsRectItem(startPosX+20,startPosY+25,10,25);
        bottomRect->setBrush(QBrush(Qt::black));
        scene->addItem(bottomRect);

    }
    if(left==2){
      leftCastle=new QGraphicsRectItem(startPosX,startPosY+10,10,30);
        leftCastle->setBrush(QBrush(Qt::red));

        scene->addItem(leftCastle);

    }
    if(right==2){
          rightCastle=new QGraphicsRectItem(startPosX+40,startPosY+10,10,30);
        rightCastle->setBrush(QBrush(Qt::red));
        scene->addItem(rightCastle);

    }
    if(top==2){
         topCastle=new QGraphicsRectItem(startPosX+10,startPosY,30,10);
        topCastle->setBrush(QBrush(Qt::red));
        scene->addItem(topCastle);

    }
    if(bottom==2){
          bottomCastle=new QGraphicsRectItem(startPosX+10,startPosY+40,30,10);
        bottomCastle->setBrush(QBrush(Qt::red));

        scene->addItem(bottomCastle);


    }
    }
    else{
     rect=new QGraphicsRectItem(QRectF(0,0,50,50));
    rect->setPos(startPosX,startPosY+200);
    rect->setBrush(QBrush(Qt::green));
    scene->addItem(rect);
    if(left==1){
         leftRect=new QGraphicsRectItem(startPosX,startPosY+220,30,10);
        leftRect->setBrush(QBrush(Qt::black));
        scene->addItem(leftRect);

    }
    if(right==1){
        rightRect=new QGraphicsRectItem(startPosX+20,startPosY+220,30,10);
        rightRect->setBrush(QBrush(Qt::black));
        scene->addItem(rightRect);

    }
    if(top==1){
         topRect=new QGraphicsRectItem(startPosX+20,startPosY+200,10,25);
        topRect->setBrush(QBrush(Qt::black));
        scene->addItem(topRect);

    }
    if(bottom==1){
         bottomRect=new QGraphicsRectItem(startPosX+20,startPosY+225,10,25);
        bottomRect->setBrush(QBrush(Qt::black));
        scene->addItem(bottomRect);

    }
    if(left==2){
        leftCastle=new QGraphicsRectItem(startPosX,startPosY+210,10,30);
        leftCastle->setBrush(QBrush(Qt::red));

        scene->addItem(leftCastle);

    }
    if(right==2){
          rightCastle=new QGraphicsRectItem(startPosX+40,startPosY+210,10,30);
        rightCastle->setBrush(QBrush(Qt::red));
        scene->addItem(rightCastle);

    }
    if(top==2){
        topCastle=new QGraphicsRectItem(startPosX+10,startPosY+200,30,10);
        topCastle->setBrush(QBrush(Qt::red));
        scene->addItem(topCastle);

    }
    if(bottom==2){
        bottomCastle=new QGraphicsRectItem(startPosX+10,startPosY+240,30,10);
        bottomCastle->setBrush(QBrush(Qt::red));

        scene->addItem(bottomCastle);


    }

    }

}



