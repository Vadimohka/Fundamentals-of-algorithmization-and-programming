//
// Created by dmitry on 10.2.24.
//

#include <Flag.h>

void Flag::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    QPolygon polygon;
    QPen pen;
    pen.setWidth(3);

    painter.begin(this);
    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing);

    polygon<< QPoint(250,ypos1) << QPoint(300,ypos1)
    << QPoint(275,ypos2) <<QPoint(300,ypos3)
    << QPoint(250,ypos3);

    painter.drawPolygon(polygon);
    painter.end();
}

void Flag::timerSlotUp(){
    connect(upTimer, &QTimer::timeout, this, &Flag::repaintUpp);
    upTimer->start(40);
    qDebug() << "Up started  __[OK]__";
}

void Flag::timerSlotDown(){
    connect(downTimer, &QTimer::timeout, this, &Flag::repaintDown);
    downTimer->start(40);
    qDebug() << "Down started  __[OK]__";
}

void Flag::repaintUpp(){
    if (ypos3 < 71){
        upTimer->stop();
        qDebug() <<"Timer stopped";
        emit isUp();
        qDebug() <<"emit isUp";
    }
    else{
        --ypos1;
        --ypos2;
        --ypos3;
        repaint();
    }
    qDebug() << "UP   Repaint started\t" << ypos3;
}

void Flag::repaintDown() {
    if (ypos3 > 299){
        downTimer->stop();
        qDebug() <<"Timer stopped";
        emit isDown();
        qDebug() <<"emit isDown";
    }
    else{
        ++ypos1;
        ++ypos2;
        ++ypos3;
        repaint();
    }
    qDebug() << "DOWN Repaint started\t" << ypos3;
}

Flag::Flag(QWidget *parent) {
    upTimer = new QTimer;
    downTimer = new QTimer;
}

Flag::~Flag() noexcept {
}



