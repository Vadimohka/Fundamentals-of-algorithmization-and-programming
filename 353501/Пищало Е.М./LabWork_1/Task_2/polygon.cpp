#include "polygon.h"
#include <QtMath>

Polygon::Polygon(QGraphicsItem *parent):Shape(parent)
{
    polyTimer = new QTimer();
    polyTimer->setInterval(1);
    connect(polyTimer, &QTimer::timeout, this, &Polygon::Resize);
}

Polygon::~Polygon()
{

}

void Polygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 1));
    painter->setBrush(QBrush(QColor::fromRgb(140, 0, 255)));
    if(drawPoints != nullptr){
        delete drawPoints;
        drawPoints = nullptr;
    }

    drawPoints = new QPointF[count_points];
    for(int i = 0; i < count_points; i++){
        drawPoints[i] = QPointF(current_Scale*current_radA * qCos(2 * M_PI / count_points * i - M_PI / 2), current_Scale*current_radA * qSin(2 * M_PI / count_points * i - M_PI / 2));
    }
    painter->drawPolygon(drawPoints, count_points);
    area = count_points * (current_radA * current_radA * qSin(2 * M_PI / count_points) / 2) * current_Scale * current_Scale;
    perimeter = count_points * sqrt(2 * current_radA * current_radA * (1 - qCos(2 * M_PI / count_points))) * current_Scale;
}

void Polygon::Resize()
{
    if(current_radA < radA && abs(radA  - current_radA) > 1.6){
        current_radA += 3;
    }
    else if(current_radA > radA && abs(radA  - current_radA) > 1.6){
        current_radA -= 3;
    }
    else{
        current_radA = radA;
    }

    update();
}

QRectF Polygon::boundingRect() const
{
    return QRectF(-current_radA*current_Scale*1.5, -current_radA*current_Scale*1.5, current_radA*current_Scale*3, current_radA*current_Scale*3);
}
