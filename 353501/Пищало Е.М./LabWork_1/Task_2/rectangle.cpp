#include "rectangle.h"
#include <QtMath>

Rectangle::Rectangle(QGraphicsItem *parent)
 :Shape(parent)
{
    rectTimer = new QTimer();
    rectTimer->setInterval(1);
    connect(rectTimer, &QTimer::timeout, this, &Rectangle::Resize);
}

Rectangle::~Rectangle()
{

}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 1));
    painter->setBrush(QBrush(QColor::fromRgb(140, 0, 255)));
    painter->drawRect(-current_sideA/2*current_Scale, -current_sideB/2*current_Scale, current_sideA*current_Scale, current_sideB*current_Scale);
    area = current_sideA * current_sideB * current_Scale * current_Scale;
    perimeter = 2 * (current_sideA + current_sideB) * current_Scale;
}

void Rectangle::Resize()
{
    if(current_sideA < sideA && abs(sideA  - current_sideA) > 4){
        current_sideA += 3;
    }
    else if(current_sideA > sideA && abs(sideA  - current_sideA) > 4){
        current_sideA -= 3;
    }
    else if(current_sideA < sideA){
        current_sideA += 0.01;
    }
    else if(current_sideA > sideA){
        current_sideA -= 0.01;
    }

    if(current_sideB < sideB && abs(sideB  - current_sideB) > 4){
        current_sideB += 3;
    }
    else if(current_sideB > sideB && abs(sideB  - current_sideB) > 4){
        current_sideB -= 3;
    }
    else if(current_sideB < sideB){
        current_sideB += 0.01;
    }
    else if(current_sideB > sideB){
        current_sideB -= 0.01;
    }

    if(abs(current_sideA - sideA) < 0.05 && abs(sideB - current_sideB) < 0.05){
        current_sideA = sideA;
        current_sideB = sideB;
    }
    else if(abs(current_sideA - sideA) < 0.05){
        current_sideA = sideA;
    }
    else if(abs(current_sideB - sideB) < 0.05){
        current_sideB = sideB;
    }
    update();
}

QRectF Rectangle::boundingRect() const
{
    return QRectF(-current_sideA/1.5*current_Scale, -current_sideB/1.5*current_Scale, current_sideA*current_Scale*2, current_sideB*current_Scale*2);
}
