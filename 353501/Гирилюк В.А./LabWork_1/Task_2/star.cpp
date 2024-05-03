#include "star.h"

Star::Star(QGraphicsItem *parent)
 :Shape(parent)
{
    starTimer = new QTimer;
    starTimer->setInterval(1);
    connect(starTimer, &QTimer::timeout, this, &Star::Resize);
}

Star::~Star()
{

}

void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 1));
    if(drawPoints != nullptr){
        delete drawPoints;
        drawPoints = nullptr;
    }

    drawPoints = new QPointF[count_points * 2];



    for(int i = 0; i < count_points*2; i+=2){
        drawPoints[i] = QPointF(current_Scale*current_radA * qCos(2 * M_PI / (count_points * 2 ) * i - M_PI / 2), current_Scale*current_radA * qSin(2 * M_PI / (count_points * 2) * i  - M_PI / 2));
        drawPoints[i+1] = QPointF(current_Scale*current_radB * qCos(2 * M_PI / (count_points * 2) * (i+1) - M_PI / 2), current_Scale*current_radB * qSin(2 * M_PI / (count_points * 2) * (i+1) - M_PI / 2));
        if(i>0){
            painter->drawLine(drawPoints[i], drawPoints[i-1]);
            painter->drawLine(drawPoints[i], drawPoints[i+1]);
        }
    }
    painter->drawLine(drawPoints[0], drawPoints[1]);
    painter->drawLine(QPointF(0, -current_radA*current_Scale), QPointF(current_Scale*current_radB * qCos(-2 * M_PI / (count_points * 2 )  + 3 *M_PI / 2), current_Scale*current_radB * qSin(-2 * M_PI / (count_points * 2) + 3*M_PI / 2)));
    area = count_points * (std::min(current_radA, current_radB)* std::min(current_radA, current_radB) * qSin(2 * M_PI / count_points) / 2 + (std::max(current_radA, current_radB)-std::min(current_radA, current_radB)) * sqrt(2 * std::min(current_radA, current_radB) * std::min(current_radA, current_radB) * (1 - qCos(2 * M_PI / count_points)))/2) * current_Scale * current_Scale;
    perimeter = 2 * count_points * sqrt(powl(std::max(current_radA, current_radB)-std::min(current_radA, current_radB), 2)+std::min(current_radA, current_radB) * std::min(current_radA, current_radB) * (1 - qCos(2 * M_PI / count_points))) * current_Scale;

}

void Star::Resize()
{
    if(current_radA != radA || current_radB != radB){
        if(current_radA < radA && abs(radA  - current_radA) > 0.6){
            ++current_radA;
        }
        else if(current_radA > radA && abs(radA  - current_radA) > 0.6){
            --current_radA;
        }
        else{
            current_radA = radA;
        }

        if(current_radB < radB && abs(radB  - current_radB) > 0.6){
            ++current_radB;
        }
        else if(current_radB > radB && abs(radB  - current_radB) > 0.6){
            --current_radB;
        }
        else{
            current_radB = radB;
        }
        update();
    }
}

QRectF Star::boundingRect() const
{
    return QRectF(-std::max(current_radA, current_radB)*current_Scale*1.5, -std::max(current_radA, current_radB)*current_Scale*1.5, std::max(current_radA, current_radB)*current_Scale*3, std::max(current_radA, current_radB)*current_Scale*3);
}
