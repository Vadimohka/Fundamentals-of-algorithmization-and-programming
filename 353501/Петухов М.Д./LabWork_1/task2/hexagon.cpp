#include "hexagon.h"

Hexagon::Hexagon() {
    centerX = 0;
    centerY = 0;
    angleHex = 360.0 / num_vertices;
    for (int i = 0; i < num_vertices; i++) {
        theta = angleHex * i * M_PI / 180.0;

        pointsX.append(centerX + radius * cos(theta));
        pointsY.append(centerY + radius * sin(theta));
        points.append(QPointF(pointsX[i], pointsY[i]));
    }
}

void Hexagon::calculatePoints(){
    pointsX.resize(num_vertices);
    pointsY.resize(num_vertices);
    points.resize(num_vertices);
    angleHex = 360.0 / num_vertices;
    for(int i = 0; i < num_vertices; i++){
        theta = angleHex * i * M_PI / 180.0;

        pointsX[i] = centerX + radius * cos(theta);
        pointsY[i] = centerY + radius * sin(theta);
        points[i] = QPointF(pointsX[i], pointsY[i]);
    }
}

void Hexagon::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);

    calculatePoints();
    center = {centerX + moveX, centerY + moveY};
    move = QPointF(moveX, moveY);
    disconnectedMove = QPointF(disconnectedMoveX, disconnectedMoveY);

    QPolygonF hexagon;
    if(!wasCenterDisconnected){
        for(int i = 0; i < num_vertices; i++){
            hexagon << QPointF(pointsX[i], pointsY[i]) * scale + move;
        }
    }
    else{
        for(int i = 0; i < num_vertices; i++){
            hexagon << QPointF(pointsX[i], pointsY[i]) * scale + disconnectedMove;
        }
    }


    painter->translate(center);
    painter->rotate(angle);
    painter->translate(-center);

    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    painter->drawPolygon(hexagon);

    painter->setBrush(Qt::white);
    painter->drawEllipse(center, 2, 2);
}

void Hexagon::setVertices(int vertices){
    num_vertices = vertices;
}
