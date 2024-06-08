#ifndef ENEMY_H
#define ENEMY_H

#include <QtWidgets>
#include "explosion.h"
#include "gameobj.h"
#include "healthbar.h"
#include "path.h"
class Enemy : public GameObj
{
    Q_OBJECT

public:
    Enemy();

    int GetHp() const { return hp; };
    void ApplyDamage(int damage, GameObj *causer) override;
    HealthBar *GetHealthBar() { return healthBar; }
    void SetPath(Path *newPath, bool repeat);
    bool GetFinishedPath() { return finishedPath; }

protected:
    void moveByPath(float dt);

private:
    void Start() override;
    void Update(float dt) override;
    void Colliding(GameObj *obj) override;
    void OnDestroy() override;

public:
    float maxHp;
    float speed;
    float hitDamage;

protected:
    HealthBar *healthBar;
    float hp;
    bool finishedPath;
    bool wasKilled;
    QPixmap m_pixmap;

    Explosion *m_explosion;
    QPropertyAnimation *m_explosionAnimation;
    QGraphicsOpacityEffect *opacityEffect;

private:
    float t;
    Path *m_path;
    float m_totalTime;
    bool m_repeatPath;
};

#endif // ENEMY_H
