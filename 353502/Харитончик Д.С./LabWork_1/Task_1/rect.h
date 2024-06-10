#pragma once

#include <QPoint>

class Rect {
protected:
    static void elevate(QPointF *point, qreal y);
    static void lower(QPointF *point, qreal y);
    static void navigateLeft(QPointF *point, qreal x);
    static void navigateRight(QPointF *point, qreal x);
};
