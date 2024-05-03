#include "mymove.h"

void mymove::moveUP(QPointF *point, qreal y) {
    point->ry() -= y;
}

void mymove::moveDown(QPointF *point, qreal y) {
    point->ry() += y;
}

void mymove::moveLeft(QPointF *point, qreal x) {
    point->rx() -= x;
}

void mymove::moveRight(QPointF *point, qreal x) {
    point->rx() += x;
}
