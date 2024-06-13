#include "circle.h"

Circle::Circle() {}
QRectF Circle::boundingRect() const
{
    if (isSetup == 0) {
        return {0, 0, 2000, 2000};
    }
    return {centre.x() - radius, centre.y() - radius, 2 * radius, 2 * radius};
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (mouseNow!=mousePress) { painter->drawEllipse(centre, radius, radius); }
}

void Circle::updateCentre()
{
    centre={(mouseNow.x()+mousePress.x())/2,(mouseNow.y()+mousePress.y())/2};
}

void Circle::updateR()
{
    radius=(sqrt(pow(mouseNow.x()-mousePress.x(),2)+pow(mouseNow.y()-mousePress.y(),2)))/2;
}

void Circle::mousePressEvent(QGraphicsSceneMouseEvent *mouse)
{
    if (isSetup == 0) {
        mousePress=mouseNow=mouse->pos();
        updateP();
        updateS();
    } else if (isSetup == 1) {
        mousePress=mouse->pos();
        update();
    }
}

void Circle::mouseMoveEvent(QGraphicsSceneMouseEvent *mouse)
{
    if (isSetup == 0) {
        mouseNow=mouse->pos();
        updateR();
        updateCentre();
        updateP();
        updateS();
        update();
    } else if (isSetup == 1) {
        centre+=mouse->pos()-mousePress;
        mousePress=mouse->pos();
        update();
        emit isSceneUpdate();
    } else if (isSetup == 2) {
        mousePress = mouse->pos();

        radius += sqrt((mouseNow.x() - mousePress.x()) * (mouseNow.x() - mousePress.x())
                       + (mouseNow.y() - mousePress.y()) * (mouseNow.y() - mousePress.y()));
        updateR();
        update();
        this->update();
    } else if (isSetup == 3) {
        mousePress = mouse->pos();
        radius -= sqrt((mousePress.x() - mouseNow.x()) * (mousePress.x() - mouseNow.x())
                       + (mousePress.y() - mouseNow.y()) * (mousePress.y() - mouseNow.y()));
        updateR();
        update();
        this->update();
    }
    emit isSceneUpdate();
}

void Circle::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse)
{
    Q_UNUSED(mouse);
    isSetup = 1;
    update();
}

double Circle::updateS()
{
    square = abs(radius * radius * M_PI);
    return square;
}

void Circle::ystanVershin() {}

double Circle::updateP()
{
    perimetr = abs(2 * radius * M_PI);
    return perimetr;
}
