#include "circle.h"

Circle::Circle(qreal r, QPointF c)
{
    SetParams(r, c);
}

void Circle::SetParams(qreal r, QPointF c)
{
    start_r = r;
    start_c = c;
    radius = r;
    center = c;
}

void Circle::SetStartParams()
{
    radius = start_r;
    center = start_c;
}

void Circle::find_per()
{
    perimeter = 2 * M_PI * radius;
}

void Circle::find_square()
{
    square = M_PI * qPow(radius, 2);
}

qreal Circle::GetPerimeter()
{
    return perimeter;
}

qreal Circle::GetSquare()
{
    return square;
}

bool Circle::Get_animation_is_true()
{
    return animation_is_true;
}

QPointF Circle::GetCenter()
{
    return center;
}

void Circle::resize_animation(qreal new_scale, qreal delta)
{
    if (!animation_is_true) {
        animation_is_true = true;
        QTimer *deley = new QTimer;
        QTimer *time_end = new QTimer;
        QObject::connect(deley, &QTimer::timeout, [=]() {
            radius *= (new_scale * scale);
        });
        QObject::connect(time_end, &QTimer::timeout, [=]() {
            deley->stop();
            time_end->stop();
            delete deley;
            delete time_end;
            animation_is_true = false;
        });
        deley->start(25);
        time_end->start(delta);
    }
}

void Circle::movement_animation(QPointF p, qreal delta)
{
    if (!animation_is_true) {
        animation_is_true = true;
        QTimer *deley = new QTimer;
        QTimer *time_end = new QTimer;
        QObject::connect(deley, &QTimer::timeout, [=]() {
            center += 25 * p/delta;
        });
        QObject::connect(time_end, &QTimer::timeout, [=]() {
            deley->stop();
            time_end->stop();
            delete deley;
            delete time_end;
            animation_is_true = false;
        });
        deley->start(25);
        time_end->start(delta);
    }
}

void Circle::SetNewCenter(QPointF p)
{
    center = p;
}

void Circle::draw(QPainter *painter)
{
    painter->drawEllipse(center, radius, radius);
}

void Circle::SetNewCoord(qreal r, QPointF c)
{
    center = c;
    radius = r;
}

