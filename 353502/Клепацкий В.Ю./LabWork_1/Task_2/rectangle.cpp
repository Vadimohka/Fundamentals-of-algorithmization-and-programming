#include "rectangle.h"

Rectangle::Rectangle()
{
    vershin.resize(4);
}

QRectF Rectangle::boundingRect() const
{
    qDebug() << "BOUNDING";
    if (isSetup == 0)
        return {0, 0, 2000, 2000};
    return {vershin[0].x(), vershin[0].y(), width, height};
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

void Rectangle::updateR()
{
    radius=(sqrt(width*width+height*height))/2;
}

void Rectangle::updateCentre()
{
    centre = {(vershin[0].x() + vershin[2].x()) / 2, (vershin[0].y() + vershin[2].y()) / 2};
}

void Rectangle::ystanVershin()
{
    x = mouseNow.x() - mousePress.x();
    y = mouseNow.y() - mousePress.y();
    height = 2 * x;
    width = 2 * height;
    QPointF A = {mouseNow.x() - width, mouseNow.y() - height};
    QPointF B = {mouseNow.x(), mouseNow.y() - height};
    QPointF C = mouseNow;
    QPointF D = {mouseNow.x() - width, mouseNow.y()};
    vershin[0] = A;
    vershin[1] = B;
    vershin[2] = C;
    vershin[3] = D;
}

void Rectangle::mousePressEvent(QGraphicsSceneMouseEvent *mouse)
{
    if (isSetup == 0) {
        centre = mousePress = mouseNow = mouse->pos();
        ystanVershin();
        updateR();
        updateP();
        updateS();
    } else if (isSetup == 1) {
        mouseNow=mouse->pos();
        update();
    }
}

void Rectangle::mouseMoveEvent(QGraphicsSceneMouseEvent *mouse)
{
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
        mouseNow = mouse->pos();
        update();
    } else if (isSetup == 2) {
        QVector<QPointF> defaultVershin = vershin;
        for (int i = 0; i < 4; ++i) {
            double x = defaultVershin[i].x() - centre.x(), y = defaultVershin[i].y() - centre.y();
            x *= 1.009;
            y *= 1.009;
            vershin[i] = {centre.x() + x, centre.y() + y};
        }
        width = vershin[1].x() - vershin[0].x();
        height = vershin[2].y() - vershin[1].y();
        this->update();
    } else if (isSetup == 3) {
        QVector<QPointF> defaultVershin = vershin;
        for (int i = 0; i < 4; ++i) {
            double x = defaultVershin[i].x() - centre.x(), y = defaultVershin[i].y() - centre.y();
            x /= 1.009;
            y /= 1.009;
            vershin[i] = {centre.x() + x, centre.y() + y};
        }
        width = vershin[1].x() - vershin[0].x();
        height = vershin[2].y() - vershin[1].y();
        this->update();
    }

    emit isSceneUpdate();
}

void Rectangle::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse)
{
    Q_UNUSED(mouse);
    isSetup = 1;
    update();
}

double Rectangle::updateS()
{
    square = abs(height * width);
    return square;
}

double Rectangle::updateP()
{
    perimetr = abs(2 * (height + width));
    return perimetr;
}
