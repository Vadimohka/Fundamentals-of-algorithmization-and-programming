#include "divingenemy.h"
#include "gamescene.h"
#include "beziercurvepath.h"
#include "enemybullet.h"
#include "item.h"

DivingEnemy::DivingEnemy()
{
    m_pixmap = QPixmap(":/SpaceShips/B-17.png")
                   .scaled(QSize(60, 60), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    setPixmap(m_pixmap);
    m_timeBeforeShoot = QRandomGenerator::global()->bounded(m_shootDelay);
    canShoot = false;
    speed = 110;
    maxHp = 80;
    hp = maxHp;
    isDiving = false;
    hitDamage = 35;
    isShootable = false;
    setTransformOriginPoint(boundingRect().center());
    bullet_sound = new QMediaPlayer();
    bullet_sound->setMedia(QUrl("qrc:/music/shoot.mp3"));
}

void DivingEnemy::OnDestroy()
{
    if(healthBar)
    {
        delete healthBar;
        healthBar = nullptr;
    }

    if(!wasKilled) return;

    Item *it = m_Scene->SpawnObject<Item>();
    it->Setup(QPixmap(":/img/energy_blast-05s.png")
                  .scaled(QSize(40, 40), Qt::KeepAspectRatio, Qt::SmoothTransformation)
              ,Item::HEAL, 30);
    it->setPos(pos());
}

void DivingEnemy::Update(float dt)
{
    if(finishedPath)
    {
        if(!isDiving)
        {
            std::vector<Player *> spl = m_Scene->GetObjectsOfClass<Player>();
            if(spl.size() > 0)
            {
                player = spl[0];
                isDiving = true;
                canShoot = true;
                isShootable = true;
            }
        }
        else
        {
            m_totalTime += dt;
            dive(dt);

            if(canShoot && isShootable)
            {
                if(m_timeBeforeShoot <= 0)
                {
                    Shoot();
                    isShootable = false;
                }
                m_timeBeforeShoot -= dt;
            }

            if(pos().y() > scene()->height() - 90)
            {
                if (pos().x() > scene()->width() / 2)
                {
                    SetPath(new BezierCurvePath(BezierCurvePath::curve3()), false);
                }
                else
                {
                    SetPath(new BezierCurvePath(BezierCurvePath::curve3Mir()), false);
                }
                canShoot = false;
            }
        }

    }
    else
    {
        moveByPath(dt);
    }

    qreal targetAngle = qAtan2(GetVelocity().y(), GetVelocity().x());
    targetAngle = qRadiansToDegrees(targetAngle) + 90;
    setRotation(targetAngle);

    healthBar->Update(hp / maxHp);
    healthBar->setPos(x() + pixmap().width() / 2 - healthBar->rect().width() / 2,
                      y() - healthBar->rect().height());
}

void DivingEnemy::dive(float dt)
{
    QPointF dir = player->pos() - pos();
    dir /= std::sqrt(dir.x() * dir.x() + dir.y() * dir.y());
    dir += QPointF(0, 10 * dt);
    setPos(pos() + dir * speed * dt);
}


void DivingEnemy::Shoot()
{
    PlayShootSound();
    m_timeBeforeShoot = m_shootDelay;
    EnemyBullet *bullet = m_Scene->SpawnObject<EnemyBullet>();
    bullet->setPos(pos());
    bullet->Launch(player->pos() - pos(), 400);
}

