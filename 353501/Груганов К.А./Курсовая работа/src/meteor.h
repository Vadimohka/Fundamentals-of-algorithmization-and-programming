#ifndef METEOR_H
#define METEOR_H

#include "enemy.h"

class Meteor : public Enemy
{
public:
    Meteor();

private:
    void Update(float dt) override;

private:
    float m_totalTime;
    float m_rotSpeed;
};

#endif // METEOR_H
