#include "item.h"
#include "player.h"

Item::Item()
{
    pickup_sound = new QMediaPlayer();
    pickup_sound->setVolume(70);
}

void Item::Setup(QPixmap pix, ItemKind kind, float amount)
{
    m_kind = kind;
    m_amount = amount;
    setPixmap(pix);
}

void Item::Update(float dt)
{
    setPos(pos() + QPointF(0, 200) * dt);
}

void Item::Colliding(GameObj *obj)
{
    Player *pl = dynamic_cast<Player *>(obj);

    if(pl)
    {
        if (pickup_sound->state() == QMediaPlayer::PlayingState) {
            pickup_sound->setPosition(0);
        }
        pickup_sound->setMedia(QUrl("qrc:/music/Voicy_8-bit Powerup.mp3"));
        pickup_sound->play();
        pl->PickupItem(this);

        Destroy();
    }
}
