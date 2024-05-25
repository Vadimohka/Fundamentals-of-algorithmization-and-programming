#ifndef VIEW_BULLET_H_
#define VIEW_BULLET_H_

#include "view/screens/gameScreen/spawnable/projectile.h"

namespace view {

class Bullet : public Projectile {
   public:
    Bullet(QGraphicsItem *parent, const QPointF &startingPos, const QPointF &endingPos);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

}  // namespace view

#endif