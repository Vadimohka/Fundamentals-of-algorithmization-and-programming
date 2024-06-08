#include "healthbar.h"

HealthBar::HealthBar()
{
    hp  = 1.0f;

    setRect(0, 0, hp, 5);
    setBrush(Qt::red);
}

void HealthBar::Update(float fracHp)
{
    hp = fracHp;
    setRect(0, 0, 80 * fracHp, 5);
}
