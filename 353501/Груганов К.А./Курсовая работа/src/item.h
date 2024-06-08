#ifndef ITEM_H
#define ITEM_H

#include <QMediaPlayer>
#include "gameobj.h"
class Item : public GameObj
{

public:
    enum ItemKind {
        HEAL,
        SHIELD,
        DOUBLE_SHOT,
    };

public:

    Item();
    void Setup(QPixmap pix, ItemKind kind, float amount);

public:

    ItemKind GetKind() const { return m_kind; }
    float GetAmount() const { return m_amount; }

private:

    void Update(float dt) override;
    void Colliding(GameObj *obh) override;

private:
    QMediaPlayer *pickup_sound;
    ItemKind m_kind;
    float m_amount;
};

#endif // ITEM_H
