#ifndef VIEW_ENEMYITEM_H_
#define VIEW_ENEMYITEM_H_

#include <QGraphicsItem>
#include <vector>

#include "app/shortcuts.h"
#include "model/enemy.h"

using std::vector;

namespace view {

class EnemyItem : public QGraphicsItem {
   private:
    SP<model::Enemy> enemyData;
    qreal _cellSize;

    U_INT spriteAnimationSpeed;
    U_INT currentSpriteFrame;
    vector<QPixmap> sprites;

    void setPosition();

   public:
    EnemyItem(QGraphicsItem *parent, const SP<model::Enemy> &enemy, qreal cellSize);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void tick();
    bool isDead() const;

    bool hasEnemyData(const SP<model::Enemy> &enemy) const;
};

}  // namespace view

#endif