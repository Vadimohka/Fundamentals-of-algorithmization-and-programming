#include "rhombus.h"

Rhombus::Rhombus(){
    width = 100;
    height = 200;
    pointsX.append(centerX - width/2);
    pointsY.append(centerY);
    pointsX.append(centerX);
    pointsY.append(centerY - height/2);
    pointsX.append(centerX + width/2);
    pointsY.append(centerY);
    pointsX.append(centerX);
    pointsY.append(centerY + height / 2);
    for(int i = 0; i < 4; i++){
        points.append(QPointF(pointsX[i], pointsY[i]));
    }
}


void Rhombus::calculatePoints(){
    points.resize(4);
    pointsX[0] = centerX - width/2;
    pointsY[0] = centerY;
    pointsX[1] = centerX;
    pointsY[1] = centerY - height / 2;
    pointsX[2] = centerX + width/2;
    pointsY[2] = centerY;
    pointsX[3] = centerX;
    pointsY[3] = centerY + height / 2;
    for(int i = 0; i < points.size(); i++){
        points[i] = QPointF(pointsX[i], pointsY[i]);
    }
}

void Rhombus::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);

    calculatePoints();

    center = QPointF(centerX + moveX, centerY + moveY);
    move = QPointF(moveX, moveY);
    disconnectedMove = QPointF(disconnectedMoveX, disconnectedMoveY);

    painter->translate(move);
    painter->rotate(angle);
    painter->translate(-move);

    QPolygonF rhombus;
    if(!wasCenterDisconnected){
        for(auto &point: points){
            rhombus << point * scale + move;
        }
    }
    else{
        for(auto &point: points){
            rhombus << point * scale + disconnectedMove;
        }
    }

    painter->setBrush(Qt::red);
    painter->drawPolygon(rhombus);
    painter->setBrush(Qt::white);
    painter->drawEllipse(center, 2, 2);
}

void Rhombus::setRhombWidth(double value){
    width = value;
};
void Rhombus::setRhombHeight(double value){
    height = value;
};
