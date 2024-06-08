#include "shootingenemy.h"
#include "enemybullet.h"
#include "gamescene.h"
#include <QRandomGenerator>

ShootingEnemy::ShootingEnemy()
{
    m_pixmap = QPixmap(":/SpaceShips/A-08.png")
                   .scaled(QSize(70, 70), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    setPixmap(m_pixmap);
    m_timeBeforeShoot = QRandomGenerator::global()->bounded(m_shootDelay);
    canShoot = false;
    maxHp = 80;
    hp = maxHp;
    speed = 90;
    hitDamage = 50;
    m_totalTime = 0;
    bullet_sound = new QMediaPlayer();
    bullet_sound->setMedia(QUrl("qrc:/music/shoot.mp3"));
    bullet_sound->setVolume(40);
    finishedPath = false;
}

void ShootingEnemy::Update(float dt)
{
    if(finishedPath)
    {
        m_totalTime += dt * 5;
        QPointF newPos = QPointF(-qCos(m_totalTime), qSin(m_totalTime));
        setPos(pos() + newPos * 3);
        canShoot = true;
    }
    else
    {
        moveByPath(dt);
    }

    if(canShoot)
    {
        if(m_timeBeforeShoot <= 0)
        {
            Shoot();
        }
        m_timeBeforeShoot -= dt;
    }

    healthBar->Update(hp / maxHp);
    healthBar->setPos(x() + pixmap().width() / 2 - healthBar->rect().width() / 2,
                      y() - healthBar->rect().height());
}

void ShootingEnemy::PlayShootSound()
{
    if(bullet_sound->state() == QMediaPlayer::PlayingState)
    {
        bullet_sound->setPosition(0);
    }
    bullet_sound->play();
}


void ShootingEnemy::Shoot()
{
    PlayShootSound();
    m_timeBeforeShoot = m_shootDelay;
    EnemyBullet *bullet = m_Scene->SpawnObject<EnemyBullet>();
    bullet->setPos(pos());
    bullet->Launch(QPointF(0, 1), 500);
}
