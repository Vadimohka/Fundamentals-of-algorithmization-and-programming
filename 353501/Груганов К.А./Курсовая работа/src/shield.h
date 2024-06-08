#ifndef SHIELD_H
#define SHIELD_H

#include <QGraphicsOpacityEffect>
#include <QMediaPlayer>
#include <QPropertyAnimation>
#include "gameobj.h"
class Shield : public GameObj
{
public:
    Shield();

public:
    void Activate(QPixmap pix, float time);
    bool IsActivated() const { return m_time > 0; }

private:
    void Update(float dt) override;

private:
    float m_time;
    QGraphicsOpacityEffect *m_opacityEffect;
    QPropertyAnimation *m_opacityAnimation;
    QMediaPlayer *pickup_sound;
};

#endif // SHIELD_H
