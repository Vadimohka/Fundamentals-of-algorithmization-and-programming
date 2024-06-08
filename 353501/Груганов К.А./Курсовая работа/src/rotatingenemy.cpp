#include "rotatingenemy.h"
#include "divingenemy.h"
#include "enemybullet.h"
#include "enemyspiral.h"
#include "gamescene.h"
#include "straightlinepath.h"

RotatingEnemy::RotatingEnemy()
{
    m_pixmap = QPixmap(":/SpaceShips/B-06.png")
                   .scaled(QSize(60, 60), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    setPixmap(m_pixmap);
    m_totalTime = 0;
    maxHp = 600;
    hp = maxHp;
    speed = 120;
    canShoot = true;
    m_shield = nullptr;
    m_timeBeforeShoot = 0;
    bullet_sound = new QMediaPlayer();
    bullet_sound->setMedia(QUrl("qrc:/music/shoot.mp3"));
    setTransformOriginPoint(boundingRect().center());
}

void RotatingEnemy::Start()
{
    m_healthBar = new HealthBar();
    m_Scene->addItem(m_healthBar);
    m_healthBar1 = new HealthBar();
    m_Scene->addItem(m_healthBar1);
    m_healthBar2 = new HealthBar();
    m_Scene->addItem(m_healthBar2);

    m_desiredPosition = QPointF(QRandomGenerator::global()->bounded(100, scene()->width() -100),
                                QRandomGenerator::global()->bounded(100, scene()->height() - 200));
}

void RotatingEnemy::OnDestroy()
{
    if(m_healthBar)
    {
        delete m_healthBar;
        m_healthBar = nullptr;
    }
    if(m_healthBar1)
    {
        delete m_healthBar1;
        m_healthBar1 = nullptr;
    }
    if(m_healthBar2)
    {
        delete m_healthBar2;
        m_healthBar2 = nullptr;
    }

}

void RotatingEnemy::ApplyDamage(int damage, GameObj *causer)
{
    (void) causer;
    if(m_shield)
    {
        if(m_shield->IsActivated())
            return;
    }

    hp -= damage;

    if(hp < 300.0f && stage == 0)
    {
        stage++;
        m_shield = m_Scene->SpawnObject<Shield>();
        m_shield->Activate(QPixmap(":/img/Shield-A-11.png")
                           .scaled(QSize(120, 120), Qt::KeepAspectRatio, Qt::SmoothTransformation)
                           , 12.0f);

        EnemySpiral *sp = m_Scene->SpawnObject<EnemySpiral>();
        sp->setPos(scene()->width()/2, -120);
        sp->SetPath(new StraightLinePath(QPointF(0, 0), QPointF(0, 150), 1), false);
    }

    if(hp < 100 && stage == 1)
    {
        stage++;
        DivingEnemy *en = m_Scene->SpawnObject<DivingEnemy>();
        en->setPos(scene()->width()/2, -120);
        en->SetPath(new StraightLinePath(QPointF(0, 0), QPointF(0, 150), 1), false);
    }

    if(hp <= 0)
    {
        Destroy();
        m_Scene->GameOver();
    }
}

void RotatingEnemy::Update(float dt)
{
    m_totalTime += dt;

    if(canShoot)
    {
        if(m_timeBeforeShoot <= 0)
        {
            Shoot();
        }
        m_timeBeforeShoot -= dt;
    }

    QPointF dir = m_desiredPosition - pos();
    qreal magnitude = qSqrt(dir.x() * dir.x() + dir.y() * dir.y());
    dir /= magnitude;
    setPos(pos() + dir * speed * dt);

    qreal targetAngle = qRadiansToDegrees(m_totalTime * 2);
    setRotation(targetAngle);

    if(magnitude <= 0.5f)
    {
        m_desiredPosition = QPointF(QRandomGenerator::global()->bounded(100, scene()->width() -100),
                                    QRandomGenerator::global()->bounded(100, scene()->height() - 200));
    }

    updateHealthBar();
    updateShield();
}

void RotatingEnemy::updateShield()
{
    if(m_shield)
    {
        QPointF npos = pos() - QPointF((qAbs(pixmap().width()/2 - m_shield->pixmap().width()/2)),
                                       (qAbs(pixmap().height()/2 - m_shield->pixmap().height()/2)));
        m_shield->setPos(npos);
    }
}

void RotatingEnemy::updateHealthBar()
{
    m_healthBar->Update(qBound(0.0f, (hp - 300.0f) / 300.0f, 1.0f));
    m_healthBar1->Update(qBound(0.0f, (hp - 100.0f) / 200.0f, 1.0f));
    m_healthBar2->Update(qBound(0.0f, hp / 100.0f, 1.0f));

    m_healthBar2->setPos(x() + pixmap().width() / 2 - m_healthBar2->rect().width() / 2,
                      y() - m_healthBar2->rect().height());

    m_healthBar1->setPos(x() + pixmap().width() / 2 - m_healthBar1->rect().width() / 2,
                        y() - m_healthBar1->rect().height() - 10);

    m_healthBar->setPos(x() + pixmap().width() / 2 - m_healthBar->rect().width() / 2,
                        y() - m_healthBar->rect().height() - 20);
}

void RotatingEnemy::Shoot()
{
    m_timeBeforeShoot = m_shootDelay;
    PlayShootSound();
    for (int i = 0; i < 4; i++) {
        EnemyBullet *bullet = m_Scene->SpawnObject<EnemyBullet>();
        bullet->setPos(pos() + boundingRect().center());
        qreal angle = rotation() + i * 90;
        qreal radianAngle = qDegreesToRadians(angle);
        qreal dirX = qCos(radianAngle);
        qreal dirY = qSin(radianAngle);
        bullet->Launch(QPointF(dirX, dirY), 200);
    }
}
