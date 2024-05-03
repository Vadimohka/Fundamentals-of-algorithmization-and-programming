#include "triangle.h"
#include <QtMath>

Triangle::Triangle(QGraphicsItem *parent)
    :Shape(parent)
{
    triangleTimer = new QTimer;
    triangleTimer->setInterval(1);
    connect(triangleTimer, &QTimer::timeout, this, &Triangle::Resize);
}

Triangle::~Triangle()
{

}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 1));
    painter->setBrush(QBrush(QColor::fromRgb(140, 0, 255)));

    point = new QPointF[3];

    point[0] = QPointF(-current_sideA/2, current_sideB*qSin(qAcos((powl(current_sideC, 2)-powl(current_sideA, 2)-powl(current_sideB, 2))/(-2*current_sideA*current_sideB)))/2)*current_Scale;
    point[1] = QPointF(current_sideA/2, current_sideB*qSin(qAcos((powl(current_sideC, 2)-powl(current_sideA, 2)-powl(current_sideB, 2))/(-2*current_sideA*current_sideB)))/2)*current_Scale;
    point[2] = QPointF(current_sideA/2-current_sideC*qCos(qAcos((powl(current_sideB, 2)-powl(current_sideA, 2)-powl(current_sideC, 2))/(-2*current_sideA*current_sideC))), -current_sideB*qSin(qAcos((powl(current_sideC, 2)-powl(current_sideA, 2)-powl(current_sideB, 2))/(-2*current_sideA*current_sideB)))/2)*current_Scale;
    painter->drawPolygon(point, 3);
    center->setPos((point[0].x()+point[1].x()+point[2].x())/3+coordCenter_X+coordobj_X, (point[0].y()+point[1].y()+point[2].y())/3+coordCenter_Y+coordobj_Y);
    area = current_sideA * current_sideB * qSin(qAcos((powl(current_sideC, 2)-powl(current_sideA, 2)-powl(current_sideB, 2))/(-2*current_sideA*current_sideB)))/2 * current_Scale * current_Scale;
    perimeter = (current_sideA + current_sideB + current_sideC) * current_Scale;
}

void Triangle::Resize()
{
    if(current_sideA < sideA && abs(sideA  - current_sideA) > 1.6){
        current_sideA += 3;
    }
    else if(current_sideA > sideA && abs(sideA  - current_sideA) > 1.6){
        current_sideA -= 3;
    }
    else{
        current_sideA = sideA;
    }

    if(current_sideB < sideB && abs(sideB  - current_sideB) > 1.6){
        current_sideB += 3;
    }
    else if(current_sideB > sideB && abs(sideB  - current_sideB) > 1.6){
        current_sideB -= 3;
    }
    else{
        current_sideB = sideB;
    }

    if(current_sideC < sideC && abs(sideC  - current_sideC) > 1.6){
        current_sideC += 3;
    }
    else if(current_sideC > sideC && abs(sideC  - current_sideC) > 1.6){
        current_sideC -= 3;
    }
    else{
        current_sideC = sideC;
    }
    update();
}

QRectF Triangle::boundingRect() const
{
    return QRectF(-std::max(std::max(current_sideA, current_sideB), current_sideC)*current_Scale, -std::max(std::max(current_sideA, current_sideB), current_sideC)*current_Scale, std::max(std::max(current_sideA, current_sideB), current_sideC)*2*current_Scale, std::max(std::max(current_sideA, current_sideB), current_sideC)*2*current_Scale);
}
