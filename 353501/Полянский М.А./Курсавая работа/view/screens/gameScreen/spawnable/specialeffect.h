#ifndef VIEW_SPECIALEFFECT_H_
#define VIEW_SPECIALEFFECT_H_

#include <QGraphicsItem>

#include "app/shortcuts.h"

namespace view {

class SpecialEffect : public QGraphicsItem {
   private:
    qreal _distance;
    qreal deltaSize;

    QSize currentSize;
    U_INT currentStep;
    U_INT speed;

   public:
    SpecialEffect(QGraphicsItem *parent, const QPointF &startingPos, qreal distance);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    bool tick();
};

}  // namespace view

#endif