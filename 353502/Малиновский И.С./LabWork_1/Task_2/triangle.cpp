#include "triangle.h"

void Triangle::updateSquare()
{
    if (vertices.size() < 3) return;
    double p=perimetr/2;
    square=qSqrt(p*(p-dist(vertices[0], vertices[1]))*(p-dist(vertices[0], vertices[2]))*p-dist(vertices[1], vertices[2]));
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (vertices.empty()) return;
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (clickNumber==2) {
        painter->drawLine(vertices[0], vertices[1]);
    }
    else if (clickNumber==3) {
        painter->drawLine(vertices[0], vertices[1]);
        painter->drawLine(vertices[0], vertices[2]);
        painter->drawLine(vertices[1], vertices[2]);
    }
}

void Triangle::mousePressEvent(QGraphicsSceneMouseEvent *mouse)
{
    updateInfo();
    emit printSquare(square);
    emit printPerimetr(perimetr);
    emit printCentre(centre);
    if (status == 1) {
        qDebug() << "OK 1";
        QPointF dop=mouse->pos();
        qDebug() << dop;
        vertices.push_back(dop);
        clickNumber++;
        if (clickNumber==3) { status = 0; }
        update();
    }
    if (status == 2) { defaultDist = dist(mouse->pos(), centre); }
    if (status == 4) {  vertices.clear(); }
    if (status == 5) {
        defaultVector={mouse->pos().x() - centre.x() , mouse->pos().y() - centre.y() };
    }
    mousePress=mouse->pos();
    emit isSceneUpdate();
}

void Triangle::mouseMoveEvent(QGraphicsSceneMouseEvent *mouse)
{
    updateInfo();
    emit printSquare(square);
    emit printPerimetr(perimetr);
    emit printCentre(centre);
    mouseNow=mouse->pos();
    if (status == 3) {
        qDebug() << mouseNow-mousePress;
        for (int i=0; i<3; i++) { vertices[i]+=mouseNow-mousePress; }
        centre+=mouseNow-mousePress;
        emit isSceneUpdate();
    }
    if (status == 2) {
        resizeFigure(mouse);
        emit isSceneUpdate();
    }
    if (status == 5) {
        rotateFigure(mouse);
    }
    mousePress=mouseNow;
}

void Triangle::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse)
{
    updateInfo();
    Q_UNUSED(mouse);
    if (clickNumber == 3 && status == 1) status = 0;
}
