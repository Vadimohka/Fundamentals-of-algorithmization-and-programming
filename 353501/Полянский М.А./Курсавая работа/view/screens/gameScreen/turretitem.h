#ifndef VIEW_TURRETITEM_H_
#define VIEW_TURRETITEM_H_

#include <QGraphicsItem>
#include <vector>

#include "app/shortcuts.h"
#include "model/enemy.h"
#include "model/position.h"
#include "model/turrets/turret.h"
#include "model/turrets/turrettype.h"
#include "view/screens/gameScreen/enemyitem.h"

using std::vector;
namespace view {

class TurretItem : public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

   private:
    SP<model::Turret> turretData;
    model::TurretType type;
    qreal _cellSize;
    U_INT specialEffectCooldown;

    void setPosition();

   public:
    TurretItem(
        QGraphicsItem *parent,
        const SP<model::Turret> &turret,
        model::TurretType turretType,
        qreal cellSize);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    model::Position getGridPosition() const;
    void attack(const vector<EnemyItem *> &enemies);

    bool hasTurretData(const SP<model::Turret> &turret) const;

   signals:
    void spawnBullet(const QPointF &startingPos, const QPointF &endingPos);
    void spawnGranade(const QPointF &startingPos, const QPointF &endingPos);
    void spawnSpecialEffect(const QPointF &startingPos, qreal distance);
};

}  // namespace view

#endif
