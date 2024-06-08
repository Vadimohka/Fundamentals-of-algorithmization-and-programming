#ifndef METEORFLOW_H
#define METEORFLOW_H

#include "formation.h"
class MeteorFlow : public Formation
{
public:
    MeteorFlow();

public:
    void beginForm() override;

private:
    void Update(float dt) override;

public:
    float duration = 10.0f;

private:
    bool m_started;
    float m_totalTime;
    bool m_buffSpawned;
    float m_nextSpawnTime;
};

#endif // METEORFLOW_H
