#ifndef SHOOTINGENEMY_H
#define SHOOTINGENEMY_H

#include <QMediaPlayer>
#include "enemy.h"

class ShootingEnemy : public Enemy
{
public:
    ShootingEnemy();

protected:
    virtual void Shoot();
    void PlayShootSound();

private:
    void Update(float dt) override;

protected:
    QMediaPlayer *bullet_sound;

private:
    const float m_shootDelay = 2.3f;
    float m_timeBeforeShoot;
    bool canShoot;
    float m_totalTime;
    QMediaPlayer *m_explosionSound;
};

#endif // SHOOTINGENEMY_H
