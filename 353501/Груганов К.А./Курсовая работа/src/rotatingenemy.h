#ifndef ROTATINGENEMY_H
#define ROTATINGENEMY_H

#include "shootingenemy.h"
#include "shield.h"

class RotatingEnemy : public ShootingEnemy
{
public:
    RotatingEnemy();

private:
    void Start() override;
    void Update(float dt) override;
    void OnDestroy() override;
    void Shoot() override;
    void ApplyDamage(int damage, GameObj *causer) override;

private:
    void updateHealthBar();
    void updateShield();
    void activateShield();

private:
    float m_totalTime;
    const float m_shootDelay = 0.55f;
    float m_timeBeforeShoot;
    bool canShoot;
    HealthBar *m_healthBar;
    HealthBar *m_healthBar1;
    HealthBar *m_healthBar2;
    QPointF m_desiredPosition;
    Shield *m_shield;
    int stage = 0;
};

#endif // ROTATINGENEMY_H
