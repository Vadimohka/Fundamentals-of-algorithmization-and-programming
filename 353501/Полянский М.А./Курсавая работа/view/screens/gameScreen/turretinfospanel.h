#ifndef VIEW_TURRETINFOSPANEL_H_
#define VIEW_TURRETINFOSPANEL_H_

#include <QGraphicsItem>

#include "model/turrets/turrettype.h"

using model::TurretType;
using model::turretTypes;

namespace view {

class TurretInfosPanel : public QGraphicsItem {
   private:
    bool _show;
    TurretType _turretType;

    void paintTitle(QPainter *painter, const QString &image, const QString &title);
    void paintTurretInfo(QPainter *painter, const QString &stats);

   public:
    TurretInfosPanel();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void setTurretType(TurretType turretType);
    void hideInfos();
};

}  // namespace view

#endif