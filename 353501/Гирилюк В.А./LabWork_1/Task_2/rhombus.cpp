#include "rhombus.h"

Rhombus::Rhombus(QGraphicsItem *parent)
 :Shape(parent)
{
    rhombTimer = new QTimer();
    rhombTimer->setInterval(1);
    connect(rhombTimer, &QTimer::timeout, this, &Rhombus::Resize);
}

Rhombus::~Rhombus()
{

}

void Rhombus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 1));
    painter->setBrush(QBrush(QColor::fromRgb(140, 0, 255)));
    QPointF *point = new QPointF[4];
    point[0] = QPointF(current_diagB/2*current_Scale, 0);
    point[1] = QPointF(0, current_diagA/2*current_Scale);
    point[2] = QPointF(-current_diagB/2*current_Scale, 0);
    point[3] = QPointF(0, -current_diagA/2*current_Scale);
    painter->drawPolygon(point, 4);
    area = current_diagA * current_diagB /2 * current_Scale * current_Scale;
    perimeter = std::sqrt(powl(current_diagA, 2) + powl(current_diagB, 2)) * 2 * current_Scale;
}

void Rhombus::Resize()
{
    if(current_diagA < diagA && abs(current_diagA  - diagA) > 4){
        current_diagA += 3;
    }
    else if(current_diagA > diagA && abs(diagA  - current_diagA) > 4){
        current_diagA -= 3;
    }
    else if(current_diagA < diagA){
        current_diagA += 0.01;
    }
    else if(current_diagA > diagA){
        current_diagA -= 0.01;
    }

    if(current_diagB < diagB && abs(diagB  - current_diagB) > 4){
        current_diagB += 3;
    }
    else if(current_diagB > diagB && abs(diagB  - current_diagB) > 4){
        current_diagB -= 3;
    }
    else if(current_diagB < diagB){
        current_diagB += 0.01;
    }
    else if(current_diagB > diagB){
        current_diagB -= 0.01;
    }

    if(abs(current_diagA - diagA) < 0.05 && abs(diagB - current_diagB) < 0.05){
        current_diagA = diagA;
        current_diagB = diagB;
    }
    else if(abs(current_diagA - diagA) < 0.05){
        current_diagA = diagA;
    }
    else if(abs(current_diagB - diagB) < 0.05){
        current_diagB = diagB;
    }
    update();
}

QRectF Rhombus::boundingRect() const
{
    return QRectF(-current_diagB/1.5*current_Scale, -current_diagA/1.5*current_Scale, current_diagB*current_Scale*2, current_diagA*current_Scale*2);
}
