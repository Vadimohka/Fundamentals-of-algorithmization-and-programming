#include "rhomb.h"

void Rhomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (clickNumber == 2) {
        painter->drawLine(vertices[0], vertices[1]);
    }
    else if (vertices.size() == 4) {
        painter->drawLine(vertices[0], vertices[1]);
        painter->drawLine(vertices[1], vertices[2]);
        painter->drawLine(vertices[0], vertices[3]);
        painter->drawLine(vertices[2], vertices[3]);
    }
}

void Rhomb::mousePressEvent(QGraphicsSceneMouseEvent *mouse)
{
    qDebug() << "OK R";
    updateInfo();
    emit printSquare(square);
    emit printPerimetr(perimetr);
    emit printCentre(centre);
    if (status == 1) {
        clickNumber++;
        if (clickNumber < 3) {
            vertices.push_back(mouse->pos());
        }
        else {
            double x = vertices[1].x() - vertices[0].x(), y = vertices[1].y() - vertices[0].y();
            double angle = calcAngle({x, y}, {mouse->pos().x() - vertices[1].x(), mouse->pos().y() - vertices[1].y()}), x2 = x, y2 = y;
            qDebug() << angle;
            x = x2 * cos(angle) - y2 * sin(angle);
            y = y2 * cos(angle) + x2 * sin(angle);

            vertices.push_back({vertices[1].x() + x, vertices[1].y() + y});
            vertices.push_back({vertices[0].x() + x, vertices[0].y() + y});
            status=0;
        }
    }
    if (status == 2) {
        defaultDist = dist(mouse->pos(), centre);
    }
    if (status == 3) {
        mousePress = mouse->pos();
        mouseNow = mouse->pos();
    }
    if (status == 4) {
        vertices.clear();
        update();
    }
    if (status == 5) {
        defaultVector = {mouse->pos().x() - centre.x(), mouse->pos().y() - centre.y()};
    }
    emit isSceneUpdate();
}

void Rhomb::mouseMoveEvent(QGraphicsSceneMouseEvent *mouse)
{
    updateInfo();
    emit printSquare(square);
    emit printPerimetr(perimetr);
    emit printCentre(centre);
    if (status == 2) {
        resizeFigure(mouse);
    }
    if (status == 3) {
        for (int i=0; i< vertices.size(); i++) {
            vertices[i] += mouse->pos() - mouseNow;
        }
        centre += mouse->pos() - mouseNow;
        mouseNow=mouse->pos();
        updateInfo();
    }
    if (status == 5) {
        rotateFigure(mouse);
    }
    emit isSceneUpdate();
}

void Rhomb::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse)
{
    updateInfo();
    if (status == 1 && clickNumber == 3) status = 0;
}

void Rhomb::updateSquare()
{
    if (vertices.size() < 4) return;
    square = dist(vertices[1], vertices[0]) * dist(vertices[1], vertices[0]) * sin(calcAngle({vertices[1].x() - vertices[0].x(), vertices[1].y() - vertices[0].y()}, {vertices[2].x() - vertices[0].x(), vertices[2].y() - vertices[0].y()}));
}
