#include "view/screens/gameScreen/spawnable/granade.h"

#include <QPainter>

namespace view {

Granade::Granade(QGraphicsItem *parent, const QPointF &startingPos, const QPointF &endingPos)
    : Projectile(parent, startingPos, endingPos) {}

QRectF Granade::boundingRect() const {
    return QRectF(0, 0, 20, 20);
}

void Granade::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor::fromRgb(89, 71, 21));
    painter->drawEllipse(0, 0, 20, 20);
}

}  // namespace view
