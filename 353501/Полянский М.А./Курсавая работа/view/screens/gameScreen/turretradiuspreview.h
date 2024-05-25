#ifndef VIEW_TURRETRADIUSPREVIEW_H_
#define VIEW_TURRETRADIUSPREVIEW_H_

#include <QGraphicsItem>

#include "app/shortcuts.h"

namespace view {

class TurretRadiusPreview : public QGraphicsItem {
   private:
    U_INT _radius;

   public:
    TurretRadiusPreview();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void setRadius(U_INT radius);
};

}  // namespace view

#endif