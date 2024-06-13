#include "square.h"

Square::Square()
{
    vershin.resize(4);
}

QRectF Square::boundingRect() const
{
    qDebug() << "BOUNDING";
    if (isSetup == 0)
        return {0, 0, 2000, 2000};
    return {vershin[0].x(), vershin[0].y(), storona, storona};
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    qDebug() << "PAINT";
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if (mouseNow != mousePress) {
        painter->drawLine(vershin[0], vershin[1]);
        painter->drawLine(vershin[1], vershin[2]);
        painter->drawLine(vershin[2], vershin[3]);
        painter->drawLine(vershin[3], vershin[0]);
    }
}

void Square::updateCentre()
{
    centre = {(vershin[0].x() + vershin[2].x()) / 2, (vershin[0].y() + vershin[2].y()) / 2};
}
void Square::ystanVershin()
{
    qDebug() << "VERSHIN";
    storona = 2 * (mouseNow.x() - mousePress.x());
    vershin[0] = {mouseNow.x() - storona, mouseNow.y() - storona};
    vershin[1] = {mouseNow.x(), mouseNow.y() - storona};
    vershin[2] = mouseNow;
    vershin[3] = {mouseNow.x() - storona, mouseNow.y()};
}

void Square::updateR()
{
    radius=(sqrt(pow(mouseNow.x()-mousePress.x(),2)+pow(mouseNow.y()-mousePress.y(),2)))/2;
}

void Square::mousePressEvent(QGraphicsSceneMouseEvent *mouse)
{
    qDebug() << "PRESS";
    if (isSetup == 0) {
        centre = mousePress = mouseNow = mouse->pos();
        updateR();
        updateP();
        updateS();
    } else {
        mouseNow=mouse->pos();
        update();
    }
}

void Square::mouseMoveEvent(QGraphicsSceneMouseEvent *mouse)
{
    qDebug() << "MOVE";
    if (isSetup == 0) {
        mouseNow=mouse->pos();
        ystanVershin();
        updateCentre();
        updateR();
        updateP();
        updateS();
        update();
    } else if (isSetup == 1) {
        centre+=mouse->pos()-mouseNow;
        for (int i = 0; i < 4; ++i) {
            vershin[i] += mouse->pos() - mouseNow;
        }
        mouseNow=mouse->pos();
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
        storona = vershin[1].x() - vershin[0].x();
        this->update();
    } else if (isSetup == 3) {
        QVector<QPointF> defaultVershin = vershin;
        for (int i = 0; i < 4; ++i) {
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

void Square::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse)
{
    qDebug() << "RELEASE";
    Q_UNUSED(mouse);
    isSetup = 1;
    update();
}

double Square::updateS()
{
    square = abs(2 * radius * radius);
    return square;
}

double Square::updateP()
{
    perimetr = abs(4 * radius * sqrt(2));
    return perimetr;
}
