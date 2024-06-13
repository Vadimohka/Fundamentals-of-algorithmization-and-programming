#include "starfive.h"

StarFive::StarFive()
{
    angle = (3.1415 * 2) / 5;
    QPointF temp1, temp2;
    for (int i = 0; i < 10; ++i) {
        temp1 = QPointF(radius1 * cos(angle * i), radius1 * sin(angle * i));
        temp2 = QPointF(radius2 * cos(angle * i + angle / 2), radius2 * sin(angle * i + angle / 2));
        vershin.push_back(temp1);
        vershin.push_back(temp2);
    }
    setPos(200, 200);
}

QRectF StarFive::boundingRect() const
{
    qreal maxRadius = (radius1 >= radius2 ? radius1 : radius2);
    return QRectF(vershin[6].x(), vershin[6].y(), 2 * maxRadius, 2 * maxRadius);
}

void StarFive::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    for (int i = 0; i < 10; ++i) {
        int next = i + 1;
        if (i == 9)
            next = 0;
        painter->drawLine(vershin[i], vershin[next]);
    }
}

void StarFive::updateCentre()
{
    double x = 0, y = 0;
    for (int i = 0; i < 10; ++i) {
        x += vershin[i].x();
        y += vershin[i].y();
    }
    centre = {x / 10, y / 10};
}
void StarFive::ystanVershin() {}

void StarFive::updateR()
{
    //radius = 50;
}

void StarFive::mousePressEvent(QGraphicsSceneMouseEvent *mouse)
{
    if (isSetup == 1) {
        mouseNow = mouse->pos();
        update();
    }
}

void StarFive::mouseMoveEvent(QGraphicsSceneMouseEvent *mouse)
{
    if (isSetup == 1) {
        centre += mouse->pos() - mouseNow;
        for (int i = 0; i < vershin.size(); ++i) {
            vershin[i] += mouse->pos() - mouseNow;
        }
        mouseNow = mouse->pos();
        update();
    } else if (isSetup == 2) {
        QVector<QPointF> defaultVershin = vershin;
        for (int i = 0; i < 10; ++i) {
            double x = defaultVershin[i].x() - centre.x(), y = defaultVershin[i].y() - centre.y();
            x *= 1.009;
            y *= 1.009;
            vershin[i] = {centre.x() + x, centre.y() + y};
        }
        radius1 *= 1.009;
        radius2 *= 1.009;
        this->update();
    } else if (isSetup == 3) {
        QVector<QPointF> defaultVershin = vershin;
        for (int i = 0; i < 10; ++i) {
            double x = defaultVershin[i].x() - centre.x(), y = defaultVershin[i].y() - centre.y();
            x /= 1.009;
            y /= 1.009;
            vershin[i] = {centre.x() + x, centre.y() + y};
        }
        radius1 /= 1.009;
        radius2 /= 1.009;
        this->update();
    }

    emit isSceneUpdate();
}

void StarFive::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouse)
{
    Q_UNUSED(mouse);
    isSetup = 1;
    update();
}

double StarFive::updateS()
{
    qreal temp = 2 * radius1 * sin(angle / 2);
    return (temp * radius2 * 5) / 2;
}

double StarFive::updateP()
{
    perimetr = 2 * 5
               * (sqrt(radius1 * radius1 + radius2 * radius2
                       - 2 * radius1 * radius2 * cos(angle / 2)));
    return perimetr;
}
