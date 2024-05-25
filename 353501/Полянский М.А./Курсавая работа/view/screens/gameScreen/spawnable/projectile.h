#ifndef VIEW_PROJECTILE_H_
#define VIEW_PROJECTILE_H_

#include <QGraphicsItem>

#include "app/shortcuts.h"

namespace view {

class Projectile : public QGraphicsItem {
   private:
    qreal deltaX;
    qreal deltaY;

    U_INT currentStep;
    // TODO: globalize projectile speed to delay enemies damage animation and update
    U_INT speed;

   public:
    Projectile(QGraphicsItem *parent, const QPointF &startingPos, const QPointF &endingPos);

    bool move();
};

}  // namespace view

#endif