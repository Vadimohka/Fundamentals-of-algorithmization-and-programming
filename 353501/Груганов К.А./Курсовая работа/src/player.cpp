#include "player.h"
#include "gamescene.h"

Player::Player()
{
    player = QPixmap(":/img/ship.png")
          .scaled(QSize(70, 70), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    setPixmap(player);

    speed = 600.0f;
    maxHp = 100;
    hp = maxHp;
    direction = 0;
    m_shootDelay = m_maxDelay;
    diffFactor = 1;
    m_shield = nullptr;
    m_doubleShot = false;
    m_doubleShootTime = 0;

    bullet_sound = new QMediaPlayer();
    bullet_sound->setMedia(QUrl("qrc:/music/shoot.mp3"));
    bullet_sound->setVolume(50);
}

void Player::PickupItem(Item *itm)
{
    switch (itm->GetKind()) {
    case Item::DOUBLE_SHOT:
        m_doubleShot = true;
        m_doubleShootTime = 20.0f;
        break;
    case Item::HEAL:
        hp += itm->GetAmount();
        break;
    case Item::SHIELD:
        if(!m_shield)
        {
            m_shield = m_Scene->SpawnObject<Shield>();
            m_shield->Activate(QPixmap(":/img/Shield-F-11.png")
                                   .scaled(QSize(90, 90),
                                           Qt::KeepAspectRatio,
                                           Qt::SmoothTransformation),
                               itm->GetAmount());
        }
        else
        {
            m_shield->Activate(QPixmap(":/img/Shield-F-11.png")
                                .scaled(QSize(90, 90), Qt::KeepAspectRatio, Qt::SmoothTransformation)
                                , itm->GetAmount());
        }
        break;
    }
}

void Player::OnDestroy()
{
    if(healthBar)
    {
        delete healthBar;
        healthBar = nullptr;
    }
    if(!m_Scene->isOver)
    {
        m_Scene->GameOver();
    }
}

void Player::ApplyDamage(int damage, GameObj *causer)
{
    (void) causer;

    if(m_shield)
    {
        if(m_shield->IsActivated())
            return;
    }

    hp -= damage * diffFactor;

    if(hp <= 0)
    {
        Destroy();
    }
}

void Player::Start()
{
    healthBar = new HealthBar();
    m_Scene->addItem(healthBar);
}

void Player::Update(float dt)
{
    if(direction != 0)
    {
        float newX = pos().x() + (speed * dt) * direction;
        newX = std::clamp(newX, 0.0f, (float) (scene()->width() - pixmap().width()));
        setPos(newX, pos().y());
    }
    if (m_shootDelay <= 0) {
        canShoot = true;
    } else {
        m_shootDelay -= dt;
    }

    healthBar->Update(hp / maxHp);
    healthBar->setPos(x() + pixmap().width() / 2 - healthBar->rect().width() / 2,
                      y() + pixmap().height() + healthBar->rect().height());

    if(m_shield)
    {
        QPointF npos = pos()
                       - QPointF((std::abs(player.width() / 2 - m_shield->pixmap().width() / 2)),
                                 (std::abs(player.height() / 2 - m_shield->pixmap().height() / 2)));
        m_shield->setPos(npos);
    }
    if (m_doubleShot && m_doubleShootTime > 0) {
        m_doubleShootTime -= dt;
        if (m_doubleShootTime <= 0) {
            m_doubleShot = false;
        }
    }
}

void Player::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Left) {
        direction -= 1;
    } else if (e->key() == Qt::Key_Right) {
        direction += 1;
    }

    if (e->key() == Qt::Key_Space && !e->isAutoRepeat() && canShoot) {
        if (!m_doubleShot) {
            bullet = m_Scene->SpawnObject<Bullet>();
            bullet->setPos(x() + pixmap().width() / 2 - 3, y() - 3);
        } else {
            bullet = m_Scene->SpawnObject<Bullet>();
            secondBullet = m_Scene->SpawnObject<Bullet>();
            bullet->setPos(x() + pixmap().width() / 2 - 10, y() - 3);
            secondBullet->setPos(x() + pixmap().width() / 2 + 10, y() - 3);
        }
        if (bullet_sound->state() == QMediaPlayer::PlayingState) {
            bullet_sound->setPosition(0);
        }

        bullet_sound->play();

        canShoot = false;
        m_shootDelay = m_maxDelay;
    }
}

void Player::keyReleaseEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Left) {
        direction += 1;
    } else if (e->key() == Qt::Key_Right) {
        direction -= 1;
    }
}
