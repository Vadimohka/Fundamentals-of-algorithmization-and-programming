#ifndef DIVINGENEMY_H
#define DIVINGENEMY_H

#include "shootingenemy.h"
#include "player.h"

class DivingEnemy : public ShootingEnemy
{
public:
    DivingEnemy();

private:
    void Update(float dt) override;
    void dive(float dt);

    void Shoot() override;
    void OnDestroy() override;

public:
    bool isShootable;

protected:
    bool isDiving;
    Player *player;

private:
    QPointF m_dest;
    float m_totalTime;
    const float m_shootDelay = 1.5f;
    float m_timeBeforeShoot;
    bool canShoot;
};

#endif // DIVINGENEMY_H
