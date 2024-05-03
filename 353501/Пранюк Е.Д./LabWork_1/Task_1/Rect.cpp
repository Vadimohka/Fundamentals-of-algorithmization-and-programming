#include "Rect.h"


Rect::Rect()  {
    timerUp = new QTimer;
    connect(timerUp, &QTimer::timeout, this, &Rect::moveUp);

    timerDown = new QTimer;
    connect(timerDown, &QTimer::timeout, this, &Rect::moveDown);

    x=0;
    y=40;
    minY=-100, maxY=40;
}

QRectF Rect::boundingRect() const {
    return QRectF(0,0,10,10);
}

void Rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(Qt::red);
    painter->drawRect(-50, y-x, 80, 50);

    painter->setBrush(Qt::green);
    painter->drawRect(-50, 30+y-x, 80, 20);
    painter->setBrush(Qt::white);
    painter->drawRect(-50, y-x, 20, 50);
}

void Rect::moveUp(){
    timerUp ->start(15);
    x+=1;
    if (y-x<=maxY && y - x >= minY ) {
        update();
    }
    else {
        timerUp->stop();
    }
}

void Rect::moveDown(){
    timerDown ->start(15);
    x-=1;
    if (y-x <= maxY && y-x>=minY) {
        update();
    }
    else {
        timerDown->stop();
    }
}
