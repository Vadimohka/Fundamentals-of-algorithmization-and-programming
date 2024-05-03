#include "plane.h"
#include <iostream>

Plane::Plane() {
    chassis = 0;
    firstPossitionPlaneOnX = 0;
    firstPossitionPlaneOnY = 0;
    nowPossitionPlaneOnX = 0;
    nowPossitionPlaneOnY = 0;
}

bool Plane::getChassis() {
    return chassis;
}

void Plane::changeChassis() {
    chassis = !chassis;
    update();
}

void Plane::setChassis(bool newChassis) {
    chassis = newChassis;
    update();
}

void Plane::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    painter->setBrush(Qt::darkMagenta);

    painter->drawRect(firstPossitionPlaneOnX,firstPossitionPlaneOnY,200,60);//основная часть

    QPolygon fuselage;//носовая часть
    fuselage << QPoint(firstPossitionPlaneOnX+200, firstPossitionPlaneOnY) << QPoint(firstPossitionPlaneOnX+200, firstPossitionPlaneOnY+60) << QPoint(firstPossitionPlaneOnX+300, firstPossitionPlaneOnY+60);
    painter->drawPolygon(fuselage);

    if(chassis == 1) { //шасси
        painter->setBrush(Qt::gray);

        painter->drawRect(firstPossitionPlaneOnX+30, firstPossitionPlaneOnY+60,4,15); //второе заднее шасси
        painter->drawEllipse(firstPossitionPlaneOnX+26,firstPossitionPlaneOnY+70,14,14);

        painter->drawRect(firstPossitionPlaneOnX+20, firstPossitionPlaneOnY+60,5,20); //первое заднее шасси
        painter->drawEllipse(firstPossitionPlaneOnX+15,firstPossitionPlaneOnY+75,15,15);

        painter->drawRect(firstPossitionPlaneOnX+175, firstPossitionPlaneOnY+60,5,20); //переднее шасси
        painter->drawEllipse(firstPossitionPlaneOnX+170,firstPossitionPlaneOnY+75,15,15);
    }

    painter->setBrush(Qt::darkMagenta);

    QPolygon rear_wing;//заднее крыло
    rear_wing << QPoint(firstPossitionPlaneOnX, firstPossitionPlaneOnY) << QPoint(firstPossitionPlaneOnX, firstPossitionPlaneOnY-35) << QPoint(firstPossitionPlaneOnX+35,firstPossitionPlaneOnY);
    painter->drawPolygon(rear_wing);


    QPolygon left_side_fender;//левое боковое крыло
    left_side_fender << QPoint(firstPossitionPlaneOnX+30,firstPossitionPlaneOnY+95) << QPoint(firstPossitionPlaneOnX+75,firstPossitionPlaneOnY+30) << QPoint(firstPossitionPlaneOnX+140,firstPossitionPlaneOnY+30);
    painter->drawPolygon(left_side_fender);


    QPolygon right_side_fender;//правое боковое крыло
    right_side_fender << QPoint(firstPossitionPlaneOnX+65, firstPossitionPlaneOnY-10) << QPoint(firstPossitionPlaneOnX+85,firstPossitionPlaneOnY) << QPoint(firstPossitionPlaneOnX+125,firstPossitionPlaneOnY);
    painter->drawPolygon(right_side_fender);

    painter->setBrush(Qt::white);

    QPolygon driver_window; //окно водителя
    driver_window << QPoint(firstPossitionPlaneOnX+225, firstPossitionPlaneOnY+30) << QPoint(firstPossitionPlaneOnX+225, firstPossitionPlaneOnY+15) << QPoint(firstPossitionPlaneOnX+250, firstPossitionPlaneOnY+30);
    painter->drawPolygon(driver_window);

    painter->drawEllipse(firstPossitionPlaneOnX+10,firstPossitionPlaneOnY+10, 15, 17.5); //окна пассажиров

    for (int completion_draw = 40; completion_draw < 200; completion_draw += 40) {
        painter->drawEllipse(firstPossitionPlaneOnX+10+completion_draw, firstPossitionPlaneOnY+10, 15, 17.5);
    }
}

void Plane::addPointUp() {
    nowPossitionPlaneOnY--;
}

void Plane::addPointDown() {
    nowPossitionPlaneOnY++;
}

void Plane::addPointLeft() {
    nowPossitionPlaneOnX--;
}

void Plane::addPointRight() {
    nowPossitionPlaneOnX++;
}

double Plane::getNowPossitionPlaneOnX() {
    return nowPossitionPlaneOnX;
}

double Plane::getNowPossitionPlaneOnY() {
    return nowPossitionPlaneOnY;
}
