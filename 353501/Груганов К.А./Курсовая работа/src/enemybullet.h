#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "gameobj.h"

class EnemyBullet : public GameObj
{
public:
    EnemyBullet();

public:
    void Launch(QPointF dir, float speed);

private:
    void Update(float dt) override;
    void Colliding(GameObj *obj) override;

private:
    float m_speed;
    float m_damage;
    QPixmap bulletPix;
    QPointF m_direction;
};

#endif // ENEMYBULLET_H
