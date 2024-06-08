#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include <QtWidgets>

class GameScene;

class GameObj : public QObject, public QGraphicsPixmapItem
{
public:
    static const int killX = 500;
    static const int killY = 500;

public:
    GameScene *m_Scene;
    bool isPendingKill = false;

public:

    GameObj();

    virtual void Start() { }
    void PreUpdate() noexcept;
    virtual void Update(float dt) { (void) dt; }
    void PostUpdate() noexcept;
    void Destroy() noexcept { isPendingKill = true; }
    virtual void OnDestroy() { }
    virtual void Colliding(GameObj *obj) { (void) obj; }
    virtual void ApplyDamage(int damage, GameObj *causer) { (void) damage; (void) causer; }

    QPointF GetVelocity() { return m_velocity; }

private:
    QPointF m_velocity = QPointF(0, 0);
    QPointF m_prevPos;
};

#endif // GAMEOBJ_H
