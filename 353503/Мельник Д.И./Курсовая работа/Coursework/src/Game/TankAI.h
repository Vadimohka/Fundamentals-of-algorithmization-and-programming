#pragma once

class Tank;

class TankAI
{
public:
    TankAI(Tank* pParentTank);

    void update(const double delta);

    void fire();

    void setOrientation();

private:
    Tank* m_pParentTank;
    short m_randFire;
    short m_orientation;
};