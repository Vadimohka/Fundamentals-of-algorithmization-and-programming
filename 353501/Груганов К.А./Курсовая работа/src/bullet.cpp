#include "bullet.h"
#include "enemy.h"

Bullet::Bullet()
{
    m_bulletPix = QPixmap(":/img/missile.png")
                    .scaled(QSize(35, 35), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    setPixmap(m_bulletPix);
    m_speed = 1000.0f;
    m_damage = 45;
}

void Bullet::Update(float dt)
{
    setPos(x(), y() - m_speed * dt);

    if (pos().y() < 0 - pixmap().height()) {
        Destroy();
    }
}

void Bullet::Colliding(GameObj *obj)
{
    Enemy *enemy = dynamic_cast<Enemy *>(obj);
    if(enemy)
    {
        enemy->ApplyDamage(m_damage, this);
        Destroy();
    }
}
