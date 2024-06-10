#include "rect.h"

void Rect::elevate(QPointF *point, qreal y) {
    point->ry() -= y;
}

void Rect::lower(QPointF *point, qreal y) {
    point->ry() += y;
}

void Rect::navigateLeft(QPointF *point, qreal x) {
    point->rx() -= x;
}

void Rect::navigateRight(QPointF *point, qreal x) {
    point->rx() += x;
}
