#include "view/screens/gameScreen/enemyitem.h"

#include <QPainter>

namespace view {

EnemyItem::EnemyItem(
    QGraphicsItem *parent,
    const SP<model::Enemy> &enemy,
    qreal cellSize)
    : QGraphicsItem(parent),
      enemyData(enemy),
      _cellSize(cellSize),
      spriteAnimationSpeed(3),
      currentSpriteFrame(0) {
    setPosition();
}

void EnemyItem::setPosition() {
    model::PathCell currentCell = enemyData->getCurrentCell();
    float cellPosition = enemyData->getCellPosition();
    bool firstHalf = cellPosition < 50;

    qreal x = currentCell.x * _cellSize;
    qreal y = currentCell.y * _cellSize;

    // Get direction
    if (firstHalf) {
        switch (currentCell.from) {
            case model::Direction::Left:
                x += cellPosition * _cellSize / 100;
                y += _cellSize / 2;

                sprites = {
                    QPixmap(":/assets/images/enemy/side1.png"),
                    QPixmap(":/assets/images/enemy/side2.png"),
                    QPixmap(":/assets/images/enemy/side3.png"),
                    QPixmap(":/assets/images/enemy/side4.png")};
                break;
            case model::Direction::Up:
                x += _cellSize / 2;
                y += cellPosition * _cellSize / 100;

                sprites = {
                    QPixmap(":/assets/images/enemy/front1.png"),
                    QPixmap(":/assets/images/enemy/front2.png"),
                    QPixmap(":/assets/images/enemy/front3.png"),
                    QPixmap(":/assets/images/enemy/front4.png")};
                break;
            case model::Direction::Right:
                x -= cellPosition * _cellSize / 100 - _cellSize;
                y += _cellSize / 2;

                sprites = {
                    QPixmap(":/assets/images/enemy/side1.png").transformed(QTransform().scale(-1, 1)),
                    QPixmap(":/assets/images/enemy/side2.png").transformed(QTransform().scale(-1, 1)),
                    QPixmap(":/assets/images/enemy/side3.png").transformed(QTransform().scale(-1, 1)),
                    QPixmap(":/assets/images/enemy/side4.png").transformed(QTransform().scale(-1, 1))};
                break;
            case model::Direction::Down:
                x += _cellSize / 2;
                y -= cellPosition * _cellSize / 100 - _cellSize;

                sprites = {
                    QPixmap(":/assets/images/enemy/back1.png"),
                    QPixmap(":/assets/images/enemy/back2.png"),
                    QPixmap(":/assets/images/enemy/back3.png"),
                    QPixmap(":/assets/images/enemy/back4.png")};
                break;
        }
    } else {
        switch (currentCell.to) {
            case model::Direction::Left:
                x -= cellPosition * _cellSize / 100 - _cellSize;
                y += _cellSize / 2;

                sprites = {
                    QPixmap(":/assets/images/enemy/side1.png").transformed(QTransform().scale(-1, 1)),
                    QPixmap(":/assets/images/enemy/side2.png").transformed(QTransform().scale(-1, 1)),
                    QPixmap(":/assets/images/enemy/side3.png").transformed(QTransform().scale(-1, 1)),
                    QPixmap(":/assets/images/enemy/side4.png").transformed(QTransform().scale(-1, 1))};
                break;
            case model::Direction::Up:
                x += _cellSize / 2;
                y -= cellPosition * _cellSize / 100 - _cellSize;

                sprites = {
                    QPixmap(":/assets/images/enemy/back1.png"),
                    QPixmap(":/assets/images/enemy/back2.png"),
                    QPixmap(":/assets/images/enemy/back3.png"),
                    QPixmap(":/assets/images/enemy/back4.png")};
                break;
            case model::Direction::Right:
                x += cellPosition * _cellSize / 100;
                y += _cellSize / 2;

                sprites = {
                    QPixmap(":/assets/images/enemy/side1.png"),
                    QPixmap(":/assets/images/enemy/side2.png"),
                    QPixmap(":/assets/images/enemy/side3.png"),
                    QPixmap(":/assets/images/enemy/side4.png")};
                break;
            case model::Direction::Down:
                x += _cellSize / 2;
                y += cellPosition * _cellSize / 100;

                sprites = {
                    QPixmap(":/assets/images/enemy/front1.png"),
                    QPixmap(":/assets/images/enemy/front2.png"),
                    QPixmap(":/assets/images/enemy/front3.png"),
                    QPixmap(":/assets/images/enemy/front4.png")};
                break;
        }
    }

    // 32 = enemy size / 2 - align to center
    x -= 32;
    y -= 32;

    setPos(x, y);
}

QRectF EnemyItem::boundingRect() const {
    return QRectF(0, 0, 64, 64);
}

void EnemyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawPixmap(QRect(0, 0, 64, 64), sprites[currentSpriteFrame]);

    // Health bar
    float currentHealth = enemyData->getHealth();
    if (currentHealth < 0) {
        currentHealth = 0;
    }
    float initialtHealth = enemyData->getInitialHealth();

    float widthAdvance = (32 * currentHealth) / initialtHealth;

    painter->setPen(Qt::NoPen);

    painter->setBrush(QColor::fromRgb(70, 70, 70, 200));
    painter->drawRect(16, 61, 32, 3);

    QColor barColor;

    if (widthAdvance <= 8) {
        barColor = QColor::fromRgb(255, 0, 0, 200);
    } else if (widthAdvance <= 16) {
        barColor = QColor::fromRgb(255, 150, 0, 200);
    } else {
        barColor = QColor::fromRgb(0, 255, 0, 200);
    }

    painter->setBrush(barColor);

    painter->drawRect(16, 61, widthAdvance, 3);
}

void EnemyItem::tick() {
    // Update position
    setPosition();

    if (spriteAnimationSpeed == 0) {
        currentSpriteFrame++;
        if (currentSpriteFrame == 4) {
            currentSpriteFrame = 0;
        }
        spriteAnimationSpeed = 3;
    } else {
        spriteAnimationSpeed--;
    }
}

bool EnemyItem::isDead() const {
    // Check if the enemyData has been deleted from the model
    if (enemyData->getHealth() <= 0) {
        return true;
    }

    return false;
}

bool EnemyItem::hasEnemyData(const SP<model::Enemy> &enemy) const {
    return enemy == enemyData;
}

}  // namespace view
