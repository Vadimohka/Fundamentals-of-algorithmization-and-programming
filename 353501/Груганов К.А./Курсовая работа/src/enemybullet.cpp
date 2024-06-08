#include "enemybullet.h"
#include "player.h"

EnemyBullet::EnemyBullet()
{
    bulletPix = QPixmap(":/img/laser-03.png")
                    .scaled(QSize(35, 35), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    setPixmap(bulletPix);
    m_damage = 25;
    setTransformOriginPoint(boundingRect().center());
}

void EnemyBullet::Launch(QPointF dir, float speed)
{
    dir /= qSqrt(dir.x() * dir.x() + dir.y() * dir.y());
    m_direction = dir;
    m_speed = speed;
}

void EnemyBullet::Colliding(GameObj *obj)
{
    Player *pl = dynamic_cast<Player *>(obj);
    if(pl)
    {
        obj->ApplyDamage(m_damage, this);
        Destroy();
    }
}

void EnemyBullet::Update(float dt)
{
    setPos(pos() + m_direction * m_speed * dt);

    qreal targetAngle = qAtan2(GetVelocity().y(), GetVelocity().x());
    targetAngle = qRadiansToDegrees(targetAngle) + 90;
    setRotation(targetAngle);
}
