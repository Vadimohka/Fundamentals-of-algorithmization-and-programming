#include "par_polygon.h"

par_polygon::par_polygon(){};

par_polygon::par_polygon(QVector<QPointF> p)
{
    SetPoints(p);
}

void par_polygon::SetPoints(QVector<QPointF> p)
{
    start_points = p;
    points.resize(p.size());
    points = p;
}

void par_polygon::find_per()
{
    perimetr = 0;
    if (points.size() > 2) {
        for (int i = 0; i < points.size() - 1; ++i) {
            perimetr += qSqrt(qPow((points[i].x() - points[i + 1].x()), 2) + qPow((points[i].y() - points[i + 1].y()), 2));
        }
        perimetr += qSqrt(qPow((points[0].x() - points[points.size() - 1].x()), 2) + qPow((points[0].y() - points[points.size() - 1].y()), 2));
    }
}

void par_polygon::find_square()
{
    if (points.size() > 2) {
        square = 0;
        for (int i = 0; i < points.size() - 1; ++i) {
            square += (points[i + 1].x() - points[i].x()) * (points[i + 1].y() + points[i].y());
        }
        square += (points[0].x() - points[points.size() - 1].x()) * (points[0].y() + points[points.size() - 1].y());
        square = std::fabs(square) / 2.0;
    }
}

qreal par_polygon::GetPerimeter()
{
    return perimetr;
}

qreal par_polygon::GetSquare()
{
    return square;
}

QPointF par_polygon::GetCenter()
{
    return center;
}

bool par_polygon::Get_animation_is_true()
{
    return animation_is_true;
}

void par_polygon::find_center()
{
    centerX = 0;
    centerY = 0;
    for (int i = 0; i < points.size(); ++i) {
        centerX += points[i].x();
        centerY += points[i].y();
    }
    centerX /= points.size();
    centerY /= points.size();
    center = {centerX, centerY};
}

void par_polygon::turn_animation(qreal rotationAngle, qreal delta)
{
    if (!animation_is_true) {
        animation_is_true = true;
        find_center();
        QTimer *deley = new QTimer;
        QTimer *time_end = new QTimer;
        QObject::connect(deley, &QTimer::timeout, [=]() {
            find_center();
            for (auto& point : points) {
                qreal radius = std::sqrt((point.x() - centerX) * (point.x() - centerX) + (point.y() - centerY) * (point.y() - centerY));
                qreal currentAngle = std::atan2(point.y() - centerY, point.x() - centerX);
                qreal newAngle = currentAngle + rotationAngle/delta;
                qreal rotatedX = centerX + radius * std::cos(newAngle);
                qreal rotatedY = centerY + radius * std::sin(newAngle);
                point = {rotatedX, rotatedY};
            }
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

void par_polygon::resize_animation(qreal new_scale, qreal delta)
{
    if (!animation_is_true) {
        animation_is_true = true;
        find_center();
        QTimer *deley = new QTimer;
        QTimer *time_end = new QTimer;
        QObject::connect(deley, &QTimer::timeout, [=]() {
            for (auto& point : points) {
                point = center + (point - center)/ scale * new_scale;
            }
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

void par_polygon::movement_animation(QPointF p, qreal delta)
{
    if (!animation_is_true) {
        animation_is_true = true;
        QTimer *deley = new QTimer;
        QTimer *time_end = new QTimer;
        QObject::connect(deley, &QTimer::timeout, [=]() {
            for (auto& point : points) {
                point += 25 * p/delta;
            }
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

void par_polygon::draw(QPainter *painter)
{
    QPolygon pol;
    for (auto point: points) {
        QPoint q = {(int) point.x(), (int) point.y()};
        pol << q;
    }
    painter->drawPolygon(pol);
}

void par_polygon::SetNewCenter(QPointF p)
{
    new_center = p;
}

void par_polygon::moveToNewCenter()
{
    find_center();
    QPointF delta = new_center - center;
    for (auto &point: points) {
        point += delta;
    }
    center += delta;
}

void par_polygon::SetStartParams()
{
    SetPoints(start_points);
}


