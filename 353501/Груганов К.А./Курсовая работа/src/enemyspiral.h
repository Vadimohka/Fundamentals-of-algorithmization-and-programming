#ifndef ENEMYSPIRAL_H
#define ENEMYSPIRAL_H

#include "enemy.h"
#include "player.h"

class EnemySpiral : public Enemy
{
public:
    EnemySpiral();

private:
    void Update(float dt) override;
    void Start() override;
    void OnDestroy() override;

public:
    const float beforeAimingDelay = 2.0f;

private:

    enum SpiralState : int
    {
        SPAWNING,
        POSITIONING,
        AIMING,
        ATTACKING
    };

    SpiralState m_state;
    QPointF m_desiredPosition;
    float m_time;
    float m_totalTime;
    bool m_aimed;
    Player *m_player;
};

#endif // ENEMYSPIRAL_H
