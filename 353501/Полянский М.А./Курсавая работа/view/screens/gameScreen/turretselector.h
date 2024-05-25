#ifndef VIEW_TURRETSELECTOR_H_
#define VIEW_TURRETSELECTOR_H_

#include <QGraphicsItem>

#include "app/shortcuts.h"
#include "model/turrets/turrettype.h"
#include "view/hud/popupselectoritem.h"

namespace view {

class TurretSelector : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

   private:
    PopupSelectorItem *weakTurretSelector;
    PopupSelectorItem *mitraTurretSelector;
    PopupSelectorItem *granadeTurretSelector;
    PopupSelectorItem *comboTurretSelector;
    PopupSelectorItem *splitTurretSelector;
    PopupSelectorItem *slowTimeTurretSelector;

   protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void focusOutEvent(QFocusEvent *event) override;

   public:
    TurretSelector();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    // Called when the item is shown, to recalculate which turrets can be added
    void updateAvailability(U_INT gameCredits);

   signals:
    void turretHovered(model::TurretType turretType);
    void turretHoverLeave();
    void turretSelected(model::TurretType turretType);
    void losedFocusSignal();
};

}  // namespace view

#endif
