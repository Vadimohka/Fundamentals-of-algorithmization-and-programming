#ifndef VIEW_EXPLOSION_H_
#define VIEW_EXPLOSION_H_

#include <QGraphicsItem>
#include <vector>

#include "app/shortcuts.h"

using std::vector;

namespace view {

enum class ExplosionType {
    EnemyExplosion,
    GranadeExplosion
};

class Explosion : public QGraphicsItem {
   private:
    ExplosionType _type;
    U_INT spriteAnimationSpeed;
    U_INT currentSpriteFrame;
    vector<QPixmap> sprites;

   public:
    Explosion(ExplosionType _type);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    bool tick();
};

}  // namespace view

#endif