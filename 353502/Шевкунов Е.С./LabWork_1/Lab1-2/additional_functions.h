#ifndef ADDITIONAL_FUNCTIONS_H
#define ADDITIONAL_FUNCTIONS_H

#include <QPoint>
#include <QtMath>

#define PI M_PI

qreal dist(QPoint pointA, QPoint pointB);
qreal dist(QPointF pointA, QPointF pointB);

qreal triangleSquare(QPoint pointA, QPoint pointB, QPoint pointC);
qreal triangleSquare(QPointF pointA, QPointF pointB, QPointF pointC);

qreal polygonSquare(QPoint*, short);
qreal polygonSquare(QPointF*, short);

QPointF center_tr(QPointF pointA, QPointF pointB, QPointF pointC);
QPoint center_tr(QPoint pointA, QPoint pointB, QPoint pointC);

#endif // ADDITIONAL_FUNCTIONS_H
