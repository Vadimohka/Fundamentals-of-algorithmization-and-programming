#pragma once

#include <QPoint>

class mymove {
protected:
    static void moveUP(QPointF *point, qreal y);
    static void moveDown(QPointF *point, qreal y);
    static void moveLeft(QPointF *point, qreal x);
    static void moveRight(QPointF *point, qreal x);
};
