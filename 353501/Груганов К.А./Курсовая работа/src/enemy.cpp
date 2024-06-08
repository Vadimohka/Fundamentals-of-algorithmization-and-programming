#include "enemy.h"
#include "beziercurvepath.h"
#include "gamescene.h"
#include "player.h"

Enemy::Enemy()
{
    m_pixmap = QPixmap(":/SpaceShips/A-12.png")
                   .scaled(QSize(60, 60), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    setPixmap(m_pixmap);
    m_explosion = new Explosion();
    m_explosion->setVisible(false);

    opacityEffect = new QGraphicsOpacityEffect(m_explosion);
    m_explosion->setGraphicsEffect(opacityEffect);
    m_explosionAnimation = new QPropertyAnimation(opacityEffect, "opacity");
    m_explosionAnimation->setDuration(1000);
    m_explosionAnimation->setStartValue(1.0);
    m_explosionAnimation->setEndValue(0.0);

    maxHp = 100;
    hp = maxHp;
    t = 0;
    speed = 100;
    finishedPath = true;
    hitDamage = 50;
    m_totalTime = 0;
}

void Enemy::Start()
{
    healthBar = new HealthBar();
    m_Scene->addItem(healthBar);
    m_Scene->addItem(m_explosion);
}

void Enemy::OnDestroy()
{
    if(healthBar)
    {
        delete healthBar;
        healthBar = nullptr;
    }
}

void Enemy::SetPath(Path *newPath, bool repeat)
{
    m_path = newPath;
    finishedPath = false;
    m_repeatPath = repeat;
    t = 0;
}

void Enemy::Colliding(GameObj *obj)
{
    Player *player = dynamic_cast<Player *>(obj);
    if(player)
    {
        obj->ApplyDamage(hitDamage, this);
        wasKilled = false;
        m_explosion->setVisible(true);
        m_explosion->setPos(pos());
        m_explosionAnimation->start();

        Destroy();
    }
}

void Enemy::Update(float dt)
{
    m_totalTime += dt * 2;
    if(finishedPath)
    {
        QPointF dir = QPointF(0, 1);
        dir /= std::sqrt(dir.x() * dir.x() + dir.y() * dir.y());
        //смещение на основе синуса от времени
        float bias = std::sin(m_totalTime);
        dir += QPointF(bias, 0);
        QPointF nextPos = pos() + (dir * dt * speed);
        setPos(nextPos);

        if(pos().y() > scene()->height() - 150)
        {
            if (pos().x() > scene()->width() / 2)
            {
                SetPath(new BezierCurvePath(BezierCurvePath::curve3()), false);
            }
            else
            {
                SetPath(new BezierCurvePath(BezierCurvePath::curve3Mir()), false);
            }
        }
    }
    else
    {
        moveByPath(dt);
    }

    healthBar->Update(hp / maxHp);
    healthBar->setPos(x() + pixmap().width() / 2 - healthBar->rect().width() / 2,
                      y() - healthBar->rect().height());
}

void Enemy::ApplyDamage(int damage, GameObj *causer)
{
    Q_UNUSED(causer);
    hp -= damage;

    if (hp <= 0) {
        wasKilled = true;

        m_explosion->setVisible(true);
        m_explosion->setPos(pos());
        m_explosionAnimation->start();

        Destroy();
    }
}

void Enemy::moveByPath(float dt)
{
    if(finishedPath) return;

    float prev = t;
    t += dt;

    if (t >= m_path->Size() - dt) {
        if(m_repeatPath)
        {
            t = 0;
        }
        else
        {
            finishedPath = true;
            return;
        }
    }

    // Вычисляем следующую позицию на кривой на основе
    // Нормализованного направления к следующей точке
    QPointF dir = m_path->PointAt(t) - m_path->PointAt(prev);

    QPointF nextPos = pos() + dir;

    setPos(nextPos);

    // Сбрасываем 't' до 0, если оно превышает максимальное значение, чтобы зациклить движение
}
