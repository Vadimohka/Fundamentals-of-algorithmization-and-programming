#include "ellipse.h"
#include <QtMath>

Ellipse::Ellipse(QGraphicsItem *parent):Shape(parent)
{
    ellTimer = new QTimer();
    ellTimer->setInterval(1);
    connect(ellTimer, &QTimer::timeout, this, &Ellipse::Resize);
}

Ellipse::~Ellipse()
{

}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 1));
    painter->setBrush(QBrush(QColor::fromRgb(140, 0, 255)));
    painter->drawEllipse(-current_sideA/2*current_Scale, -current_sideB/2*current_Scale, current_sideA*current_Scale, current_sideB*current_Scale);
    area = M_PI * current_sideA * current_sideB * current_Scale * current_Scale;
    perimeter = M_PI * sqrt(2 * current_sideA * current_sideA + current_sideB * current_sideB) * current_Scale;
}

void Ellipse::Resize()
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

QRectF Ellipse::boundingRect() const
{
    return QRectF(-current_sideA/1.5*current_Scale, -current_sideB/1.5*current_Scale, current_sideA*current_Scale*2, current_sideB*current_Scale*2);
}
