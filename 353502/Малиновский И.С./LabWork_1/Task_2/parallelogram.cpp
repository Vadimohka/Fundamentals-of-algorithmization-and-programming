#include "parallelogram.h"

void Parallelogram::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (vertices.empty()) return;
    if (clickNumber==2) {
        painter->drawLine(vertices[0], vertices[1]);
    }
    if (clickNumber==3) {
        painter->drawLine(vertices[0], vertices[1]);
        painter->drawLine(vertices[1], vertices[2]);
        painter->drawLine(vertices[2], vertices[3]);
        painter->drawLine(vertices[3], vertices[0]);
    }
}

void Parallelogram::mousePressEvent(QGraphicsSceneMouseEvent *mouse)
{
    updateInfo();
    emit printSquare(square);
    emit printPerimetr(perimetr);
    emit printCentre(centre);
    if (status == 1) {
        clickNumber++;
        if (clickNumber<=2) { vertices.push_back(mouse->pos()); }
        else {
            vertices.push_back(mouse->pos());
            vertices.push_back(vertices[0]+(vertices[2]-vertices[1]));
            status = 0;
        }
    }
    if (status == 2) {
        updateInfo();
        defaultDist = dist(mouse->pos(), centre);
    }
    if (status == 4) {
        vertices.clear();
    }
    if (status == 5) {
        defaultVector = {mouse->pos().x() - centre.x(), mouse->pos().y() - centre.y()};
    }
    mousePress=mouse->pos();
    emit isSceneUpdate();
}

void Parallelogram::mouseMoveEvent(QGraphicsSceneMouseEvent *mouse)
{
    updateInfo();
    emit printSquare(square);
    emit printPerimetr(perimetr);
    emit printCentre(centre);
    mouseNow=mouse->pos();
    if (status == 3) {
        centre+=mouseNow-mousePress;
        for (int i=0; i<4; i++) { vertices[i]+=mouseNow-mousePress; }
        mousePress=mouse->pos();
        emit isSceneUpdate();
    }
    if (status == 2) {
        resizeFigure(mouse);
        emit isSceneUpdate();
    }
    if (status == 5) {
        rotateFigure(mouse);
    }
}

void Parallelogram::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    updateInfo();
    if (clickNumber == 3 && status == 1) status = 0;
}

void Parallelogram::updateSquare()
{
    if (vertices.size() < 4) return;
    square=dist(vertices[0], vertices[2])*dist(vertices[1], vertices[3])/2;
}
