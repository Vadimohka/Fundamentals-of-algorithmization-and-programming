#ifndef BULLET_H
#define BULLET_H

#include <QtWidgets>
#include "gameobj.h"

class Bullet : public GameObj
{
    Q_OBJECT
public:
    Bullet();

private:
    void Update(float dt) override;
    void Colliding(GameObj *obj) override;

private:
    QPixmap m_bulletPix;
    float m_damage;
    float m_speed;
};

#endif // BULLET_H
