#ifndef VIEW_GRANADE_H_
#define VIEW_GRANADE_H_

#include "view/screens/gameScreen/spawnable/projectile.h"

namespace view {

class Granade : public Projectile {
   public:
    Granade(QGraphicsItem *parent, const QPointF &startingPos, const QPointF &endingPos);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

}  // namespace view

#endif