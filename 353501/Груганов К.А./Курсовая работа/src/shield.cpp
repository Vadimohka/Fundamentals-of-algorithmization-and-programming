#include "shield.h"

Shield::Shield()
{
    m_time = 0;
    m_opacityEffect = new QGraphicsOpacityEffect(this);
    this->setGraphicsEffect(m_opacityEffect);

    m_opacityAnimation = new QPropertyAnimation(m_opacityEffect, "opacity");
    m_opacityAnimation->setStartValue(0.0);
    m_opacityAnimation->setEndValue(1.0);

    pickup_sound = new QMediaPlayer(this);
    pickup_sound->setMedia(QUrl("qrc:/music/Voicy_8-bit Powerup.mp3"));
    pickup_sound->setVolume(70);
}

void Shield::Activate(QPixmap pix, float time)
{
    setPixmap(pix);
    setVisible(true);
    m_time = time;
    if (pickup_sound->state() == QMediaPlayer::PlayingState) {
        pickup_sound->setPosition(0);
    } else if (pickup_sound->state() == QMediaPlayer::StoppedState) {
        pickup_sound->play();
    }
}

void Shield::Update(float dt)
{
    if(m_time > 0)
    {
        m_time -= dt;
        if (m_time < 3 && m_time > 0) {
            m_opacityAnimation->setDuration(m_time * 1000);
            m_opacityAnimation->start();
        }
    }
    else
    {
        setVisible(false);
    }
}
