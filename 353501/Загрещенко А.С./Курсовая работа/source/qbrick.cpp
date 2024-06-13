#include "qbrick.h"
#include "brick.h"

#include <QGraphicsDropShadowEffect>
#include <QDebug>

QBrick::QBrick(const QString &text){


}


QBrick::QBrick(Brick* brick){
    setAlignment(Qt::AlignCenter);
    this->brick = brick;
}

void QBrick::draw(){
    if(brick == nullptr){
        setText("");
        setStyleSheet("QBrick { background: rgb(204,192,179); border-radius: 10px; }");
    }
    else{
        int brickNum =  brick->getVal();
        setText(QString::number(brickNum));
        // Set corresponding colors
        if(brickNum == 2){
            setStyleSheet("QBrick { background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; }");
        }
        else if(brickNum == 4){
            setStyleSheet("QBrick { background: rgb(237,224,200); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; }");
        }
        else if(brickNum == 8){
            setStyleSheet("QBrick { background: rgb(242,177,121); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
        }
        else if(brickNum == 16){
            setStyleSheet("QBrick { background: rgb(245,150,100); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
        }
        else if(brickNum == 32){
            setStyleSheet("QBrick { background: rgb(245,125,95); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
        }
        else if(brickNum == 64){
            setStyleSheet("QBrick { background: rgb(245,95,60); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
        }
        else if(brickNum == 128){
            setStyleSheet("QBrick { background: rgb(237,207,114); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
        }
        else if(brickNum == 256){
            QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
            dse->setColor(Qt::yellow);
            dse->setBlurRadius(20);
            dse->setOffset(-1);
            setGraphicsEffect(dse);
            setStyleSheet("QBrick { background: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
        }
        else if(brickNum == 512){
            QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
            dse->setColor(Qt::yellow);
            dse->setBlurRadius(30);
            dse->setOffset(-1);
            setGraphicsEffect(dse);
            setStyleSheet("QBrick { background: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
        }
        else if(brickNum == 1024){
            QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
            dse->setColor(Qt::yellow);
            dse->setBlurRadius(40);
            dse->setOffset(-1);
            setGraphicsEffect(dse);
            setStyleSheet("QBrick { background: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");

        }
        else if(brickNum == 2048){
            QGraphicsDropShadowEffect *dse = new QGraphicsDropShadowEffect();
            dse->setColor(Qt::yellow);
            dse->setBlurRadius(50);
            dse->setOffset(-1);
            setGraphicsEffect(dse);
            setStyleSheet("QBrick { background: rgb(237,204,97); color: rgb(255,255,255); font: bold; border-radius: 10px; font: 40pt; }");
        }
        else{
            setStyleSheet("QTile { background: rgb(238,228,218); color: rgb(119,110,101); font: bold; border-radius: 10px; font: 40pt; }");
        }

    }
}
