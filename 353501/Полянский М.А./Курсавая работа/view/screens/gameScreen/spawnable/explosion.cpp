#include "view/screens/gameScreen/spawnable/explosion.h"

#include <QPainter>

namespace view {

Explosion::Explosion(ExplosionType type) : _type(type), spriteAnimationSpeed(1), currentSpriteFrame(0) {
    switch (_type) {
        default:
        case ExplosionType::EnemyExplosion:
            for (U_INT i = 1; i <= 14; i++) {
                sprites.push_back(QPixmap(QString(":/assets/images/explosion1/explosion%1.png").arg(i)));
            }
            break;
        case ExplosionType::GranadeExplosion:
            for (U_INT i = 1; i <= 7; i++) {
                sprites.push_back(QPixmap(QString(":/assets/images/explosion2/explosion%1.png").arg(i)));
            }
            break;
    }
}

QRectF Explosion::boundingRect() const {
    switch (_type) {
        default:
        case ExplosionType::EnemyExplosion:
            return QRectF(0, 0, 64, 64);
            break;
        case ExplosionType::GranadeExplosion:
            return QRectF(0, 0, 128, 128);
            break;
    }
}

void Explosion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    switch (_type) {
        default:
        case ExplosionType::EnemyExplosion:
            painter->drawPixmap(QRect(0, 0, 64, 64), sprites[currentSpriteFrame]);
            break;
        case ExplosionType::GranadeExplosion:
            painter->drawPixmap(QRect(0, 0, 64, 64), sprites[currentSpriteFrame]);
            break;
    }
}

bool Explosion::tick() {
    if (spriteAnimationSpeed == 0) {
        currentSpriteFrame++;

        switch (_type) {
            default:
            case ExplosionType::EnemyExplosion:
                if (currentSpriteFrame == 14) {
                    // return true if finished
                    return true;
                }
                break;
            case ExplosionType::GranadeExplosion:
                if (currentSpriteFrame == 7) {
                    // return true if finished
                    return true;
                }
                break;
        }

        spriteAnimationSpeed = 1;
    } else {
        spriteAnimationSpeed--;
    }

    return false;
}

}  // namespace view
