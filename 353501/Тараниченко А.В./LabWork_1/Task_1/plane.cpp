#include "plane.h"

Plane::Plane(QObject *parent) : movingrect() {
    lowered = false;
    rotation = 0;
    timer = new QTimer;
    wing1 = new QGraphicsRectItem(-125, -280, 100, 250, this);
    wing2 = new QGraphicsRectItem(-125, 30, 100, 250, this);
    cabin = new QGraphicsEllipseItem(-220, -25, 50, 50, this);
    rect1 = new QGraphicsRectItem(-225, 40, 50,20, this);
    rect2 = new QGraphicsRectItem(65, 40, 50,20, this);
    wheel1 = new QGraphicsEllipseItem(-175, 35, 30, 30, this);
    wheel2 = new QGraphicsEllipseItem(115, 35, 30, 30, this);
    rect1->setBrush(Qt::blue);
    rect2->setBrush(Qt::blue);
    wheel1->setBrush(Qt::red);
    wheel2->setBrush(Qt::red);
    wing1->setBrush(Qt::yellow);
    wing2->setBrush(Qt::yellow);
    cabin->setBrush(Qt::darkBlue);
}

QRectF Plane::boundingRect() const {
    QRectF rect = QRectF(-250, -50, 400, 100);
    int geardist = rect.height() - 5;
    int geardiam = rect.height() / 2;
    rect = rect.adjusted(-geardist, -10, geardist, geardiam);
    return rect;
}

void Plane::paintp(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF rect = boundingRect();
    QBrush brush(Qt::green);
    painter->fillRect(rect, brush);
    painter->drawRect(rect);
}

void Plane::lowerGear(){
    if (!lowered){
        rect1->setTransformOriginPoint(QPoint(-225,40));
        rect2->setTransformOriginPoint(QPoint(65,40));
        wheel1->setTransformOriginPoint(QPoint(-225,40));
        wheel2->setTransformOriginPoint(QPoint(65,40));
        timer->setInterval(100);
        connect(timer, &QTimer::timeout, this, &Plane::lower);
        timer->start();
    }
    lowered = true;
}

void Plane::unLowerGear(){
    if (lowered){
        rect1->setTransformOriginPoint(QPoint(-225,40));
        rect2->setTransformOriginPoint(QPoint(65,40));
        wheel1->setTransformOriginPoint(QPoint(-225,40));
        wheel2->setTransformOriginPoint(QPoint(65,40));
        timer->setInterval(100);
        connect(timer, &QTimer::timeout, this, &Plane::unlower);
        timer->start();
    }
    lowered = false;
}

void Plane::lower(){
    rotation += 5;
    rect1->setRotation(rotation);
    rect2->setRotation(rotation);
    wheel1->setRotation(rotation);
    wheel2->setRotation(rotation);
    if (rotation == 90){
        disconnect(timer, &QTimer::timeout, this, &Plane::lower);
        timer->stop();
    }
}

void Plane::unlower(){
    rotation -= 5;
    rect1->setRotation(rotation);
    rect2->setRotation(rotation);
    wheel1->setRotation(rotation);
    wheel2->setRotation(rotation);
    if (rotation == 0){
        disconnect(timer, &QTimer::timeout, this, &Plane::unlower);
        timer->stop();
    }
}
