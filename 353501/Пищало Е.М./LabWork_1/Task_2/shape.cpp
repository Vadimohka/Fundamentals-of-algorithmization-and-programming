#include "shape.h"
#include <QtMath>

Shape::Shape(QGraphicsItem *parent) : QGraphicsObject(parent){
    center = new Center();
    timer = new QTimer(this);
    timer->setInterval(1);
    connect(timer, &QTimer::timeout, this, &Shape::Move);
    connect(timer, &QTimer::timeout, this, &Shape::Rotate);
    connect(timer, &QTimer::timeout, this, &Shape::Scale);
    connect(timer, &QTimer::timeout, this, &Shape::Move_Center);
}



Shape::~Shape()
{

}

QRectF Shape::boundingRect() const
{
    return QRectF(-1000, -750, 2500, 1500);
}

void Shape::Rotate()
{
    qreal currentAngle = rotation();
    if(currentAngle != rotate){
        if(currentAngle < rotate && abs(currentAngle - rotate) > 1){
            ++currentAngle;
        }
        else if(currentAngle > rotate && abs(currentAngle - rotate) > 1){
            --currentAngle;
        }
        else{
            currentAngle = rotate;
        }
        setRotation(currentAngle);
    }
}

void Shape::Move()
{
    qreal current_X = pos().x();
    qreal current_Y = pos().y();
    if (coordobj_X != current_X){
        if(current_X < coordobj_X && abs(coordobj_X - current_X) > 0.6){
            ++current_X;
        }
        else if(current_X > coordobj_X && abs(current_X - coordobj_X) > 0.6){
            --current_X;
        }
        else{
            current_Y = coordobj_Y;
        }
        setPos(current_X, current_Y);
    }

    if(current_Y != coordobj_Y){
        if(current_Y < coordobj_Y && abs(coordobj_Y - current_Y) > 0.6){
            ++current_Y;
        }
        else if(current_Y > coordobj_Y && abs(current_Y - coordobj_Y) > 0.6){
            --current_Y;
        }
        else{
            current_Y = coordobj_Y;
        }
        setPos(current_X, current_Y);
    }

}

void Shape::Move_Center()
{
    qreal current_X = pos().x();
    qreal current_Y = pos().y();
    if(coordCenter_X > current_coordCenter_X && abs(coordCenter_X - current_coordCenter_X) > 1.1){
        current_coordCenter_X += 2;
    }
    else if(coordCenter_X < current_coordCenter_X && abs(coordCenter_X - current_coordCenter_X) > 1.1){
        current_coordCenter_X -= 2;
    }
    else{
        current_coordCenter_X = coordCenter_X;
    }

    if(coordCenter_Y > current_coordCenter_Y && abs(coordCenter_Y - current_coordCenter_Y) > 1.1){
        current_coordCenter_Y += 2;
    }
    else if(coordCenter_Y < current_coordCenter_Y && abs(coordCenter_Y - current_coordCenter_Y) > 1.1){
        current_coordCenter_Y -= 2;
    }
    else {
        current_coordCenter_Y = coordCenter_Y;
    }
    center->setPos(current_coordCenter_X + current_X, current_coordCenter_Y + current_Y);

    setTransformOriginPoint(current_coordCenter_X, current_coordCenter_Y);
}



void Shape::Scale()
{
    if(scale != current_Scale){
        if(current_Scale < scale && abs(current_Scale - scale) > 0.07){
            current_Scale += 0.1;
        }
        else if(current_Scale > scale && abs(current_Scale - scale) > 0.07){
            current_Scale -= 0.1;
        }
        else{
            current_Scale = scale;
        }
    }
}


void Shape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
}
