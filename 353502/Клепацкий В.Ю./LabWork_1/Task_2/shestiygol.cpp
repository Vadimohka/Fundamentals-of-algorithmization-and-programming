#include "shestiygol.h"

Shestiygol::Shestiygol() {}

QRectF Shestiygol::boundingRect() const
{
    if (isSetup == 0)
        return {0, 0, 2000, 2000};
    return {centre.x() - vusota, centre.y() - radius, 2 * vusota, 2 * radius};
}

void Shestiygol::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPolygonF polygon;
    vusota = radius * sqrt(3);
    polygon << QPointF(centre.x(),centre.y()-2*radius) << QPointF(centre.x()+vusota,centre.y()-radius)<<
               QPointF(centre.x()+vusota,centre.y()+radius)<<QPointF(centre.x(),centre.y()+2*radius)<<
               QPointF(centre.x()-vusota,centre.y()+radius)<<QPointF(centre.x()-vusota,centre.y()-radius);

    if (mouseNow!=mousePress) { painter->drawPolygon(polygon); }
}

void Shestiygol::updateCentre()
{
    double x=mousePress.x(), y=mousePress.y();
    centre={(mouseNow.x()+x)/2,(mouseNow.y()+y)/2};
}

void Shestiygol::updateR()
{
    radius=(sqrt(pow(mouseNow.x()-mousePress.x(),2)+pow(mouseNow.y()-mousePress.y(),2)))/2;

}

void Shestiygol::mousePressEvent(QGraphicsSceneMouseEvent *mouse)
{
    if (isSetup == 0) {
        mousePress=mouseNow=mouse->pos();
        updateR();
        updateCentre();
        updateP();
        updateS();
    } else if (isSetup == 1) {
        mouseNow=mouse->pos();
        update();
    }
}

void Shestiygol::mouseMoveEvent(QGraphicsSceneMouseEvent *mouse)
{
    if (isSetup == 0) {
        mouseNow=mouse->pos();
        updateR();
        updateCentre();
        updateP();
        updateS();
        update();
    } else if (isSetup == 1) {
        centre+=mouse->pos()-mouseNow;
        mouseNow=mouse->pos();
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

void Shestiygol::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse)
{
    Q_UNUSED(mouse);
    isSetup = 1;
    update();
}

void Shestiygol::ystanVershin() {}

double Shestiygol::updateS()
{
    square = abs(radius * radius * sqrt(3) * 3 / 2);
    return square;
}

double Shestiygol::updateP()
{
    perimetr = abs(6 * radius);
    return perimetr;
}
