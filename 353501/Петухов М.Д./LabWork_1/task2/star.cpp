#include "star.h"

Star::Star(){
    points.clear();
    centerX = 0;
    centerY = 0;
    starAngle = 2 * M_PI / num_vertices;
    for (int i = 0; i < num_vertices * 2; i+=2) {
        double current_angle = i/2 * starAngle;

        pointsX.append(centerX + inner_radius * cos(current_angle));
        pointsY.append(centerY + inner_radius * sin(current_angle));
        points.append(QPointF(pointsX[i], pointsY[i]));

        pointsX.append(centerX + outer_radius * cos(current_angle + starAngle / 2.0));
        pointsY.append(centerY + outer_radius * sin(current_angle + starAngle / 2.0));
        points.append(QPointF(pointsX[i + 1], pointsY[i + 1]));
    }
}

void Star::calculatePoints(){
    pointsX.resize(num_vertices * 2);
    pointsY.resize(num_vertices * 2);
    points.resize(num_vertices * 2);
    starAngle = 2 * M_PI / num_vertices;
    for (int i = 0; i < num_vertices*2; i+=2) {
        double current_angle = i/2 * starAngle;

        pointsX[i] = (centerX + inner_radius * cos(current_angle));
        pointsY[i] = (centerY + inner_radius * sin(current_angle));
        points[i] = (QPointF(pointsX[i], pointsY[i]));

        pointsX[i+1] = (centerX + outer_radius * cos(current_angle + starAngle / 2.0));
        pointsY[i+1] = (centerY + outer_radius * sin(current_angle + starAngle / 2.0));
        points[i+1]= (QPointF(pointsX[i+1], pointsY[i+1]));
    }
}


void Star::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);

    calculatePoints();

    center = {centerX + moveX, centerY + moveY};
    move = QPointF(moveX, moveY);
    disconnectedMove = QPointF(disconnectedMoveX, disconnectedMoveY);

    QPolygonF star;
    if(!wasCenterDisconnected){
        for (int i = 0; i < num_vertices * 2; i+=2) {
            star << QPointF(pointsX[i], pointsY[i]) * scale + move << QPointF(pointsX[i+1], pointsY[i+1]) * scale + move;
        }
    }
    else{
        //после отсоединения центра и поворота с отсоединенным центром, с помощью ротайта поворачивается ось координат, а точки имеют старые координаты, но из-за того
        // что ось повернута, создается впечатление того что фигура рисуется на новом месте
        for (int i = 0; i < num_vertices * 2; i+=2) {
            star << QPointF(pointsX[i], pointsY[i]) * scale + disconnectedMove << QPointF(pointsX[i+1], pointsY[i+1]) * scale + disconnectedMove;
        }
    }

    painter->translate(center);
    painter->rotate(angle);
    painter->translate(-center);

    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setBrush(Qt::red);
    painter->drawPolygon(star);
    painter->setBrush(Qt::white);
    painter->drawEllipse(center, 2, 2);
}

void Star::setInnerRadius(){
    inner_radius += 10;
};

void Star::setOuterRadius(){
    outer_radius += 10;
};

void Star::setInnerRadiusDown(){
    if(inner_radius > 10){
        inner_radius -= 10;
    }
}

void Star::setOuterRadiusDown(){
    if(outer_radius > 10){
        outer_radius -=10;
    }
}

void Star::setVertices(int vertices){
    num_vertices = vertices;
};
