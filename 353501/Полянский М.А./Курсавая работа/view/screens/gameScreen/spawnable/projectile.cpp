#include "view/screens/gameScreen/spawnable/projectile.h"

#include <QPainter>

namespace view {

Projectile::Projectile(QGraphicsItem *parent, const QPointF &startingPos, const QPointF &endingPos)
    : QGraphicsItem(parent), currentStep(1), speed(5) {
    QPointF realStartingPos(startingPos.x() - 5, startingPos.y() - 5);

    setPos(realStartingPos);

    deltaX = 1.0 / speed * (endingPos.x() - realStartingPos.x());
    deltaY = 1.0 / speed * (endingPos.y() - realStartingPos.y());
}

bool Projectile::move() {
    // Calculate next point
    QPointF currentPos = pos();
    QPointF nextPos(currentPos.x() + deltaX, currentPos.y() + deltaY);

    if (currentStep == speed + 1) {
        // Return true if arrived
        return true;
    }

    currentStep++;
    setPos(nextPos);

    return false;
}

}  // namespace view
