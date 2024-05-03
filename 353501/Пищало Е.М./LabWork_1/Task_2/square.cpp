#include "square.h"
#include <QtMath>

Square::Square(QGraphicsItem *parent)
 :Shape(parent)
{
    sqrTimer = new QTimer;
    sqrTimer->setInterval(1);
    connect(sqrTimer, &QTimer::timeout, this, &Square::Resize);
}

Square::~Square()
{

}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 1));
    painter->setBrush(QBrush(QColor::fromRgb(140, 0, 255)));
    painter->drawRect(-current_sideA/2*current_Scale, -current_sideA/2*current_Scale, current_sideA*current_Scale, current_sideA*current_Scale);
    area = current_sideA * current_sideA * current_Scale * current_Scale;
    perimeter = 4 * current_sideA * current_Scale;
}

void Square::Resize()
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

QRectF Square::boundingRect() const
{
    return QRectF(-current_sideA/1.5*current_Scale, -current_sideA/1.5*current_Scale, current_sideA*current_Scale*2, current_sideA*current_Scale*2);
}
