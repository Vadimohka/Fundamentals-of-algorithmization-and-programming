#include "rhomb.h"

Rhomb::Rhomb()
{
    vershin.resize(4);
}

QRectF Rhomb::boundingRect() const
{
    if (isSetup == 0)
        return {0, 0, 2000, 2000};
    return {vershin[3].x(), vershin[0].y(), diagolSecond, diagolFirst};
}

void Rhomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (mouseNow != mousePress) {
        painter->drawLine(vershin[0], vershin[1]);
        painter->drawLine(vershin[1], vershin[2]);
        painter->drawLine(vershin[2], vershin[3]);
        painter->drawLine(vershin[3], vershin[0]);
    }
}

void Rhomb::updateCentre()
{
    centre = {(vershin[0].x() + vershin[2].x()) / 2, (vershin[0].y() + vershin[2].y()) / 2};
}
void Rhomb::ystanVershin()
{
    diagolFirst = 2 * (mouseNow.y() - mousePress.y());
    diagolSecond = diagolFirst * sqrt(3);
    vershin[0] = {centre.x(), centre.y() - diagolFirst / 2};
    vershin[1] = {centre.x() + diagolSecond / 2, centre.y()};
    vershin[2] = mouseNow;
    vershin[3] = {centre.x() - diagolSecond / 2, centre.y()};
}

void Rhomb::updateR()
{
    radius = diagolSecond / 4;
}

void Rhomb::mousePressEvent(QGraphicsSceneMouseEvent *mouse)
{
    if (isSetup == 0) {
        centre = mousePress = mouseNow = mouse->pos();
        updateR();
        updateP();
        updateS();
    } else if (isSetup == 1) {
        mouseNow = mouse->pos();
        update();
    }
}

void Rhomb::mouseMoveEvent(QGraphicsSceneMouseEvent *mouse)
{
    if (isSetup == 0) {
        mouseNow = mouse->pos();
        ystanVershin();
        updateCentre();
        updateR();
        updateP();
        updateS();
        update();
    } else if (isSetup == 1) {
        centre += mouse->pos() - mouseNow;
        for (int i = 0; i < 4; ++i) {
            vershin[i] += mouse->pos() - mouseNow;
        }
        mouseNow = mouse->pos();
        update();
        emit isSceneUpdate();
    } else if (isSetup == 2) {
        QVector<QPointF> defaultVershin = vershin;
        for (int i = 0; i < 4; ++i) {
            double x = defaultVershin[i].x() - centre.x(), y = defaultVershin[i].y() - centre.y();
            x *= 1.009;
            y *= 1.009;
            vershin[i] = {centre.x() + x, centre.y() + y};
        }
        diagolSecond = vershin[1].x() - vershin[3].x();
        diagolFirst = vershin[2].y() - vershin[0].y();
        this->update();
    } else if (isSetup == 3) {
        QVector<QPointF> defaultVershin = vershin;
        for (int i = 0; i < 4; ++i) {
            double x = defaultVershin[i].x() - centre.x(), y = defaultVershin[i].y() - centre.y();
            x /= 1.009;
            y /= 1.009;
            vershin[i] = {centre.x() + x, centre.y() + y};
        }
        diagolSecond = vershin[1].x() - vershin[3].x();
        diagolFirst = vershin[2].y() - vershin[0].y();
        this->update();
    }

    emit isSceneUpdate();
}

void Rhomb::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse)
{
    Q_UNUSED(mouse);
    isSetup = 1;
    update();
}

double Rhomb::updateS()
{
    square = abs(diagolFirst * diagolSecond / 2);
    return square;
}

double Rhomb::updateP()
{
    perimetr = abs(4 * diagolSecond);
    return perimetr;
}
