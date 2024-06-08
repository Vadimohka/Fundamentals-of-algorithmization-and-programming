#include "enemyspiral.h"
#include "gamescene.h"
#include "item.h"

EnemySpiral::EnemySpiral()
{
    m_state = SpiralState::SPAWNING;
    m_time = beforeAimingDelay;
    m_totalTime = 0;
    hitDamage = 100;
    speed = 300;
    m_aimed = true;
    setTransformOriginPoint(boundingRect().center());

    opacityEffect = new QGraphicsOpacityEffect(m_explosion);
    m_explosion->setGraphicsEffect(opacityEffect);
    m_explosionAnimation = new QPropertyAnimation(opacityEffect, "opacity");
    m_explosionAnimation->setDuration(1000);
    m_explosionAnimation->setStartValue(1.0);
    m_explosionAnimation->setEndValue(0.0);
}

void EnemySpiral::OnDestroy()
{
    if(healthBar)
    {
        delete healthBar;
        healthBar = nullptr;
    }

    if (!wasKilled)
        return;

    Item *it = m_Scene->SpawnObject<Item>();
    it->Setup(QPixmap(":/img/energy_blast-04s.png")
                  .scaled(QSize(40, 40), Qt::KeepAspectRatio, Qt::SmoothTransformation)
              ,Item::SHIELD, 12);
    it->setPos(pos());
}

void EnemySpiral::Start()
{
    healthBar = new HealthBar();
    m_Scene->addItem(healthBar);
    m_Scene->addItem(m_explosion);
    auto pl = m_Scene->GetObjectsOfClass<Player>();
    if(pl.size() > 0)
    {
        m_player = pl[0];
    }
    else
    {
        qDebug() << "couldn't find the player";
        Destroy();
    }
}

void EnemySpiral::Update(float dt)
{
    healthBar->Update(hp / maxHp);
    healthBar->setPos(x() + pixmap().width() / 2 - healthBar->rect().width() / 2,
                      y() - healthBar->rect().height());

    if(finishedPath && m_state == SpiralState::SPAWNING)
    {
        m_state = SpiralState::AIMING;
        m_time = beforeAimingDelay;
    }
    else if(!finishedPath)
    {
        moveByPath(dt);
        return;
    }

    if(pos().y() > scene()->height() - 120)
    {
        m_state = SpiralState::POSITIONING;
        m_desiredPosition = QPointF(pos().x(), 120);
        setRotation(0);
    }

    QPointF dir;
    qreal magnitude;
    switch (m_state)
    {
    case SpiralState::SPAWNING:
        return;
    case SpiralState::POSITIONING:
        dir = m_desiredPosition - pos();
        magnitude = qSqrt(dir.x() * dir.x() + dir.y() * dir.y());
        if (magnitude <= 1.0f) {
            if(m_aimed)
            {
                m_state = SpiralState::ATTACKING;
            }
            else
            {
                m_state = SpiralState::AIMING;
            }
            m_totalTime = 1;
            break;
        }
        dir /= magnitude;
        setPos(pos() + dir * speed * dt);
        break;
    case SpiralState::AIMING:
        m_time -= dt;
        if(m_time <= 0)
        {
            m_state = SpiralState::POSITIONING;
            m_time = beforeAimingDelay;
            m_desiredPosition = QPointF(m_player->x(), 120);
            m_aimed = true;
        }
        break;
    case SpiralState::ATTACKING:
        m_totalTime += dt * 6;
        dir = QPointF(std::sin(m_totalTime) * 4, speed * dt);
        setPos(pos() + dir);
        qreal targetAngle = qAtan2(GetVelocity().y(), GetVelocity().x());
        targetAngle = qRadiansToDegrees(targetAngle) + 90;
        setRotation(targetAngle);
        m_aimed = false;
        break;
    }
}
