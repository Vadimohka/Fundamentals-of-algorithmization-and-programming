#ifndef PLAYER_H
#define PLAYER_H

#include <QMediaPlayer>
#include <QtWidgets>
#include "bullet.h"
#include "gameobj.h"
#include "healthbar.h"
#include "item.h"
#include "shield.h"

class Player : public GameObj
{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *e) override;
    void keyReleaseEvent(QKeyEvent *e) override;

public:
    void PickupItem(Item *itm);

private:
    void Start() override;
    void Update(float dt) override;
    void ApplyDamage(int damage, GameObj *causer) override;
    void OnDestroy() override;

public:
    float diffFactor;

private:
    QPixmap player;
    Bullet *bullet;
    Bullet *secondBullet;
    HealthBar *healthBar;
    Shield *m_shield;

    int direction;
    QMediaPlayer *bullet_sound;
    QMediaPlayer *pickup_sound;
    bool canShoot;
    float m_shootDelay;
    const float m_maxDelay = 0.15f;
    bool m_doubleShot;
    float m_doubleShootTime;
    float hp;
    float maxHp;
    float speed;
};

#endif // PLAYER_H
