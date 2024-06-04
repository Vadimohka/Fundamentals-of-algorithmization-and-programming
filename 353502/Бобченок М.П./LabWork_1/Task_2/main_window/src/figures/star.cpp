//
// Created by u on 10.03.24.
//

#include "star.h"

void star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::white);
    QPen pen;
    pen.setWidth(5);
    pen.setColor(Qt::black);
    painter->setPen(pen);

    int convex = 0;
    if (isConvex) {
        convex = 1;
    } else {
        convex = 2;
    }


    float gap = pi / static_cast<float>(corners) * static_cast<float>(1 + convex % 2);

    if (isConvex) {
        float tmp = sqrtf(powf(sinf(angle) * R - x_centre, 2) + powf(cosf(angle) * R - y_centre, 2));
        tmp = tmp * tmp * sinf(pi * 2 / static_cast<float>(corners)) / 2;
        r = tmp / sqrtf(
                powf(sinf(angle) * R - sinf(angle + gap) * R, 2) +
                powf(cosf(angle) * R - cosf(angle + gap) * R, 2));
    }

    p = sqrtf(powf(sinf(angle) * R - sinf(angle + gap) * r, 2) + powf(cosf(angle) * R - cosf(angle + gap) * r, 2));
    p *= static_cast<float>(corners * convex);

    float curAngle = angle + acosf(-1) / 2;
    bool isCorner = true;
    QPolygon polygon;
    for (int i = 0; i < corners * convex; i++) {
        if (isCorner || convex == 1) {
            polygon << QPoint(static_cast<int>(x_centre + sinf(curAngle) * R), static_cast<int>(y_centre + cosf(curAngle) * R));
        } else {
            polygon << QPoint(static_cast<int>(x_centre + sinf(curAngle) * r), static_cast<int>(y_centre + cosf(curAngle) * r));
        }

        isCorner ^= 1;
        curAngle += gap;
    }

    painter->drawPolygon(polygon);

    QPen penDot;
    penDot.setColor(Qt::green);
    penDot.setWidth(5);
    painter->setPen(penDot);
    painter->drawPoint(static_cast<int>(x_centre), static_cast<int>(y_centre));
}

QRectF star::boundingRect() const
{
    return {0, 0, 0, 0};
}

void star::move(float deltaX, float deltaY)
{
    x_centre += deltaX;
    y_centre += deltaY;
    update();
}

void star::rotate(float deltaAngle)
{
    angle += deltaAngle;
    update();
}

void star::changeR(float delta)
{
    R += delta;
    if (R < 0) {
        R = 0;
    }
    r = R / 2;
    update();
}

float star::getR() const
{
    return R;
}

float star::getAngle() const
{
    return angle;
}

star::star(float _x_centre, float _y_centre, float _angle, float _radius, int _numOfCorners, bool _isConvex) :
        corners(_numOfCorners), x_centre(_x_centre), y_centre(_y_centre), R(_radius), angle(_angle), r(R / 2), p(0),
        isConvex(_isConvex)
{
    update();
}



