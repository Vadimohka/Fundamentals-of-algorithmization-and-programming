#include "circle.h"

Circle::Circle(QGraphicsItem *parent)
{
    circleTimer = new QTimer;
    circleTimer->setInterval(1);
    connect(circleTimer, &QTimer::timeout, this, &Circle::Resize);
}

Circle::~Circle()
{

}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 1));
    painter->setBrush(QBrush(QColor::fromRgb(140, 0, 255)));
    painter->drawEllipse(-current_sideA/2*current_Scale, -current_sideA/2*current_Scale, current_sideA*current_Scale, current_sideA*current_Scale);
    area = M_PI * powl(current_sideA * current_Scale, 2);
    perimeter = 2 * M_PI * current_sideA * current_Scale;
}

void Circle::Resize()
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

    if(abs(current_sideA - sideA) < 0.05){
        current_sideA = sideA;
    }
    update();
}

QRectF Circle::boundingRect() const
{
    return QRectF(-current_sideA/1.5*current_Scale, -current_sideA/1.5*current_Scale, current_sideA*current_Scale*2, current_sideA*current_Scale*2);
}
