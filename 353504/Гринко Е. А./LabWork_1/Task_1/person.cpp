#include "person.h"

Person::Person()
{
    QPen pen(Qt::black);
    pen.setWidth(2);
    leftEye = new QGraphicsEllipseItem(rect().width()/2-15, -30, 10, 10, this);
    rightEye = new QGraphicsEllipseItem(rect().width()/2+5, -30, 10, 10, this);
    leftEye->setPen(pen);
    rightEye->setPen(pen);
    head = new QGraphicsEllipseItem(rect().width()/2-20, -40, 40, 40, this);
    head->setPen(pen);
    leftArm = new QGraphicsLineItem(0, 0, -30, 50, this);
    leftArm->setPen(pen);
    rightArm1 = new QGraphicsLineItem(rect().width(), 0, rect().width() + 40, 0, this);
    rightArm1->setPen(pen);
    rightArm2 =new QGraphicsLineItem(rect().width()+40,0,rect().width()/2+10,-40,this);
    rightArm2->setPen(pen);
    leftLeg = new QGraphicsLineItem(0, rect().height(), -50, rect().height() + 50, this);
    leftLeg->setPen(pen);
    rightLeg = new QGraphicsLineItem(rect().width(), rect().height(), rect().width() + 50, rect().height() + 50, this);
    rightLeg->setPen(pen);

    helmet = new QGraphicsEllipseItem(rect().width()/2-25, -50, 50, 10, this);
    helmet->setPen(pen);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateRightArmRotation()));

    QPainterPath mouthPath;

    mouthPath.moveTo(rect().width()/2-10, -15);
    mouthPath.quadTo(rect().width()/2, -10, rect().width()/2+10, -15);
    mouth = new QGraphicsPathItem(mouthPath, this);
    mouth->setPen(pen);
}

Person::~Person()
{
    delete leftEye;
    delete rightEye;
    delete head;
    delete leftArm;
    delete rightArm1;
    delete rightArm2;
    delete leftLeg;
    delete rightLeg;
    delete timer;
    delete mouth;
}

void Person::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Rectangle::paint(painter, option, widget);
}

void Person::rotateRightArm()
{
    if(!timer->isActive()){

        timer->start(50);
    }else{
        timer->stop();
    }
}

void Person::updateRightArmRotation()
{
    qreal maxRotation = 60.0;
    rightArm2->setTransformOriginPoint(QPointF(rect().width() + 40, 0));
    static bool isIncreasing = true;
    if (isIncreasing) {
        if (rightArm2->rotation() >= maxRotation) {
            isIncreasing = false;
        } else {
            rightArm2->setRotation(rightArm2->rotation() + 1);
        }
    } else {
        if (rightArm2->rotation() <= 0) {
            isIncreasing = true;
        } else {
            rightArm2->setRotation(rightArm2->rotation() - 1);
        }
    }
    update();
}


void Person::stopAnimation()
{
    if(timer != nullptr && timer->isActive()) {
        timer->stop();
    }
}
