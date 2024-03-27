#ifndef PERSON_H
#define PERSON_H

#include "rectangle.h"
class Person:public Rectangle{
    Q_OBJECT
public:
    Person();
    ~Person();
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);
    void rotateRightArm();
    void stopAnimation();
private slots:
    void updateRightArmRotation();
private:
    QTimer *timer;
    QGraphicsEllipseItem* head;
    QGraphicsLineItem* leftArm;
    QGraphicsLineItem* rightArm1;
    QGraphicsLineItem*rightArm2;
    QGraphicsLineItem* leftLeg;
    QGraphicsLineItem* rightLeg;
    QGraphicsEllipseItem *leftEye;
    QGraphicsEllipseItem *rightEye;
    QGraphicsPathItem *mouth;
    QGraphicsEllipseItem *helmet;
};

#endif // PERSON_
