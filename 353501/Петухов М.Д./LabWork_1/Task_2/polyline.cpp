#include "polyline.h"


polyline::polyline() {
}

void polyline::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);

    center = QPointF(centerX + moveX, centerY + moveY);
    move = QPointF(moveX, moveY);
    disconnectedMove = QPointF(disconnectedMoveX, disconnectedMoveY);

    painter->translate(center);
    painter->rotate(angle);
    painter->translate(-center);

    painter->translate(move);
    painter->rotate(angle);
    painter->translate(-move);


    painter->setBrush(Qt::white);
    if(!wasCenterDisconnected){
        for(auto &point : points){
            painter->drawEllipse(point * scale + move, 10 * scale, 10 * scale);
        }
    }
    else{
        for(auto &point : points){
            painter->drawEllipse(point * scale + disconnectedMove, 10 * scale, 10 * scale);
        }
    }

    painter->setBrush(Qt::yellow);
    painter->drawEllipse(center, 2, 2);
}

void polyline::addPoint(const QPointF& point)
{
    points.push_back(point);
}

void polyline::clear(){
    moveX = 0;
    moveY = 0;
    angle = 0;
    move = QPointF(moveX, moveY);
    centerX = 0;
    centerY = 0;
    center = QPoint(centerX, centerY);
    scale = 1;
}
