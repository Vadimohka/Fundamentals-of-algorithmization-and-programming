#include "rectangle.h"

Rectangle::Rectangle(){
    width = 100;
    height = 200;
    centerX = 0;
    centerY = 0;

    pointsX.append(centerX - width / 2);
    pointsY.append(centerY- height / 2);
    pointsX.append(centerX + width / 2);
    pointsY.append(centerY - height / 2);
    pointsX.append(centerX + width / 2);
    pointsY.append(centerY + height / 2);
    pointsX.append(centerX - width / 2);
    pointsY.append(centerY + height / 2);

    for(int i = 0; i < 4; i++){
        points.append(QPointF(pointsX[i], pointsY[i]));
    }
}


void Rectangle::calculatePoints(){
    points.resize(4);
    pointsX[0] = centerX - width / 2;
    pointsY[0] = centerY- height / 2;
    pointsX[1] = centerX + width / 2;
    pointsY[1] = centerY - height / 2;
    pointsX[2] = centerX + width / 2;
    pointsY[2] = centerY + height / 2;
    pointsX[3] = centerX - width / 2;
    pointsY[3] = centerY + height / 2;
    for(int i = 0; i < points.size(); i++){
        points[i] = QPointF(pointsX[i], pointsY[i]);
    }
}


void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    calculatePoints();

    center = QPointF(centerX + moveX, centerY + moveY);
    move = QPointF(moveX, moveY);
    disconnectedMove = QPointF(disconnectedMoveX, disconnectedMoveY);
    painter->setBrush(Qt::red);

    QPolygonF rectangle;

    if(!wasCenterDisconnected){
        for(int i = 0; i < 4; i ++){
            rectangle << QPointF(pointsX[i], pointsY[i]) * scale + move;
        }
    }
    else{
        for(int i = 0; i < 4; i ++){
            rectangle << QPointF(pointsX[i], pointsY[i]) * scale + disconnectedMove;
        }
    }

    painter->translate(move);
    painter->rotate(angle);
    painter->translate(-move);

    painter->setBrush(Qt::red);
    painter->drawPolygon(rectangle);
    painter->setBrush(Qt::white);
    painter->drawEllipse(center, 2, 2);
}


void Rectangle::setWidthRectangle(double value){
    width = value;
};
void Rectangle::setHeightRectangle(double value){
    height = value;
};
