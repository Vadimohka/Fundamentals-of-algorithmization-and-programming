#include "circle.h"

QRectF Circle::boundingRect() const
{
    if (status != 1) {
        qDebug() << centre << " " << radius;
        return {centre.x()-radius, centre.y()-radius, 2*radius, 2*radius};
    }
    return {0, 0, BIG_NUM, BIG_NUM};
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (mouseNow!=mousePress) { painter->drawEllipse(centre, radius, radius); }
}

void Circle::updateCentre()
{
    double x=mousePress.x(), y=mousePress.y();
    if (mouseNow.x()<x) { x-=2*radius; }
    if (mouseNow.y()<y) { y-=2*radius; }
    centre={x+radius, y+radius};
}

void Circle::updateRadius()
{
    radius=qMin(qAbs(mousePress.x()-mouseNow.x()), qAbs(mousePress.y()-mouseNow.y()))/2;
}

void Circle::updateSquare()
{
    square=M_PI * radius * radius;
}

void Circle::updatePerimetr()
{
    perimetr = 2 * M_PI * radius;
}

void Circle::mousePressEvent(QGraphicsSceneMouseEvent *mouse)
{
    updateInfo();
    emit printSquare(square);
    emit printPerimetr(square);
    emit printCentre(centre);
    if (status == 1) {
        mousePress=mouseNow=mouse->pos();
        updateRadius();
        updateCentre();
        updateInfo();
        update();
    }
    if (status == 3) {
        mouseNow=mouse->pos();
    }
    if (status == 2) {
        defaultDist = dist(centre, mouse->pos());
    }
    if (status == 4) {
        radius=0;
    }
    if (status == 5) {
        defaultVector = {mouse->pos().x() - centre.x(), mouse->pos().y() - centre.y()};
    }
    emit isSceneUpdate();
}

void Circle::mouseMoveEvent(QGraphicsSceneMouseEvent *mouse)
{
    updateInfo();
    emit printSquare(square);
    emit printPerimetr(perimetr);
    emit printCentre(centre);
    if (status == 1) {
        mouseNow=mouse->pos();
        updateRadius();
        updateCentre();
        updateInfo();
        update();
    }
    if (status == 3) {
        centre+=mouse->pos()-mouseNow;
        mouseNow=mouse->pos();
        updateInfo();
        update();
        emit isSceneUpdate();
    }
    if (status == 2) {
        radius += dist(centre, mouse->pos()) - defaultDist;
        defaultDist = dist(centre, mouse->pos());

        updateInfo();
    }
    if (status == 5) {
        rotateFigure(mouse);
    }
    emit isSceneUpdate();
}

void Circle::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse)
{
    updateInfo();
    Q_UNUSED(mouse);
    if (status == 1) status = 0;
    update();
}


void Circle::updateInfo()
{
    updatePerimetr();
    updateSquare();
}
