#include "TankAI.h"
#include "chrono"
#include "time.h"

#include "GameObjects/Tank.h"

class Tank;

TankAI::TankAI(Tank *pParentTank)
        : m_pParentTank(pParentTank) {

}

void TankAI::update(const double delta) {

    srand(static_cast<unsigned int> (m_pParentTank->getCurrentPosition().x * 10 + delta * 100));
    m_randFire = rand() % 4;
    if ((rand() % 23) == 2) {
        m_orientation = rand() % 4;
        setOrientation();
    }
    fire();
}

void TankAI::fire() {
    if (m_randFire == 1) {
        m_pParentTank->fire();
    }
}

void TankAI::setOrientation() {

    if (m_orientation == 0) {
        m_pParentTank->setOrientation(Tank::EOrientation::Top);
    } else if (m_orientation == 1) {
        m_pParentTank->setOrientation(Tank::EOrientation::Bottom);
    } else if (m_orientation == 2) {
        m_pParentTank->setOrientation(Tank::EOrientation::Left);
    } else {
        m_pParentTank->setOrientation(Tank::EOrientation::Right);
    }

}