#include "triangle.h"

Triangle::Triangle()
{
    vershin.resize(3);
}

QRectF Triangle::boundingRect() const
{
    if (isSetup == 0)
        return {0, 0, 2000, 2000};
    return {vershin[2].x(), vershin[2].y() - storona, storona, storona};
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (mouseNow != mousePress) {
        painter->drawLine(vershin[0], vershin[1]);
        painter->drawLine(vershin[1], vershin[2]);
        painter->drawLine(vershin[2], vershin[0]);
    }
}

void Triangle::updateCentre() {}
void Triangle::ystanVershin()
{
    vusota = radius / 2;
    storona = sqrt(3) * radius;
    vershin[0] = {centre.x(), centre.y() - radius};
    vershin[1] = mouseNow;
    vershin[2] = {centre.x() - storona / 2, centre.y() + vusota};
}

void Triangle::updateR()
{
    radius = sqrt((centre.x() - mouseNow.x()) * (centre.x() - mouseNow.x())
                  + (centre.y() - mouseNow.y()) * (centre.y() - mouseNow.y()));
}

void Triangle::mousePressEvent(QGraphicsSceneMouseEvent *mouse)
{
    if (isSetup == 0) {
        centre = mousePress = mouseNow = mouse->pos();
        updateR();
        ystanVershin();
        updateP();
        updateS();
    } else if (isSetup == 1) {
        mouseNow=mouse->pos();
        update();
    }
}

void Triangle::mouseMoveEvent(QGraphicsSceneMouseEvent *mouse)
{
    if (isSetup == 0) {
        mouseNow=mouse->pos();
        updateR();
        ystanVershin();
        updateP();
        updateS();
        update();
    } else if (isSetup == 1) {
        centre += mouse->pos() - mouseNow;
        for (int i = 0; i < 3; ++i) {
            vershin[i] += mouse->pos() - mouseNow;
        }
        mouseNow=mouse->pos();
        update();
        emit isSceneUpdate();
    } else if (isSetup == 2) {
        QVector<QPointF> defaultVershin = vershin;
        for (int i = 0; i < 3; ++i) {
            double x = defaultVershin[i].x() - centre.x(), y = defaultVershin[i].y() - centre.y();
            x *= 1.009;
            y *= 1.009;
            vershin[i] = {centre.x() + x, centre.y() + y};
        }
        storona = vershin[1].x() - vershin[0].x();
        this->update();
    } else if (isSetup == 3) {
        QVector<QPointF> defaultVershin = vershin;
        for (int i = 0; i < 3; ++i) {
            double x = defaultVershin[i].x() - centre.x(), y = defaultVershin[i].y() - centre.y();
            x /= 1.009;
            y /= 1.009;
            vershin[i] = {centre.x() + x, centre.y() + y};
        }
        storona = vershin[1].x() - vershin[0].x();
        this->update();
    }

    emit isSceneUpdate();
}

void Triangle::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse)
{
    Q_UNUSED(mouse);
    isSetup = 1;
    update();
}

double Triangle::updateS()
{
    square = abs(storona * storona * sqrt(3) / 4);
    return square;
}

double Triangle::updateP()
{
    perimetr = abs(3 * storona);
    return perimetr;
}
