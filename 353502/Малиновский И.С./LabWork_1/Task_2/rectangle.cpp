#include "rectangle.h"

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (status == 1) {
        qreal height = qAbs(mousePress.y()-mouseNow.y()), width = qAbs(mousePress.x()-mouseNow.x()), xPos = mousePress.x(), yPos = mousePress.y();
        if (mouseNow.x()<mousePress.x()) { xPos-=width; }
        if (mouseNow.y()<mousePress.y()) { yPos-=height; }
        painter->drawLine(QPointF(xPos, yPos), QPointF(xPos, yPos+height));
        painter->drawLine(QPointF(xPos, yPos), QPointF(xPos+width, yPos));
        painter->drawLine(QPointF(xPos, yPos+height), QPointF(xPos+width, yPos+height));
        painter->drawLine(QPointF(xPos+width, yPos), QPointF(xPos+width, yPos+height));
    }
    else if (!vertices.empty()) {
        painter->drawLine(vertices[0], vertices[1]);
        painter->drawLine(vertices[0], vertices[2]);
        painter->drawLine(vertices[1], vertices[3]);
        painter->drawLine(vertices[2], vertices[3]);
    }
}

void Rectangle::mousePressEvent(QGraphicsSceneMouseEvent *mouse)
{
    updateInfo();
    emit printSquare(square);
    emit printPerimetr(perimetr);
    emit printCentre(centre);
    mousePress=mouse->pos();
    mouseNow=mouse->pos();
    if (status == 2) { defaultDist = dist(mouse->pos(), centre); }
    if (status == 4) { vertices.clear(); }
    if (status == 5) {
        defaultVector = {mouse->pos().x() - centre.x(), mouse->pos().y() - centre.y()};
    }
    emit isSceneUpdate();
}

void Rectangle::mouseMoveEvent(QGraphicsSceneMouseEvent *mouse)
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
    }
    if (status == 2) {
        resizeFigure(mouse);
        emit isSceneUpdate();
    }
    if (status == 5) {
        rotateFigure(mouse);
    }
    emit isSceneUpdate();
}

void Rectangle::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse)
{
    updateInfo();
    Q_UNUSED(mouse);
    qreal height = qAbs(mousePress.y()-mouseNow.y()), width = qAbs(mousePress.x()-mouseNow.x()), xPos = mousePress.x(), yPos = mousePress.y();
    if (mouseNow.x()<mousePress.x()) { xPos-=width; }
    if (mouseNow.y()<mousePress.y()) { yPos-=height; }
    vertices.push_back({xPos, yPos});
    vertices.push_back({xPos, yPos+height});
    vertices.push_back({xPos+width, yPos});
    vertices.push_back({xPos+width, yPos+height});
    updateInfo();
    if (status == 1) status = 0;
}

void Rectangle::updateSquare() {
    if (vertices.size() < 4) return;
    square=(vertices[1].y()-vertices[0].y())*(vertices[2].x()-vertices[0].x());
}

