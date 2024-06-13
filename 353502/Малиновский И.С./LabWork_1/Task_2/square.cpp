#include "square.h"

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    qDebug() << "Square";
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (status == 1) {
        qreal length=qMin(qAbs(mousePress.x()-mouseNow.x()), qAbs(mousePress.y()-mouseNow.y())), xPos = mousePress.x(), yPos = mousePress.y();
        if (mouseNow.x()<mousePress.x()) { xPos-=length; }
        if (mouseNow.y()<mousePress.y()) { yPos-=length; }
        qDebug() << xPos << yPos << length;
        painter->drawLine(QPointF(xPos, yPos), QPointF(xPos, yPos+length));
        painter->drawLine(QPointF(xPos, yPos), QPointF(xPos+length, yPos));
        painter->drawLine(QPointF(xPos, yPos+length), QPointF(xPos+length, yPos+length));
        painter->drawLine(QPointF(xPos+length, yPos), QPointF(xPos+length, yPos+length));
    }
    else if (!vertices.empty()) {
        painter->drawLine(vertices[0], vertices[1]);
        painter->drawLine(vertices[0], vertices[2]);
        painter->drawLine(vertices[1], vertices[3]);
        painter->drawLine(vertices[2], vertices[3]);
    }
}

void Square::mousePressEvent(QGraphicsSceneMouseEvent *mouse)
{
    qDebug() << "OK";
    updateInfo();
    emit printSquare(square);
    emit printPerimetr(perimetr);
    emit printCentre(centre);
    mousePress = mouse->pos();
    mouseNow = mouse->pos();
    if (status == 2) { defaultDist = dist(mouse->pos(), centre); }
    if (status == 4) { vertices.clear(); }
    if (status == 5) {
        defaultVector = {mouse->pos().x() - centre.x(), mouse->pos().y() - centre.y()};
    }
    emit isSceneUpdate();
}

void Square::mouseMoveEvent(QGraphicsSceneMouseEvent *mouse)
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

void Square::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse)
{
    updateInfo();
    Q_UNUSED(mouse);
    qreal length=qMin(qAbs(mousePress.x()-mouseNow.x()), qAbs(mousePress.y()-mouseNow.y())), xPos = mousePress.x(), yPos = mousePress.y();
    if (mouseNow.x()<mousePress.x()) { xPos-=length; }
    if (mouseNow.y()<mousePress.y()) { yPos-=length; }
    vertices.push_back({xPos, yPos});
    vertices.push_back({xPos, yPos+length});
    vertices.push_back({xPos+length, yPos});
    vertices.push_back({xPos+length, yPos+length});
    updateInfo();
    if (status == 1) { status = 0; }
}

void Square::updateSquare() {
    square=(vertices[1].y()-vertices[0].y())*(vertices[2].x()-vertices[0].x());
}

