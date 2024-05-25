#include "view/screens/gameScreen/spawnable/bullet.h"

#include <QPainter>

namespace view {

Bullet::Bullet(QGraphicsItem *parent, const QPointF &startingPos, const QPointF &endingPos)
    : Projectile(parent, startingPos, endingPos) {}

QRectF Bullet::boundingRect() const {
    return QRectF(0, 0, 10, 10);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    painter->drawEllipse(0, 0, 10, 10);
}

}  // namespace view
