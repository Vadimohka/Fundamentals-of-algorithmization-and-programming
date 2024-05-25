#include "view/screens/gameScreen/turretitem.h"

#include <QPainter>

namespace view {

TurretItem::TurretItem(
    QGraphicsItem *parent,
    const SP<model::Turret> &turret,
    model::TurretType turretType,
    qreal cellSize)
    : QGraphicsItem(parent),
      turretData(turret),
      type(turretType),
      _cellSize(cellSize),
      specialEffectCooldown(20) {
    setPosition();
}

void TurretItem::setPosition() {
    model::Position position = turretData->getPosition();
    setPos(position.x * _cellSize, position.y * _cellSize);
}

QRectF TurretItem::boundingRect() const {
    return QRectF(0, 0, _cellSize, _cellSize);
}

void TurretItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(Qt::NoPen);

    QPixmap pixmap;

    switch (type) {
        case model::TurretType::WeakTurret:
            pixmap = QPixmap(":/assets/images/turrets/weak-turret.png");
            break;
        case model::TurretType::MitraTurret:
            pixmap = QPixmap(":/assets/images/turrets/mitra-turret.png");
            break;
        case model::TurretType::GranadeTurret:
            pixmap = QPixmap(":/assets/images/turrets/granade-turret.png");
            break;
        case model::TurretType::ComboTurret:
            pixmap = QPixmap(":/assets/images/turrets/combo-turret.png");
            break;
        case model::TurretType::SplitTurret:
            pixmap = QPixmap(":/assets/images/turrets/split-turret.png");
            break;
        case model::TurretType::SlowTimeTurret:
            pixmap = QPixmap(":/assets/images/turrets/slowtime-turret.png");
            break;
    }

    painter->drawPixmap(QRect(0, 0, _cellSize, _cellSize), pixmap);
}

model::Position TurretItem::getGridPosition() const {
    return turretData->getPosition();
}

void TurretItem::attack(const vector<EnemyItem *> &enemies) {
    vector<SP<model::Enemy>> targetedEnemies = turretData->getTargetedEnemies();

    if (type == model::TurretType::WeakTurret ||
        type == model::TurretType::MitraTurret ||
        type == model::TurretType::ComboTurret ||
        type == model::TurretType::SplitTurret) {
        
        
        for (auto enemy : targetedEnemies) {
            
            for (auto enemyItem : enemies) {
                if (enemyItem->hasEnemyData(enemy)) {
                  
                    QPointF enemyPos(enemyItem->pos().x() + 50, enemyItem->pos().y() + 50);  // 50: MAGIC NUMBER

                    emit spawnBullet(
                        QPointF(pos().x() + ((_cellSize - 10) / 2), pos().y() + ((_cellSize - 10) / 2)),
                        QPointF(enemyPos.x() + enemyItem->boundingRect().x() / 2, enemyPos.y() + enemyItem->boundingRect().y() / 2));
                }
            }
        }

    } else if (type == model::TurretType::GranadeTurret) {
       
        if (targetedEnemies.size() > 0) {
            for (auto enemyItem : enemies) {
                if (enemyItem->hasEnemyData(targetedEnemies[0])) {
                
                    QPointF enemyPos(enemyItem->pos().x() + 50, enemyItem->pos().y() + 50);  // 50: MAGIC NUMBER

                    emit spawnGranade(
                        QPointF(pos().x() + ((_cellSize - 10) / 2), pos().y() + ((_cellSize - 10) / 2)),
                        QPointF(enemyPos.x() + enemyItem->boundingRect().x() / 2, enemyPos.y() + enemyItem->boundingRect().y() / 2));
                }
            }
        }

    } else if (type == model::TurretType::SlowTimeTurret) {
        // Special effect projectile
        if (specialEffectCooldown == 0) {
            emit spawnSpecialEffect(
                QPointF(pos().x() + (boundingRect().width() / 2), pos().y() + (boundingRect().height() / 2)),
                _cellSize * model::turretTypes.at(type).attackRadius + boundingRect().width() / 2);
            specialEffectCooldown = 20;
        } else {
            specialEffectCooldown--;
        }
    }
}

bool TurretItem::hasTurretData(const SP<model::Turret> &turret) const {
    return turret == turretData;
}

}  // namespace view
